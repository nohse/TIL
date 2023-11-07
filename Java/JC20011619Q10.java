import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
class FlyingTextEx extends JFrame {
	private final int FLYING_UNIT = 10;
	private JLabel la = new JLabel("HELLO"); 
	public FlyingTextEx() {
		setTitle("20011619 nohseonghyeon");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(null);
		c.addKeyListener(new MyKeyListener());

		la.setLocation(50,50);
		la.setSize(100,20);
		c.add(la);
		setSize(300,300);
		setVisible(true);
		c.setFocusable(true);
		c.requestFocus();

		c.addMouseListener(new MyMouseListener());
	}
	class MyMouseListener implements MouseListener {
        public void mousePressed(MouseEvent e) {}

        public void mouseReleased(MouseEvent e) {}

        public void mouseClicked(MouseEvent e) {
            // Check for double-click
        	int x,y;
        	x=e.getX();
        	y=e.getY();
            if (e.getClickCount() ==2&&e.getButton()==MouseEvent.BUTTON1) {
            	la.setLocation(x,y);
            }
        }

        public void mouseEntered(MouseEvent e) {}

        public void mouseExited(MouseEvent e) {}
    }
class MyKeyListener extends KeyAdapter {
	public void keyPressed(KeyEvent e) {
		int keyCode = e.getKeyCode();
			switch(keyCode) {
			case KeyEvent.VK_UP: 
				la.setLocation(la.getX(), la.getY()-FLYING_UNIT);
				break;
			case KeyEvent.VK_DOWN: 
				la.setLocation(la.getX(), la.getY()+FLYING_UNIT); 
				break;
			case KeyEvent.VK_LEFT: 
				la.setLocation(la.getX()-FLYING_UNIT, la.getY()); 
				break;
			case KeyEvent.VK_RIGHT: 
				la.setLocation(la.getX()+FLYING_UNIT, la.getY()); 
				break;
		}
	}
	}
}
public class JC20011619Q10 {
	public static void main(String [] args) {
		new FlyingTextEx();
	}

}
