package Num1;
import java.awt.*;
import javax.swing.*;
class TimerThread extends Thread{
	private JLabel timerLabel;
	public TimerThread(JLabel timerLabel) {
		this.timerLabel=timerLabel;
	}
	
	public void run() {
		int n=0;
		while(true) {
			timerLabel.setText(Integer.toString(n));
			n++;
			try {
				sleep(1000);
			}
			catch(InterruptedException e) {
				return;
			}
		}
	}
}
class ThreaderTimerEx extends JFrame{
	public ThreaderTimerEx() {
		setTitle("20011619 nohseonghyeon");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c=getContentPane();
		c.setLayout(new FlowLayout());
		
		JLabel timerLabel=new JLabel();
		timerLabel.setFont(new Font("Gothic", Font.ITALIC, 80));
		c.add(timerLabel);
		
		TimerThread th= new TimerThread(timerLabel);

		setSize(300,170);
		setVisible(true);

		timerLabel.setFont(new Font("Gothic", Font.ITALIC, 80));
		c.add(timerLabel);

		th.start();

	}
}
public class Java13_01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new ThreaderTimerEx();
		System.out.println("a");
	}

}
