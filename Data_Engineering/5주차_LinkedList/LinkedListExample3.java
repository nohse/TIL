package kr.ac.sejong.kmooce.data_engineering.linkedlist;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import kr.ac.sejong.kmooc.data_engineering.Email;

public class LinkedListExample3 {
	public static void main(String [] args) {
		
		List<Integer> linkedlist=new LinkedList<Integer>();
		System.out.println(linkedlist.isEmpty());
		System.out.println(linkedlist.size());

		linkedlist.add(3);
		linkedlist.add(5);
		linkedlist.add(7);
		
		System.out.println(linkedlist.isEmpty());
		System.out.println(linkedlist.size());

		List<Integer> arraylist=new ArrayList<Integer>(linkedlist);
		System.out.println(linkedlist.isEmpty());
		System.out.println(linkedlist.size());

		linkedlist.add(1, 9);
		arraylist.add(1, 9);
		System.out.println(linkedlist);
		System.out.println(arraylist);
	}
}
