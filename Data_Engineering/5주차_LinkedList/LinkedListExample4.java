package kr.ac.sejong.kmooce.data_engineering.linkedlist;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;
import java.util.Queue;

import kr.ac.sejong.kmooc.data_engineering.Email;

public class LinkedListExample4 {
	public static void main(String [] args) {
		
		List<Integer> linkedlist=new LinkedList<Integer>();
		linkedlist.add(1);
		linkedlist.add(3);
		linkedlist.add(5);
		linkedlist.add(5);
		linkedlist.add(7);
		linkedlist.add(9);
		System.out.println(linkedlist);
		List<Integer> arraylist=new ArrayList<Integer>(linkedlist);
		System.out.println(linkedlist.contains(5));
		System.out.println(arraylist.contains(5));
		System.out.println(linkedlist.get(4));
		System.out.println(arraylist.get(5));
		System.out.println(linkedlist.indexOf(5));
		System.out.println(arraylist.indexOf(5));
		System.out.println(arraylist.lastIndexOf(5));
		System.out.println(arraylist.lastIndexOf(5));
	}
}
