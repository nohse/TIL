package kr.ac.sejong.kmooce.data_engineering.linkedlist;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;
import java.util.Deque;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;
import java.util.Queue;

import kr.ac.sejong.kmooc.data_engineering.Email;

public class LinkedListExample8 {
	public static void main(String [] args) {
		
		LinkedList<Integer> linkedlist=new LinkedList<Integer>();
		linkedlist.add(1);
		linkedlist.add(3);
		linkedlist.add(5);
		linkedlist.offer(7);
		linkedlist.offer(9);
		System.out.println(linkedlist);

	}
}
