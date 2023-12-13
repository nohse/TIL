package Num1;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
class KeyCodeEx extends JFrame {
	private JLabel la1 = new JLabel("la1"); 

	public KeyCodeEx() {
		setTitle("20011619nohseonghyeon");
		setDefaultCloseOperation(JFrame	.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		c.addKeyListener(new MyKeyListener()); 		
		c.add(la1);

		setSize(250, 250);
		setVisible(true);
		

		c.setFocusable(true);
		c.requestFocus();

	}	
	private class MyKeyListener implements KeyListener{

		@Override
		public void keyTyped(KeyEvent e) {
		}

		@Override
		public void keyPressed(KeyEvent e) {
			// TODO Auto-generated method stub
			la1.setText(e.getKeyText(e.getKeyCode()));
			Container c=(Container)e.getSource();
			if(e.getKeyChar()=='%') {
				c.setBackground(Color.YELLOW);
			}
			else if(e.getKeyCode()==KeyEvent.VK_F1)
				c.setBackground(Color.GREEN);
		}

		@Override
		public void keyReleased(KeyEvent e) {
			// TODO Auto-generated method stub
			
		}
		
	}
}


public class Java10_07 {
	public static void main(String[] args) {
		new KeyCodeEx();
	}
}
