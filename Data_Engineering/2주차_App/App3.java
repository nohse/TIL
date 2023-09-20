package kr.ac.sejong.kmooc.data_engineering;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class App3 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\water\\eclipse-workspace\\data//email.txt"));
		int eventCount=0;
		while (true) {
			String line = br.readLine();
			if (line==null)
				break;
			if(line.startsWith("#"))
				continue; 
			eventCount++;
			String[] array=line.split("\t");
			int from=Integer.parseInt(array[0]);
			int to=Integer.parseInt(array[1]); 
			System.out.println(new Email(from, to));
		}
		System.out.println(eventCount);
		br.close();
	}
}
