package kr.ac.sejong.kmooc.data_engineering;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class App5 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\water\\eclipse-workspace\\data//email.txt"));
		int min=Integer.MAX_VALUE;
		while (true) {
			String line = br.readLine();
			if (line==null)
				break;
			if(line.startsWith("#"))
				continue; 
			String[] array=line.split("\t");
			int from=Integer.parseInt(array[0]);
			if(from<min)
				min=from;
			int to=Integer.parseInt(array[1]); 
			if(to<min)
				min=to;
			System.out.println(new Email(from, to));
		}
		System.out.println(min);
		br.close();
	}
}
