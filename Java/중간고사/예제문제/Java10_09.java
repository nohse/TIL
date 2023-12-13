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

class ClickAndDoubleClickEx extends JFrame {
	public ClickAndDoubleClickEx() {
		setTitle("MouseListener¿Í MouseMotionListener ¿¹Á¦");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());

		c.addMouseListener(new MyMouseListener());
		setSize(300, 200);
		setVisible(true);
	}
	class MyMouseListener implements MouseListener{

		@Override	
		public void mouseClicked(MouseEvent e) {
			if(e.getClickCount()==2&&e.getButton()==MouseEvent.BUTTON1) {
				Container c=(Container)e.getSource();
				int r = (int)(Math.random()*256);
				int g = (int)(Math.random()*256);
				int b = (int)(Math.random()*256);
				c.setBackground(new Color(r,g,b));

			}
		}

		@Override
		public void mousePressed(MouseEvent e) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void mouseReleased(MouseEvent e) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void mouseEntered(MouseEvent e) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void mouseExited(MouseEvent e) {
			// TODO Auto-generated method stub
			
		}
		
	}
}

public class Java10_09 {
	public static void main(String[] args) {
		new ClickAndDoubleClickEx();
	}

}
