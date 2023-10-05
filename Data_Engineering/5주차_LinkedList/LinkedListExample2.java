package kr.ac.sejong.kmooce.data_engineering.linkedlist;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import kr.ac.sejong.kmooc.data_engineering.Email;

public class LinkedListExample2 {
	public static void main(String [] args) {
		
		ArrayList<Integer> arraylist=new ArrayList<Integer>();
		arraylist.add(3);
		arraylist.add(7);
		arraylist.add(5);
		System.out.println(arraylist);

		LinkedList<Integer> intlist = new LinkedList<Integer>(arraylist);
		LinkedList<String> stringlist = new LinkedList<String>();
		LinkedList<Email> emaillist = new LinkedList<Email>();
		
		System.out.println(intlist);
		System.out.println(stringlist);
		System.out.println(emaillist);

	}
}
