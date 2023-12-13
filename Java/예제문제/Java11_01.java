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

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

class JComponentEx extends JFrame {
	public JComponentEx() {
		setTitle("MouseListener�� MouseMotionListener ����");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());

		JButton b1 = new JButton("Magenta/Yellow Button");
		JButton b2 = new JButton(" Disabled Button ");
		JButton b3 = new JButton("getX(), getY()");

		b1.setBackground(Color.YELLOW); // ���� ����
		b1.setForeground(Color.MAGENTA); // ���ڻ� ����
		b1.setFont(new Font("Arial", Font.ITALIC, 20)); // Arial, 20�ȼ� ��Ʈ ����
		b2.setEnabled(false); // ��ư ��Ȱ��ȭ
		b3.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				JButton b = (JButton)e.getSource();
				JComponentEx frame = (JComponentEx)b.getTopLevelAncestor();
				frame.setTitle(b.getX() + "," + b.getY()); // Ÿ��Ʋ�� ��ư ��ǥ ���

			}
			
		});
		c.add(b1);
		c.add(b2);
		c.add(b3);

		setSize(260, 200);
		setVisible(true);
	}
}

public class Java11_01 {
	public static void main(String[] args) {
		new JComponentEx();
	}

}
