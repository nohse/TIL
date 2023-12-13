package Num1;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JRadioButton;
import javax.swing.SwingConstants;

class RadioButtonEx extends JFrame {
	JRadioButton b1=new JRadioButton("사과");
	JRadioButton b2=new JRadioButton("배");
	JRadioButton b3=new JRadioButton("체리");
	JLabel la=new JLabel();
	public RadioButtonEx() {
		setTitle("20011619nohseonghyeon");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		ButtonGroup g=new ButtonGroup();

		
		
		MyItemListener listener=new MyItemListener();
		
		g.add(b1);
		g.add(b2);
		g.add(b3);
		
		b1.addItemListener(listener);
		b2.addItemListener(listener);
		b3.addItemListener(listener);
		
		c.add(b1);
		c.add(b2);
		c.add(b3);
		c.add(la);
		
		setSize(250,150);
		setVisible(true);
	}
	class MyItemListener implements ItemListener{

		@Override
		public void itemStateChanged(ItemEvent e) {
			if(e.getStateChange()==ItemEvent.SELECTED) {
				if(e.getItem()==b1) {
					la.setText("사과");
				}
				else if(e.getItem()==b2) {
					la.setText("배");
				}
				else if(e.getItem()==b3) {
					la.setText("체리");
				}
			}
			
		}
		
	}

}
public class Java11_07 {
	public static void main(String[] args) {
		new RadioButtonEx();
	}

}
