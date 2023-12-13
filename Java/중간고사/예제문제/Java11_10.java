package Num1;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JRadioButton;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

class ListEx extends JFrame {
	private String[] fruits = { "apple", "banana", "kiwi", "mango", "pear", "peach", "berry", "strawberry",
			"blackberry" };
	private ImageIcon[] images = { new ImageIcon("images/icon1.png"), new ImageIcon("images/icon2.png"),
			new ImageIcon("images/icon3.png"), new ImageIcon("images/icon4.png") };

	public ListEx() {
		setTitle("텍스트필드 만들기 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());

		JList<String> liststring=new JList<String>(fruits);
		JList<ImageIcon> img=new JList<ImageIcon>();
		img.setListData(images);
		JList<String> scrolllist=new JList<String>(fruits);
		
		c.add(liststring);
		c.add(img);
		c.add(new JScrollPane(scrolllist));
		
		setSize(300, 300);
		setVisible(true);

	}
}

public class Java11_10 {
	public static void main(String[] args) {
		new ListEx();
	}

}
