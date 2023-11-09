package kr.ac.sejong.kmooce.data_engineering_hashmap;

import java.util.HashMap;

import kr.ac.sejong.kmooc.data_engineering.Email;

public class HashMapExample5 {
	public static void main(String[] args) {
		HashMap<Integer, Integer> map= new HashMap<Integer, Integer>(1);
		for(int i=0;i<1000;i++) {
			map.put(i,i);
		}
		System.out.println(map);
	}
}
