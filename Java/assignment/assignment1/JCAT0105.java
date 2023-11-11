package AT0105;

import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;


public class JCAT0105 extends JFrame{
	JLabel la; 
	JCAT0105(){
		setTitle("클릭 연습 용 응용프로그램");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(null);
		
		la= new JLabel("C");
		la.setSize(20,20);
		la.setLocation(100,100);
		la.addMouseListener(new MyMouseAdapter());

		add(la);
		setSize(500,500);
		setVisible(true);
		la.requestFocus();
		
	}
	class MyMouseAdapter extends MouseAdapter{
		int x,y;
		public void mouseClicked(MouseEvent e) {
			x = (int)(Math.random()*450);
			y = (int)(Math.random()*450);
			la.setLocation(x,y);
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new JCAT0105();
	}
	
}