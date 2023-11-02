import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.util.Random;

class MouseListenerEx extends JFrame {
    private JLabel la = new JLabel("Hello");
    private Container c;

    public MouseListenerEx() {
        setTitle("20011619 nohseonghyeon");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        c = getContentPane();
        c.addMouseListener(new MyMouseListener());

        c.setLayout(null);
        la.setSize(50, 20);
        la.setLocation(30, 30);
        c.add(la);

        setSize(250, 250);
        setVisible(true);
    }

    class MyMouseListener implements MouseListener {
        public void mousePressed(MouseEvent e) {
            int x = e.getX();
            int y = e.getY();
            la.setLocation(x, y);
        }

        public void mouseReleased(MouseEvent e) {}

        public void mouseClicked(MouseEvent e) {
            // Check for double-click
            if (e.getClickCount() == 2 && e.getButton() == MouseEvent.BUTTON1) {
            	
                Random rand = new Random();
                int R = rand.nextInt(256);
                int G = rand.nextInt(256);
                int B = rand.nextInt(256);
                
                Color myColor = new Color(R, G, B);

                c.setBackground(myColor);
            }
        }

        public void mouseEntered(MouseEvent e) {}

        public void mouseExited(MouseEvent e) {}
    }
}

public class JC20011619Q09 {
    public static void main(String[] args) {
        new MouseListenerEx();
    }
}

