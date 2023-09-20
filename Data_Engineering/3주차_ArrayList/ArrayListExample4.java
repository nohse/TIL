package kr.ac.sejong.kmooc.data_engineering;

import java.util.ArrayList;
import java.util.Collection;

public class ArrayListExample4 {
	public static void main(String[] args) {
		ArrayList<Integer> l=new ArrayList<Integer>();
		l.add(0,3);
		System.out.println(l);
		l.add(1,5);
		System.out.println(l);
		l.add(2,7);
		System.out.println(l);
		l.add(1,9);
		System.out.println(l);
		
	}
}