package Num1;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.*;
class RandomThread extends Thread{
	private Container c;
	private boolean finish=false;
	public RandomThread(Container c) {
		this.c=c;
	}
	void finish() {
		finish=true;
	}
	public void run() {
		while(true) {
			int x = ((int)(Math.random()*c.getWidth()));
			int y = ((int)(Math.random()*c.getHeight()));
			JLabel label = new JLabel("Java"); //새 레이블 생성
			label.setSize(80, 30); 
			label.setLocation(x, y);		
			c.add(label);
			c.repaint(); 

			try {
				sleep(300);
				if(finish==true) {
					c.removeAll();
					label = new JLabel("finish"); 
					label.setSize(80, 30); 
					label.setLocation(100, 100); 
					label.setForeground(Color.RED);
					c.add(label);
					c.repaint();
					return;
				}
			}catch(InterruptedException e) {
				return ;
			}
		}
	}
}
class ThreadFinishFlagEx extends JFrame{
	private RandomThread th;
	ThreadFinishFlagEx(){
		setTitle("20011619nohseonghyeon");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c=getContentPane();
		c.setLayout(null);
		
		c.addMouseListener(new MouseAdapter() {

			@Override
			public void mousePressed(MouseEvent e) {
				th.finish();
			}
		});
		setSize(300,200);
		setVisible(true);
		
		th=new RandomThread(c);
		th.start();
	}
}
public class Java13_05 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new ThreadFinishFlagEx();
	}
}
