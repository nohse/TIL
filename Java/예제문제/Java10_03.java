package Num1;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
class AnonymousClassListener extends JFrame{
	JButton btn=new JButton("Action");
	public AnonymousClassListener() {
		setTitle("20011619nohseonghyeon");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c= getContentPane();
		c.setLayout(new FlowLayout());
		
		btn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				JButton btn=(JButton)e.getSource();
				if(btn.getText().equals("Action")) {
					btn.setText("¾×¼Ç");
				}
				else {
					btn.setText("Action");
				}
				setTitle(btn.getText());
			}
		});
		c.add(btn);
		
		setSize(200,150);
		setVisible(true);
		
	}
}
public class Java10_03 {
	public static void main(String[] args) {
		new AnonymousClassListener();
	}
}
