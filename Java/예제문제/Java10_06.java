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
class KeyListenerEx extends JFrame {
	private JLabel la1 = new JLabel("la1"); 
	private JLabel la2 = new JLabel("la2"); 
	private JLabel la3 = new JLabel("la3"); 

	public KeyListenerEx() {
		setTitle("20011619nohseonghyeon");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		c.addKeyListener(new MyKeyListener()); 
		
		la1.setOpaque(true);
		la2.setOpaque(true);
		la3.setOpaque(true);

		la1.setBackground(Color.YELLOW);
		la2.setBackground(Color.YELLOW);
		la3.setBackground(Color.YELLOW);
		
		c.add(la1);
		c.add(la2);
		c.add(la3);

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
			la1.setText(Integer.toString(e.getKeyCode()));
			la2.setText(Character.toString(e.getKeyChar()));
			la3.setText(e.getKeyText(e.getKeyCode()));
		}

		@Override
		public void keyReleased(KeyEvent e) {
			// TODO Auto-generated method stub
			
		}
		
	}
}


public class Java10_06 {
	public static void main(String[] args) {
		new KeyListenerEx();
	}
}
