package kr.ac.sejong.kmooc.data_engineering;

import java.util.ArrayList;
import java.util.Collection;

public class ArrayListExample2 {
	public static void main(String[] args) {
		ArrayList<Integer> intList=new ArrayList<Integer>();
		intList.add(3);
		System.out.println(intList.size());
		intList.add(7);
		intList.add(5);
		System.out.println(intList.size());
	}
}