package kr.ac.sejong.kmooce.data_engineering.linkedlist;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

import kr.ac.sejong.kmooc.data_engineering.Email;

public class LinkedListExample11 {
	public static List <Email> getData() throws IOException {
		List <Email> data=new LinkedList<Email>();
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
			data.add(new Email(from,to));
		}
		br.close();
		
		return data;
		
	}
	public static void main(String[] args) throws IOException {
		List<Email> data= getData();
		
		int count=0;
		int min=Integer.MAX_VALUE;
		int max=Integer.MIN_VALUE;
		for(Email email:data) {
			int from = email.getFrom();
			int to=email.getTo();
			count++;
			if(from<min)
				min=from;
			if(from>max)
				max=from;
			if(to<min)
				min=to;
			if(to>max)
				max=to;
		}
		System.out.println("count is "+count);
		System.out.println("min ID is "+min);
		System.out.println("max Id is "+max);
	}
}