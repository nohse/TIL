package kr.ac.sejong.kmooc.data_engineering;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.TreeSet;

import javax.swing.text.html.HTMLDocument.Iterator;

public class App12 {
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
			TreeSet<Integer> treeSet=new TreeSet<Integer>();
			for(Email email:data) {
				treeSet.add(email.from);
				treeSet.add(email.to);
			}
			System.out.println(treeSet.lower(100000));
			System.out.println(treeSet.higher(100000));
			System.out.println(treeSet.first());
			System.out.println(treeSet.last());
			Iterator<Integer> iterator=treeSet.iterator(); 
		}
}
