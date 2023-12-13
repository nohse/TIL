import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

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
				Thread.sleep(1000); // 1초동안 잠을 잔다.
			}
			catch(InterruptedException e) {
				return; // 예외가 발생하면 스레드 종료
			}
		}
	}
	
	void setPauseFlag (Boolean b) {
		pause = b;
	}
}

class ThreadInterruptEx extends JFrame {
	private Thread th;
	JButton btn, btn2;
	JLabel timerLabel;
	TimerRunnable runnable;
	
	public ThreadInterruptEx() {
		setTitle("ThreadInterruptEx 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());

		// 타이머 값을 출력할 레이블 생성
		timerLabel = new JLabel();
		timerLabel.setFont(new Font("Gothic", Font.ITALIC, 80));
		
		// 타이머 스레드로 사용할 Runnable 객체 생성
		// 타이머 값을 출력할 레이블 컴포넌트를 생성자에 전달한다.
		
		c.add(timerLabel);
		
		// 버튼을 생성하고 Action 리스너 등록
		btn = new JButton("stop Timer");
		btn.addActionListener(new MyActionListener1());
		c.add(btn);
		
		btn2 = new JButton("resume Timer");
		btn2.addActionListener(new MyActionListener2());
		c.add(btn2);
		
		setSize(300,170);
		setVisible(true);
		
		runnable = new TimerRunnable(timerLabel);
		th = new Thread(runnable); // 스레드 생성
		th.start(); // 스레드 동작시킴
	}
	
	class MyActionListener1 implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			th.interrupt(); // 타이머 스레드 강제 종료
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
			
			runnable = new TimerRunnable(timerLabel);
			th = new Thread(runnable); // 스레드 생성
			th.start(); // 스레드 동작시킴
			
		}
	}
	
}

public class JC21 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new ThreadInterruptEx();
	}

}
