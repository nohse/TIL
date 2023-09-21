
public class JC20011619Q04 {
	public static void main(String[] args) {
		int i=1,j=1;
		System.out.println("노성현20011619");
		while(i<10) { // 1단에서 9단
			while(j<10) { // 각 단의 구구셈 출력
				System.out.print(i + "*" + j + "=" + i*j); // 구구셈 출력
				System.out.print('\t'); // 하나씩 탭으로 띄기
				j++;
			}
			System.out.println(); // 한 단이 끝나면 다음 줄로 커서 이동
			j=1;
			i++;
		}
	}

}
