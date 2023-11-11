package AT0104;

import java.awt.FlowLayout;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class JCAT0104 extends JFrame{

	JLabel la; 
	String text = "Love Java";
	JCAT0104(){
		setTitle("Left 키로 문자열 이동");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(new FlowLayout());
		
		
		la= new JLabel("Love Java");
		
		la.addKeyListener(new MyKeyAdapter());
		
		la.setSize(100,30);
		add(la);
		setSize(300,300);
		setVisible(true);
		la.requestFocus();
		
	}
	class MyKeyAdapter extends KeyAdapter{
		public void keyPressed(KeyEvent e) {
		if(e.getKeyCode()==KeyEvent.VK_LEFT) { 
			text = text.substring(1)+text.substring(0, 1);
			la.setText(text); 
			}
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new JCAT0104();
	}

}