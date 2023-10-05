package kr.ac.sejong.kmooce.data_engineering.linkedlist;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Deque;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;
import java.util.Queue;

import kr.ac.sejong.kmooc.data_engineering.Email;

public class LinkedListExample6 {
	public static void main(String [] args) {
		
		List<Integer> linkedlist=new LinkedList<Integer>();
		linkedlist.add(1);
		linkedlist.add(3);
		linkedlist.add(5);
		linkedlist.add(7);
		linkedlist.add(9);
		Iterator<Integer> iterator=linkedlist.iterator();
		while(iterator.hasNext()) {
			System.out.println(iterator.next());
		}
		for(Integer val:linkedlist) {
			System.out.println(val);
		}
		ListIterator<Integer> listiterator=linkedlist.listIterator(3); 
		
		while(listiterator.hasPrevious()) {
			System.out.println(listiterator.previous());
		}
	}
}
