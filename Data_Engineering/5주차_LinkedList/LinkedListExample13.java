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

public class LinkedListExample13 {
	public static LinkedList <Email> getLinkedList() throws IOException {
		LinkedList <Email> data=new LinkedList<Email>();
		BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\water\\eclipse-workspace\\data//email.txt"));
		int index=0;
		while (true)  {
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
	public static ArrayList <Email> getArrayList() throws IOException {
		ArrayList <Email> data=new ArrayList<Email>();
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
		ArrayList<Email> array= getArrayList();
		LinkedList<Email> link= getLinkedList();
		
		long p1=System.currentTimeMillis();
		while(true) {
			if(array.size()>0)
				array.remove(array.size()-1);
			else 
				break;
		}
		System.out.println("array = "+(System.currentTimeMillis()-p1));
		long p2=System.currentTimeMillis();
		while(true) {
			Email email=link.poll();
			if(email==null)
				break;
		}
		System.out.println("link = "+(System.currentTimeMillis()-p2));

		 
	}

}