
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class MyLabel extends JLabel {
	private int barSize = 0; // 현재 그려져야할 바의 크기
	private int maxBarSize; // 바의 최대 크
	
	public MyLabel(int maxBarSize) { 
		this.maxBarSize = maxBarSize;
	}
	
	@Override
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		g.setColor(Color.MAGENTA);
		int width = (int) (((double)(this.getWidth()))/maxBarSize*barSize);
		if(width==0) return; // 크기가 0이기 때문에 바를 그릴 필요 없음
		g.fillRect(0, 0, width, this.getHeight());
	}
	
	synchronized public void fill() {
		if(barSize == maxBarSize) {
			/*
			try {
				wait(); // 바의 크기가 최대이면, ComsumerThread에 의해 바의 크기가 줄어들때까지 대기
			} catch (InterruptedException e) { return; }
			*/
			barSize = 0;
		}
		barSize++;
		repaint(); // 바의 크기가 변했으니 다시 그리기
		//notify(); // 기다리는 ConsumerThread 스레드 깨우기
	}
	synchronized public void consume() {
		if(barSize == 0) {
			/*
			try {
				wait(); // 바의 크기가 0이면 바의 크기가 0보다 커질 때까지 대기
			} catch (InterruptedException e) { return; }
			*/
			barSize = maxBarSize;
		}
		barSize--;
		repaint(); // 바의 크기가 변했으니 다시 그리기
		//notify(); // 기다리는 이벤트 스레드 깨우기
	}
}

class ConsumerThread implements Runnable {
	private MyLabel bar;
	private int sleepTime;
	
	public ConsumerThread(MyLabel bar, int sT) {
		this.bar = bar;
		sleepTime = sT;
	}
	
	@Override
	public void run() {
		while(true) {
			try {
				Thread.sleep(sleepTime);
				bar.consume(); // 0.1초마다 바를 1단위씩 감소
			} catch (InterruptedException e) { return; }
		}
	}
}

class FillThread implements Runnable {
	private MyLabel bar;
	private int sleepTime;
	private static Boolean pause = false;

	public FillThread(MyLabel bar, int sT) {
		this.bar = bar;
		sleepTime = sT;
	}
	
	@Override
	public void run() {
		while(true) {
			try {
				synchronized (this) {
					while (pause) {
						wait();
					}
				}
				
				Thread.sleep(sleepTime);
				bar.fill(); // 0.1초마다 바를 1단위씩 증가
			} catch (InterruptedException e) { return; }
		}
	}
	
	public void pause() {
		pause = true;
	}
	
	public synchronized void resume() {
		pause = false;
		notify();
	}
	
}

class TimerRunnable implements Runnable {
	private JLabel timerLabel; // 타이머 값이 출력된 레이블
	private static Boolean pause = false;
	
	public TimerRunnable(JLabel timerLabel) {
		this.timerLabel = timerLabel;
	}

	// 스레드 코드. run()이 종료하면 스레드 종료
	@Override
	public void run() {
		int n=0; // 타이머 카운트 값
		while(true) { // 무한 루프
			
			timerLabel.setText(Integer.toString(n)); // 타이머 값을 레이블에 출력
			n++; // 카운트 증가
			try {
				synchronized (this) {
					while (pause) {
						wait();
					}
				}
				Thread.sleep(1000); // 1초동안 잠을 잔다.
			}
			catch(InterruptedException e) {
				return; // 예외가 발생하면 스레드 종료
			}
		}
	}
	
	public void pause() {
		pause = true;
	}
	
	public synchronized void resume() {
		pause = false;
		notify();
	}
}

class ThreadInterruptEx extends JFrame {
	private Thread th, fTH, cTH;
	private MyLabel bar1 = new MyLabel(10);
	JButton btn, btn2;
	JLabel timerLabel;
	TimerRunnable runnable;
	FillThread fillTH;
	ConsumerThread consumeTH;

	
	public ThreadInterruptEx() {
		setTitle("ThreadInterruptEx 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		//c.setLayout(new FlowLayout());
		c.setLayout(null);

		// 타이머 값을 출력할 레이블 생성
		timerLabel = new JLabel();
		timerLabel.setFont(new Font("Gothic", Font.ITALIC, 80));
		
		// 타이머 스레드로 사용할 Runnable 객체 생성
		// 타이머 값을 출력할 레이블 컴포넌트를 생성자에 전달한다.
		
		c.add(timerLabel);
		
		// 버튼을 생성하고 Action 리스너 등록
		//btn = new JButton("stop Timer");
		btn = new JButton("pause Timer");
		btn.addActionListener(new MyActionListener1());
		c.add(btn);
		
		btn2 = new JButton("resume Timer");
		btn2.addActionListener(new MyActionListener2());
		c.add(btn2);
		

		bar1.setBackground(Color.ORANGE);
		bar1.setOpaque(true);
		bar1.setLocation(20, 100);
		bar1.setSize(300, 20); // 300x20 크기의 바
		c.add(bar1);

		
		timerLabel.setLocation(10,20);
		timerLabel.setSize(100,50);
		btn.setLocation(120,30);
		btn.setSize(80,40);
		btn2.setLocation(210,30);
		btn2.setSize(80,40);
		
		setSize(400,200);
		setVisible(true);

		runnable = new TimerRunnable(timerLabel);
		th = new Thread(runnable); // 스레드 생성
		th.start(); // 스레드 동작시킴
		
		fillTH = new FillThread(bar1, 100);
		fTH = new Thread(fillTH);
		fTH.start();
	}
	
	class MyActionListener1 implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			//th.interrupt(); // 타이머 스레드 강제 종료
			
			runnable.pause();
			fillTH.pause();
			
			JButton btn = (JButton)e.getSource();
			btn.setEnabled(false); // 버튼 비활성화
		}
	}
	
	class MyActionListener2 implements ActionListener {
		@Override
		public void actionPerformed (ActionEvent e) {
			//runnable.setPauseFlag(false);
			btn.setEnabled(true);
			
			runnable.resume();
			fillTH.resume();
			/*
			runnable = new TimerRunnable(timerLabel);
			th = new Thread(runnable); // 스레드 생성
			th.start(); // 스레드 동작시킴
			*/
			
		}
	}
	
}

public class JC30 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new ThreadInterruptEx();
	}

}
