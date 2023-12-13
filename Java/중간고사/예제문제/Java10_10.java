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

class MouseListenerAllEx extends JFrame {
	private JLabel la = new JLabel("No Mouse Event");

	public MouseListenerAllEx() {
		setTitle("MouseListener¿Í MouseMotionListener ¿¹Á¦");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());

		MyMouseListener listener = new MyMouseListener();
		c.addMouseListener(listener);
		c.addMouseMotionListener(listener);

		c.add(la);

		setSize(300, 200);
		setVisible(true);
	}

	class MyMouseListener implements MouseListener, MouseMotionListener {
		public void mousePressed(MouseEvent e) {
			la.setText("mousePressed (" + e.getX() + ", " + e.getY() + ")");
		}

		public void mouseReleased(MouseEvent e) {
			la.setText("MouseReleased(" + e.getX() + ", " + e.getY() + ")");
		}

		public void mouseClicked(MouseEvent e) {
		}

		public void mouseEntered(MouseEvent e) {
			Component c = (Component) e.getSource();
			c.setBackground(Color.CYAN);
		}

		public void mouseExited(MouseEvent e) {
			Component c = (Component) e.getSource();
			c.setBackground(Color.YELLOW);
		}

		public void mouseDragged(MouseEvent e) {
			la.setText("MouseDragged (" + e.getX() + "," + e.getY() + ")");
		}

		public void mouseMoved(MouseEvent e) {
			la.setText("MouseMoved (" + e.getX() + "," + e.getY() + ")");
		}
	}
}

public class Java10_10 {
	public static void main(String[] args) {
		new MouseListenerAllEx();
	}

}
