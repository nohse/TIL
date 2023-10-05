package kr.ac.sejong.kmooce.data_engineering.linkedlist;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;
import java.util.Deque;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;
import java.util.NoSuchElementException;
import java.util.Queue;

import kr.ac.sejong.kmooc.data_engineering.Email;

public class LinkedListExample9 {
	public static void main(String [] args) {
		
		LinkedList<Integer> linkedlist=new LinkedList<Integer>();
		try {
		System.out.println(linkedlist.element());
		System.out.println("출력되지 않음");
		}catch(NoSuchElementException e) {
			System.out.println("출력됨");

		}
		System.out.println(linkedlist.peek());
		
		linkedlist.add(3);
		linkedlist.add(4);
		linkedlist.add(5);

		System.out.println(linkedlist.element());
		System.out.println(linkedlist.peek());

	}
}
