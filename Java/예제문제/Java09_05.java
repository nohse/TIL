package Num1;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JButton;
import javax.swing.JFrame;
class BorderLayoutEx extends JFrame{
	public BorderLayoutEx() {
		setTitle("20011619nohseonghyeon");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c=getContentPane();
		c.setLayout(new BorderLayout(30,20));
		
		c.add(new JButton("add"),BorderLayout.NORTH);
		c.add(new JButton("div"),BorderLayout.WEST);
		c.add(new JButton("Calculate"),BorderLayout.CENTER);
		c.add(new JButton("mul"),BorderLayout.EAST);
		c.add(new JButton("sub"),BorderLayout.SOUTH);
		
		setSize(300,200);
		setVisible(true);
	}
}
public class Java09_05 {
	public static void main(String[] args) {
		BorderLayoutEx cpe=new BorderLayoutEx();
	}
}
