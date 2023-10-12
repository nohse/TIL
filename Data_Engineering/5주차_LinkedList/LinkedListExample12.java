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

public class LinkedListExample12 {
	public static List <Email> getLinkedList() throws IOException {
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
			data.add(0,new Email(from,to));
		}
		br.close();
		
		return data;
		
	}
	public static List <Email> getArrayList() throws IOException {
		List <Email> data=new ArrayList<Email>();
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
			data.add(0,new Email(from,to));
		}
		br.close();
		
		return data;
		
	}
	public static void main(String[] args) throws IOException {
		long p1=System.currentTimeMillis();
		List<Email> array= getArrayList();
		System.out.println("Array list = " + (System.currentTimeMillis()-p1));
		long p2=System.currentTimeMillis();
		List<Email> link= getLinkedList();
		System.out.println("Linked list  = " + (System.currentTimeMillis()-p2));


	}

}