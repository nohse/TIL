package kr.ac.sejong.kmooc.data_engineering;

import java.util.ArrayList;
import java.util.Collection;

public class ArrayListExample8 {
	public static void main(String[] args) {
		ArrayList<Integer> l=new ArrayList<Integer>();
		l.add(1);
		l.add(5);
		l.add(3);
		l.add(5);
		l.add(1);
		l.add(7);
		System.out.println(l);
		System.out.println(l.remove(Integer.valueOf(5)));
		System.out.println(l);
	}
}