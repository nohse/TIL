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
import java.util.Vector;

import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JRadioButton;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

class ComboBoxEx extends JFrame {
	private String[] fruits = { "apple", "banana", "kiwi", "mango", "pear", "peach", "berry", "strawberry",
			"blackberry" };
	private String[] names = { "kitae", "jaemoon", "hyosoo", "namyun" };
	JComboBox<String> fruitc=new JComboBox<String>(fruits);
	JComboBox<String> namec=new JComboBox<String>();
//	private JTextField tf=new JTextField(10);
	public ComboBoxEx() {
		setTitle("텍스트필드 만들기 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
//		c.add(tf);
//		tf.addActionListener(new ActionListener() {
//			
//			@Override
//			public void actionPerformed(ActionEvent e) {
//				namec.addItem(tf.getText());
//				tf.setText("");
//			}
//		});
		c.setLayout(new FlowLayout());


		for(int i=0;i<names.length;i++) {
			namec.addItem(names[i]);
		}
		c.add(fruitc);
		c.add(namec);
		
		setSize(300, 300);
		setVisible(true);

	}
}

public class Java11_12 {
	public static void main(String[] args) {
		new ComboBoxEx();
	}

}
