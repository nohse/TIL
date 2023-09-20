package kr.ac.sejong.kmooc.data_engineering;

import java.util.ArrayList;
import java.util.Collection;

public class ArrayListExample3 {
	public static void main(String[] args) {
		ArrayList<Integer> l=new ArrayList<Integer>();
		l.add(0,3);
		l.add(1,9);
		l.add(2,5);
		l.add(3,7);
		System.out.println(l);
		System.out.println(l.contains(3));

		ArrayList<Email> emails=new ArrayList<Email>();
		emails.add(new Email(0,0));
		emails.add(new Email(0,1));
		emails.add(new Email(2,2));
		System.out.println(emails);
		System.out.println(emails.contains(new Email(0,1)));
	}
}