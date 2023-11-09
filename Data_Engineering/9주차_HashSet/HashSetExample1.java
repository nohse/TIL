package kr.ac.sejong.kmooc.data_engineering.hashset;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;
import java.util.Set;

public class HashSetExample1 {

	public static void main(String[] args) {
		Collection<Integer> inHashSet=new HashSet<Integer>();
		System.out.println(inHashSet);
		
		ArrayList<Integer> arraylist=new ArrayList<Integer> ();
		arraylist.add(1);
		arraylist.add(3);
		arraylist.add(3);
		arraylist.add(5);
		System.out.println(arraylist);
		HashSet<Integer> intHashSet2=new HashSet<Integer>(arraylist);
		System.out.println(intHashSet2);
	}

}
