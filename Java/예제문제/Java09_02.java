package Num1;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JButton;
import javax.swing.JFrame;
class ContentPaneEx extends JFrame{
	JButton btn1=new JButton("OK");
	JButton btn2=new JButton("Cancel");
	JButton btn3=new JButton("Ignore");
	public ContentPaneEx() {
		setTitle("20011619nohseonghyeon");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c=getContentPane();
		c.setBackground(Color.ORANGE);
		c.setLayout(new FlowLayout());
		
		c.add(btn1);
		c.add(btn2);
		c.add(btn3);
		
		setSize(300,150);
		setVisible(true);
	}
}
public class Java09_02 {
	public static void main(String[] args) {
		ContentPaneEx cpe=new ContentPaneEx();
	}
}
