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

public class LinkedListExample7 {
	public static void main(String [] args) {
		
		List<Integer> linkedlist=new LinkedList<Integer>();
		linkedlist.add(3);
		linkedlist.add(7);
		linkedlist.add(5);
		linkedlist.add(9);
		linkedlist.add(1);
		System.out.println(linkedlist);
		for(Object val: linkedlist.toArray()) {
			System.out.println(val);
		}
		linkedlist.sort(new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				if(o1<02)
					return -1;
				else if(01==02)
					return 0;
				return 1;
			}
		});
		System.out.println(linkedlist);
		
		System.out.println(linkedlist.subList(1, 3));
		
		linkedlist.clear();
		System.out.println(linkedlist.isEmpty());
		System.out.println(linkedlist.size());


	}
}
