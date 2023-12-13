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

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;

class CheckBoxEx extends JFrame {
	JLabel sum = new JLabel("���� 0�� �Դϴ�.");
	JCheckBox apple = new JCheckBox("���");
	JCheckBox b = new JCheckBox("��");
	JCheckBox cherry = new JCheckBox("ü��");

	public CheckBoxEx() {
		setTitle("20011619nohseonghyeon");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JLabel la = new JLabel("��� 100��, ��500��, ü�� 20000");
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		MyItemListener listener=new MyItemListener();
		apple.addItemListener(listener);
		b.addItemListener(listener);
		cherry.addItemListener(listener);

		c.add(la);
		c.add(apple);
		c.add(b);
		c.add(cherry);
		c.add(sum);

		setSize(200, 180);
		setVisible(true);
	}

	class MyItemListener implements ItemListener {
		private int result = 0;
		@Override
		public void itemStateChanged(ItemEvent e) {
			if (e.getStateChange() == ItemEvent.SELECTED) {
				if (e.getItem()  == apple) {
					result += 100;
				} else if (e.getItem()  == b) {
					result += 500;
				} else if (e.getItem()  == cherry) {
					result += 20000;
				}
			}
			else {
				if (e.getItem()  == apple) {
					result -= 100;
				} else if (e.getItem()  == b) {
					result -= 500;
				} else if (e.getItem()  == cherry) {
					result -= 20000;
				}
			}
			sum.setText("���� " + result + "�� �Դϴ�.");
		}

	}

}

public class Java11_04 {
	public static void main(String[] args) {
		new CheckBoxEx();
	}

}
