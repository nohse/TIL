package AT0102;

public class JCAT0102 {
	public static void main(String[] args) {
		int[][] arr=new int[4][4];
		for(int i=0;i<4;i++) {
			for(int j=0;j<4;j++) {
				arr[i][j]=0;
			}
		}
		for(int i=0;i<10;i++) {
			int a,b;
			int key=(int)(Math.random()*10+1);
			do {
			a=(int)(Math.random()*4);
			b=(int)(Math.random()*4);
			}while(arr[a][b]!=0);
			arr[a][b]=key;
		}
		for(int i=0;i<4;i++) {
			for(int j=0;j<4;j++) {
				System.out.print(arr[i][j]+" ");
			}
			System.out.println();
		}
		
	}
}
