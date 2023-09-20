package kr.ac.sejong.kmooc.data_engineering;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class App7 {
		public static void app2() throws IOException {
			BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\water\\eclipse-workspace\\data//email.txt"));
			int lineCount=0;
			while (true) {
				String line = br.readLine();
				if (line==null)
					break;
				lineCount++;
				if(line.startsWith("#"))
					continue; 
				String[] array=line.split("\t");
				int from=Integer.parseInt(array[0]);
				int to=Integer.parseInt(array[1]); 
			}
			System.out.println(" 줄 수:  "+lineCount);
			br.close();
		}
		public static void app3(Email[] data) throws IOException {
			int size=0;
			for(int i=0;i<data.length;i++) {
				size++;
				}
			System.out.println(size);
		}
		public static void app4(Email[] data) throws IOException {
			int min=Integer.MAX_VALUE;
			for(Email email:data) {
				if(email.from<min) {
					min=email.from;
				}
				if(email.to<min) {
					min=email.to;
				}
			}
			System.out.println(min);
		}
		public static void app5(Email[] data) throws IOException {
			int max=Integer.MIN_VALUE;
			for(Email email:data) {
				if(email.from>max) {
					max=email.from;
				}
				if(email.to>max) {
					max=email.to;
				}
			}
			System.out.println(max);
		}
		public static void main (String[] args) throws IOException {
			
			long pre=System.currentTimeMillis();
			
			Email[] data=new Email[420045];
			BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\water\\eclipse-workspace\\data//email.txt"));
			int index=0;
			while (true) {
				String line = br.readLine();
				if (line==null)
					break;
				if(line.startsWith("#"))
					continue; 
				String[] array=line.split("\t");
				int from=Integer.parseInt(array[0]);
				int to=Integer.parseInt(array[1]); 
				data[index++]=new Email(from,to);
			}
			br.close();
			app2();
			app3(data);
			app4(data);
			app5(data);
			System.out.println(System.currentTimeMillis()-pre); 
		}
}
