package kr.ac.sejong.kmooce.data_engineering.linkedlist;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;
import java.util.Queue;

import kr.ac.sejong.kmooc.data_engineering.Email;

public class LinkedListExample5 {
	public static void main(String [] args) {
		
		List<Integer> linkedlist=new LinkedList<Integer>();
		linkedlist.add(1);
		linkedlist.add(3);
		linkedlist.add(5);
		linkedlist.add(5);
		linkedlist.add(7);
		linkedlist.add(9);
		List<Integer> arraylist=new ArrayList<Integer>(linkedlist);
		linkedlist.set(2,4);
		arraylist.set(2,4);
		System.out.println(linkedlist);
		System.out.println(arraylist);
		
		System.out.println(linkedlist.remove(Integer.valueOf(4)));
		System.out.println(arraylist.remove(Integer.valueOf(4)));

		System.out.println(linkedlist);
		System.out.println(arraylist);
		
		System.out.println(linkedlist.remove(3));
		System.out.println(arraylist.remove(3));

		System.out.println(linkedlist);
		System.out.println(arraylist);

		
	}
}
