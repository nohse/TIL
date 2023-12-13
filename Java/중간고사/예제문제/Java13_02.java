package Num1;
import java.awt.*;
import javax.swing.*;
class TimerRunnable implements Runnable{
  private JLabel timerLabel;
  public TimerRunnable(JLabel timerLabel) {
	  this.timerLabel=timerLabel;
  }
	@Override
	public void run() {
		int n=0;
		while(true) {
			n++;
			timerLabel.setText(Integer.toString(n));
			try {
				Thread.sleep(1000);
			}catch(InterruptedException e){
				return ;
			}
		}
	}
	
}
class RunnableTimerEx extends JFrame{
	public RunnableTimerEx(){
		setTitle("20011619nohseonghyeon");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c= getContentPane();
		c.setLayout(new FlowLayout());
		
		JLabel timerLabel = new JLabel();
		timerLabel.setFont(new Font("Gothic", Font.ITALIC, 80));
		c.add(timerLabel);
		
		TimerRunnable runnable=new TimerRunnable(timerLabel);
		Thread th= new Thread(runnable);
		
		
		setSize(250,150);
		setVisible(true);
		
		th.start();
	}
	
}
public class Java13_02 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new RunnableTimerEx();
	}
}
