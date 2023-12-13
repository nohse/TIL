package Num1;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;

class CheckBoxEx extends JFrame {
	public CheckBoxEx() {
		setTitle("20011619nohseonghyeon");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());

		ImageIcon img= new ImageIcon("images/cherry.jpg"); 
		ImageIcon selectedCherryIcon = new ImageIcon("images/selectedCherry.jpg");

		JCheckBox apple=new JCheckBox("사과");
		JCheckBox b=new JCheckBox("배",true);
		JCheckBox cherry=new JCheckBox("체리",img);
		cherry.setBorderPainted(true);
		cherry.setSelectedIcon(selectedCherryIcon);
		
		c.add(apple);
		c.add(b);
		c.add(cherry);
		
		setSize(250,150);
		setVisible(true);
	}

}
public class Java11_05 {
	public static void main(String[] args) {
		new CheckBoxEx();
	}

}
