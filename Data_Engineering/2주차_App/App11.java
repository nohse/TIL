package kr.ac.sejong.kmooc.data_engineering;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;

public class App11 {
		public static Email[] getData() throws IOException {
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
			
			return data;
			
		}
		public static void main (String[] args) throws IOException {
			Email[] data=getData();
			HashSet<Integer> senders=new HashSet<Integer>();
			for(Email email:data) {
				int from=email.from;
				senders.add(from);
			}
			System.out.println(senders.size());
		}
}
