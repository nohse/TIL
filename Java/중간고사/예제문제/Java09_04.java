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
import javax.swing.JTextField;
class GridLayoutEx extends JFrame{
	public GridLayoutEx() {
		setTitle("20011619nohseonghyeon");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c=getContentPane();
		GridLayout grid =new GridLayout(4,2);
		grid.setVgap(5);
		c.setLayout(grid);
		
		c.add(new JLabel("이름"));
		c.add(new JTextField(""));
		c.add(new JLabel("학번"));
		c.add(new JTextField(""));
		c.add(new JLabel("학과"));
		c.add(new JTextField(""));
		c.add(new JLabel("과목"));
		c.add(new JTextField(""));
		
		setSize(300,200);
		setVisible(true);
	}
}
public class Java09_04 {
	public static void main(String[] args) {
		GridLayoutEx cpe=new GridLayoutEx();
	}
}
