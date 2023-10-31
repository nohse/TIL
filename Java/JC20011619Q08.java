import javax.swing.*;
import java.awt.*;

class FlowLayoutEx extends JFrame {
	public FlowLayoutEx() {
		setTitle("20011619/nohseonghyeon");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();

		c.setLayout(new FlowLayout(FlowLayout.LEFT, 30, 40));
		c.add(new JButton("add"));
		c.add(new JButton("sub"));
		c.add(new JButton("mul"));
		c.add(new JButton("div"));
		c.add(new JButton("Calculate"));

		setSize(300, 200);
		setVisible(true);
	}


}

 class BorderLayoutEx extends JFrame {
	public BorderLayoutEx() {
		setTitle("20011619/nohseonghyeon");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		Container c = getContentPane();

		c.setLayout(new BorderLayout(30, 20));
		c.add(new JButton("Calculate"), BorderLayout.CENTER);
		c.add(new JButton("add"), BorderLayout.NORTH);
		c.add(new JButton("sub"), BorderLayout.SOUTH);
		c.add(new JButton("mul"), BorderLayout.EAST);
		c.add(new JButton("div"), BorderLayout.WEST);

		setSize(300, 200); // 프레임 크기 300×200 설정
		setLocation(300,0);
		setVisible(true); // 프레임을 화면에 출력
	}
}
 
 public class JC20011619Q08{
	 public static void main(String[] args) {
		 new FlowLayoutEx();
		 new BorderLayoutEx();
	 }
 }
