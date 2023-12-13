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
class FlyingTextEx extends JFrame {
	private JLabel la1 = new JLabel("HELLO"); 

	public FlyingTextEx() {
		setTitle("20011619nohseonghyeon");
		setDefaultCloseOperation(JFrame	.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(null);
		
		c.addKeyListener(new MyKeyListener()); 		
		c.add(la1);
		la1.setLocation(50,50);
		la1.setSize(100,20);

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
			if(e.getKeyCode()==KeyEvent.VK_UP) {
				la1.setLocation(la1.getX(),la1.getY()-10);
			}
			else if(e.getKeyCode()==KeyEvent.VK_DOWN) {
				la1.setLocation(la1.getX(),la1.getY()+10);
			}
			else if(e.getKeyCode()==KeyEvent.VK_LEFT) {
				la1.setLocation(la1.getX()-10,la1.getY());
			}
			else if(e.getKeyCode()==KeyEvent.VK_RIGHT) {
				la1.setLocation(la1.getX()+10,la1.getY());
			}
		}

		@Override
		public void keyReleased(KeyEvent e) {
			// TODO Auto-generated method stub
			
		}
		
	}
}


public class Java10_08 {
	public static void main(String[] args) {
		new FlyingTextEx();
	}
}
