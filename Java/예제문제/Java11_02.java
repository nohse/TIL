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
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;

class LabelEx extends JFrame {
	public LabelEx() {
		setTitle("MouseListener�� MouseMotionListener ����");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());

		JLabel la1=new JLabel("����մϴ�.");
		
		ImageIcon img1=new ImageIcon("images/beauty.jpg");
		JLabel la2=new JLabel(img1);
		
		ImageIcon normalIcon = new ImageIcon("images/normalIcon.gif"); 
		JLabel la3 = new JLabel("��������� ��ȭ�ϼ���",
					normalIcon, SwingConstants.CENTER);

		c.add(la1);
		c.add(la2);
		c.add(la3);
		setSize(400, 600);
		setVisible(true);
	}
}

public class Java11_02 {
	public static void main(String[] args) {
		new LabelEx();
	}

}
