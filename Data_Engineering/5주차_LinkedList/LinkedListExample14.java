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

public class LinkedListExample14 {
	public static List <Email> getLinkedList() throws IOException {
		List <Email> data=new LinkedList<Email>();
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
			data.add(new Email(from,to));
		}
		br.close();
		
		return data;
		
	}
	public static void main(String[] args) throws IOException {
		List<Email> array= getArrayList();
		List<Email> link= getLinkedList();
		long p1=System.currentTimeMillis();
		int from =0;
		for(Email email: array) {
			from+=email.getFrom();
		}
		System.out.println("array ="+(System.currentTimeMillis()-p1));
		from=0;
		long p2=System.currentTimeMillis();
		for(Email email: link) {
			from+=email.getFrom();
		}
		System.out.println("link ="+(System.currentTimeMillis()-p2));
		
		long p3=System.currentTimeMillis();
		from =0;
		for(int i=0;i<array.size();i++) {
			from+=array.get(i).getFrom();
		}
		System.out.println("array ="+(System.currentTimeMillis()-p3));
		from=0;
		
		long p4=System.currentTimeMillis();
		for(int i=0;i<link.size();i++) {
			from+=link.get(i).getFrom();
			System.out.println(i);
		}
		System.out.println("link ="+(System.currentTimeMillis()-p4));
	}

}