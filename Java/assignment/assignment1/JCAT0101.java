package AT0101;

import java.util.Scanner;

public class JCAT0101 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("정수 몇개?");
        int n = scan.nextInt();
        Integer[] arr = new Integer[n];

        for (int i = 0; i < n; i++) {
            int key=(int)(Math.random()*100+1);
            int flag=0;
            for(int j=0;j<i;j++) {
            	if(arr[j]==key) {
            		flag=1;
            		i--;
            		break;
            	}
            }
            if(flag==1)
            	continue;
            arr[i] = key;
        }

        for (int i = 0; i < n; i++) {
        	if(i!=0&&i%10==0)
        		System.out.println();
            System.out.print(arr[i] + " ");
        }

        scan.close();
    }

}