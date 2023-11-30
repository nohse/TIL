import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class ComboBoxEx extends JFrame {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private String [] fruits = {"apple", "banana", "kiwi", "mango", "pear", 
			"peach", "berry", "strawberry", "blackberry"};
	private String [] names = {"kitae", "jaemoon", "hyosoo", "namyun"};
	private JTextField tf1 = new JTextField(20);
	private JTextField tf2 = new JTextField(20);
	//private JPanel jp1, jp2;
	JComboBox<String> strCombo;
	JComboBox<String> nameCombo;
	
	public ComboBoxEx() {
		setTitle("콤보박스 만들기 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());

		//jp1 = new JPanel();
		//jp2 = new JPanel();
		//jp1.setLayout(new FlowLayout());
		//jp2.setLayout(new FlowLayout());
		
		//jp1.add(tf1);
		c.add(tf1); c.add(tf2);
		strCombo = new JComboBox<String>(fruits); // 문자열 콤보박스 생성
		//jp1.add(strCombo);
		c.add(strCombo);
		//c.add(jp1);
		
		//jp2.add(tf2);
		
		nameCombo = new JComboBox<String>(); // 콤보박스 생성
		for(int i=0; i<names.length; i++)
			nameCombo.addItem(names[i]); // 콤보박스에 문자열 아이템 삽입
		c.add(nameCombo);
		//c.add(jp2);
		
		tf1.addActionListener(new MyActionListener());
		tf2.addActionListener(new MyActionListener());
		
		setSize(500,300);
		setVisible(true);
	}
	
	class MyActionListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			
			JTextField t = (JTextField)e.getSource();
			String tt = t.getText();
			
			if (t == tf1) {
				strCombo.addItem(tt);
			} else {
				nameCombo.addItem(tt);
			}
			t.setText(""); // 현재 텍스트필드에 입력된 내용 지우기
		}
	}
}

public class JC1113 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new ComboBoxEx();

	}

}
