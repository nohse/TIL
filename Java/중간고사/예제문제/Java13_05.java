package Num1;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
class TimerRunnable1 extends Thread{
	private JLabel la=new JLabel();
	public TimerRunnable1(JLabel la) {
		this.la=la;
	}
	public void run() {
		int n=0;
		while(true) {
			la.setText(Integer.toString(n));
			n++;
			try {
			sleep(1000);
			}catch(InterruptedException e) {
				return ;
			}

		}
	}
}
class ThreadInterruptEx1 extends JFrame{
	JButton btn=new JButton("kill timer");
	JLabel la=new JLabel();
	TimerRunnable1 th=new TimerRunnable1(la);
	public ThreadInterruptEx1() {
		setTitle("20011619nohseonghyeon");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c= getContentPane();
		c.setLayout(new FlowLayout());

		btn.addActionListener(new MyActionListener());
		c.add(la);
		c.add(btn);
		
		setSize(500,250);
		setVisible(true);
		
		th.start();
		
	}
	class MyActionListener implements ActionListener{

		@Override
		public void actionPerformed(ActionEvent e) {
			th.interrupt();
			JButton btn=(JButton)e.getSource();
			btn.setEnabled(false);
		}
	}
}
public class Java13_04 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new ThreadInterruptEx1();
	}
}
