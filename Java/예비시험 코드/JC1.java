package num1;
import util.*;

class PrintShop {
	private String pChar;  // 기본 출력 문자열
	private int maxNum = 3;   // 한줄당 최대 출력 갯수
	private int maxIter = 2;  // 최대 출력 "라인" 갯수
	
	PrintShop() {
		pChar = "#";
		maxNum = 3;
		maxIter = 2;
	}
	
	PrintShop(String anotherChar) {
		pChar=anotherChar;

	}
	
	PrintShop(String anotherChar, int mN) {
		pChar=anotherChar;
		maxNum=mN;

	}
	
	PrintShop(String anotherChar, int mN, int mI) {
		pChar=anotherChar;
		maxNum=mN;
		maxIter=mI;

	}
	
	// can implement additional methods here
	
	void print() {
		for(int i=0;i<maxNum;i++) {
			for(int j=i;j>=0;j--) {
				System.out.print(pChar);
			}
			System.out.print("\n");
		}
		for(int i=0;i<maxNum;i++) {
			for(int j=maxNum;j>i;j--) {
				System.out.print(pChar);
			}
			System.out.print("\n");
		}
		System.out.println("--------------------");
	}
	

	void printReverse() {
		int i=0;
		while(i<maxNum) {
			int j=maxNum;
			while(j>i) {
				System.out.print(pChar);
				j--;
			}
			i++;
			System.out.print("\n");
		}
		i=0;
		while(i<maxNum) {
			int j=i;
			while(j>=0) {
				System.out.print(pChar);
				j--;
			}
			System.out.print("\n");
			i++;
		}
		System.out.println("--------------------");
	}
}

public class JC1 {
	public static void main(String[] args) {
		System.out.println("20011619노성현");
		ReadText rT = new ReadText("num1");
		String line="";
		String tokens[];
		
		PrintShop p1;
		int i;
		
		p1= new PrintShop();
		p1.print();
		p1.printReverse();
	
		while ((line = rT.readLine()) != null) {
			tokens = line.split(" ");
			p1 = new PrintShop(tokens[0],Integer.parseInt(tokens[1]),Integer.parseInt(tokens[2]));
			p1.print();
			p1.printReverse();

		}

		
	}

}