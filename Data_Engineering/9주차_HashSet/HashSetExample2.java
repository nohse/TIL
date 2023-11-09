package kr.ac.sejong.kmooc.data_engineering.hashset;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;
import java.util.Set;

public class HashSetExample2 {

	public static void main(String[] args) {
		HashSet<Integer> intHashSet=new HashSet<Integer>();
		System.out.println(intHashSet);
		System.out.println(intHashSet.isEmpty());
		System.out.println(intHashSet.size());
		intHashSet.add(1);
		System.out.println(intHashSet);
		intHashSet.add(1);
		System.out.println(intHashSet);
		intHashSet.add(3);
		System.out.println(intHashSet);
		intHashSet.add(5);
		System.out.println(intHashSet);
		System.out.println(intHashSet.isEmpty());
		System.out.println(intHashSet.size());
		System.out.println(intHashSet.contains(4));
		intHashSet.remove(3);
		System.out.println(intHashSet);
		System.out.println(intHashSet.size());
	}

}
