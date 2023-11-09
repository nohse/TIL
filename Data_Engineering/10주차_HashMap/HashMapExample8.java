package kr.ac.sejong.kmooce.data_engineering_hashmap;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map.Entry;
import java.util.Set;

import kr.ac.sejong.kmooc.data_engineering.Email;

public class HashMapExample8 {
	public static void main(String[] args) {
		HashMap<Integer, Integer> map= new HashMap<Integer, Integer>();
		map.put(1,10);
		map.put(3,8);
		map.put(5,6);
		map.put(7,4);
		map.put(9,2 );
		System.out.println(map);
		
		Set<Integer> keySet=map.keySet();
		Iterator<Integer> keyIterator=keySet.iterator();
		
		while(keyIterator.hasNext()) {
			Integer key= keyIterator.next();
			System.out.println(key+" : "+map.get(key));
		}
		
		for(Integer key: keySet) {
			System.out.println(key+" : "+map.get(key));
		}
		
		
		Set<Entry<Integer,Integer>> entrySet=map.entrySet();
		Iterator<Entry<Integer,Integer>> entryiterator= entrySet.iterator();
		
		while(entryiterator.hasNext()) {
			Entry<Integer,Integer> entry=entryiterator.next();
			System.out.println(entry.getKey()+" : "+entry.getValue());
		}
		
		for(Entry<Integer,Integer>entry: map.entrySet()) {
			System.out.println(entry.getKey()+" : "+entry.getValue());
		}
		
		System.out.println(map.values());
	}
}
