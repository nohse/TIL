package Num1;
import java.awt.*;
import javax.swing.*;
class FlickeringLabel extends JLabel implements Runnable{
	private int delay;
	public FlickeringLabel(String text, int delay) {
		super(text);
		this.delay=delay;
		setOpaque(true);
		Thread th = new Thread(this);
		th.start();

	}
	@Override
	public void run() {
		int n=0;
		while(true) {
			if(n%2==0) {
					setBackground(Color.YELLOW);
					n++;
			}
			else {
				setBackground(Color.GREEN);
				n++;
			}
			try {
				Thread.sleep(delay);
			}catch(InterruptedException e) {
				return ;
			}
		}
	}
	
}
class FlickeringLabelEx extends JFrame{
	private FlickeringLabel a=new FlickeringLabel("±ôºý", 500);
	private FlickeringLabel a2=new FlickeringLabel("¿©±âµµ ±ôºý", 300);
	private JLabel b=new JLabel("¾È±ôºý");
	
	public FlickeringLabelEx(){
		setTitle("20011619nohseonghyeon");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c=getContentPane();
		c.setLayout(new FlowLayout());
		
		c.add(a);
		c.add(b);
		c.add(a2);
		
		setSize(300,150);
		setVisible(true);
		
		
	}
}
public class Java13_03 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new FlickeringLabelEx();
	}
}
