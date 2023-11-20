package kr.kmooc.dataEngineering.homework4_5;
import java.util.Iterator;
import java.util.LinkedList;

public class MyHashSetIterator<E> implements Iterator<E> {

	private LinkedList<E>[] hashTable;
	private int tableIndex;
	private int listIndex;
	
	public MyHashSetIterator(LinkedList<E>[] hashTable) {
		this.hashTable=hashTable;
		tableIndex=0;
		listIndex=0;
		while(true) {
			try {
				LinkedList<E> list=hashTable[tableIndex];
			}catch(Exception e) {
				tableIndex=-1;
				break;
			}
			try {
				hashTable[tableIndex].get(listIndex);
				break;
			}catch(Exception e) {
				tableIndex++;
				listIndex=0;
			}
		}
	}
	@Override
	public boolean hasNext() {
		return tableIndex!=-1;
	}

	@Override
	public E next() {
		E item=hashTable[tableIndex].get(listIndex++	);
		if(item==null)
			return null;
		while(true) {
			try {
				LinkedList<E> list=hashTable[tableIndex];
			}catch(Exception e) {
				tableIndex=-1;
				break;
			}
			try {
				hashTable[tableIndex].get(listIndex);
				break;
			}catch(Exception e) {
				tableIndex++;
				listIndex=0;
			}
		}
		return item; 
	}

}
