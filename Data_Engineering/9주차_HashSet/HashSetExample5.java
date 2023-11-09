package kr.ac.sejong.kmooc.data_engineering.hashset;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class HashSetExample5 {

	public static void main(String[] args) {
		HashSet<Integer> a=new HashSet<Integer>();
		a.add(2);
		a.add(5);
		a.add(10);
		a.add(4);
		a.add(20);
		System.out.println(a);
		HashSet<Integer> b=new HashSet<Integer>();
		b.add(2);
		b.add(5);
		b.add(10);
		b.add(3);
		b.add(6);
		b.add(15);
		b.add(30);
		System.out.println(b);
		System.out.println(a.containsAll(b));
		
//		a.addAll(b);
//		System.out.println(a);
//		a.retainAll(b);
//		System.out.println(a);
		a.removeAll(b);
		System.out.println(a);
	}

}
