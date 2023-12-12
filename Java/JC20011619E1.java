package Num1;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class MyLabel extends JLabel {
	int barSize = 0; // 바의 크기
	int maxBarSize;
	
	MyLabel(int maxBarSize) { 
		this.maxBarSize = maxBarSize;
	}
	
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		g.setColor(Color.MAGENTA);
		int width = (int)(((double)(this.getWidth()))
				/maxBarSize*barSize);
		if(width==0) return; 
		g.fillRect(0, 0, width, this.getHeight());
	}
	
	synchronized void fill() {
		if(barSize == maxBarSize) {
//			try {
//				wait(); 
//			} catch (InterruptedException e) { return; }
			barSize=0;
		}
		barSize++;
		repaint(); // 바 다시 그리기
	}

synchronized void consume() {
	if(barSize == 0) {
//		try {
//			wait(); 
//		} catch (InterruptedException e)
//			 { return; }
		barSize=0;
	}
	barSize--;
	repaint(); // 바 다시 그리기
}	
}

class ConsumerThread implements Runnable {
MyLabel bar;

ConsumerThread(MyLabel bar) {
	this.bar = bar;
}
public void run() {
	while(true) {
		try {
			Thread.sleep(200);
			bar.consume(); 
		} catch (InterruptedException e)
		 { return; }
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
				bar.fill(); // 0.1珥덈쭏�떎 諛붾�� 1�떒�쐞�뵫 利앷�
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
			/*
			if (pause == true) {
				continue;
			}
			*/
			timerLabel.setText(Integer.toString(n)); // 타이머 값을 레이블에 출력
			n++; // 카운트 증가
			try {
				synchronized(this) {
					while(pause) {
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
	
	public void pause () {
		pause = true;
	}
	public synchronized void resume() {
		pause = false;
		notify();
	}
}

class ThreadInterruptEx extends JFrame {
	private Thread th, fTH, cTH;
	JButton btn, btn2;
	private MyLabel bar1=new MyLabel(10);
	JLabel timerLabel;
	TimerRunnable runnable;
	FillThread fillTH;
	ConsumerThread consumeTH;
	
	public ThreadInterruptEx() {
		setTitle("ThreadInterruptEx 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(null);

		// 타이머 값을 출력할 레이블 생성
		timerLabel = new JLabel();
		timerLabel.setFont(new Font("Gothic", Font.ITALIC, 80));
		
		// 타이머 스레드로 사용할 Runnable 객체 생성
		// 타이머 값을 출력할 레이블 컴포넌트를 생성자에 전달한다.
		
		c.add(timerLabel);
		
		// 버튼을 생성하고 Action 리스너 등록
		btn = new JButton("pause Timer");
		btn.addActionListener(new MyActionListener1());
		c.add(btn);
		
		btn2 = new JButton("resume Timer");
		btn2.addActionListener(new MyActionListener2());
		c.add(btn2);
		bar1.setBackground(Color.ORANGE);
		bar1.setOpaque(true);
		bar1.setLocation(20, 100);
		bar1.setSize(300, 20); // 300x20 �겕湲곗쓽 諛�
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
			runnable.pause();
			fillTH.pause();
			//runnable.setPauseFlag(true);
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
			
		}
	}
	
}

public class JC20011619E1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new ThreadInterruptEx();
	}

}