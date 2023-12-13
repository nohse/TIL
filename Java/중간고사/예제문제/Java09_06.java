package Num1;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
class NullContainerEx extends JFrame{
	public NullContainerEx() {
		setTitle("20011619nohseonghyeon");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c=getContentPane();
		c.setLayout(null);
		
		JLabel la=new JLabel("Hello, Press Buttons!");
		la.setLocation(130,50);
		la.setSize(200,20);
		c.add(la);
		
		for(int i=1;i<10;i++) {
			JButton btn=new JButton(Integer.toString(i));
			btn.setLocation(i*15,i*15);
			btn.setSize(50,20);
			c.add(btn);
			
		}
		setSize(300,200);
		setVisible(true);
	}
}
public class Java09_06 {
	public static void main(String[] args) {
		NullContainerEx cpe=new NullContainerEx();
	}
}
