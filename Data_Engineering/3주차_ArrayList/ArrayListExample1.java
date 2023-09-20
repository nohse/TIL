package kr.ac.sejong.kmooc.data_engineering;

import java.util.ArrayList;
import java.util.Collection;

public class ArrayListExample1 {
	public static void main(String[] args) {
		ArrayList<Integer> intlist =new ArrayList<Integer>(); 
		System.out.println(intlist.isEmpty());
		System.out.println(intlist.size());
		ArrayList<String> stringlist =new ArrayList<String>(); 
		System.out.println(stringlist.isEmpty());
		System.out.println(stringlist.size());
		ArrayList<Email> emaillist =new ArrayList<Email>(); 
		System.out.println(emaillist.isEmpty());
		System.out.println(emaillist.size());


		
	}
}