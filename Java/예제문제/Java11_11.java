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
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JRadioButton;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

class ListChangeEx extends JFrame {	
	private JTextField tf=new JTextField(10);
	private Vector<String> v=new Vector<String>();
	private JList<String> namelist=new JList<String>(v);
	public ListChangeEx() {
		setTitle("텍스트필드 만들기 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		c.add(new JLabel("이름 입력 후 <Enter>키"));
		tf.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				v.add(tf.getText());
				tf.setText("");
				namelist.setListData(v);
			}
		});
		c.add(tf);
		v.add("노성현");
		v.add("노장현");
		namelist.setVisibleRowCount(5);
		namelist.setFixedCellWidth(100);

		c.add(new JScrollPane(namelist));
		
		setSize(300, 300);
		setVisible(true);

	}
}

public class Java11_11 {
	public static void main(String[] args) {
		new ListChangeEx();
	}

}
