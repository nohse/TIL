package kr.kmooc.dataEngineering.homework4_5;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Set;

public class MyHashSet<E> implements Set<E>{
	
	private LinkedList<E>[] hashTable;
	private int size;
	private int capacity;
	public MyHashSet() {
		capacity=4096;
		size=0;
		hashTable=new LinkedList[capacity];
		for(int i=0;i<capacity;i++) {
			hashTable[i]=new LinkedList<E>();
		}
	}
	public MyHashSet(int capacity) {
		this.capacity=capacity;
		size=0;
		hashTable=new LinkedList[capacity];
		for(int i=0;i<capacity;i++) {
			hashTable[i]=new LinkedList<E>();
		}
	}
	public MyHashSet(Collection<? extends E>c) {
		this();
		
		for(E val:c) {
			this.add(val);
		}
	}
	@Override
	public String toString() {
		if(size==0)
			return "[]";
		String result="[";
		
		Iterator<E> iterator=this.iterator();
		result+=iterator.next();
		
		while(iterator.hasNext()) {
			result+=","+iterator.next();
		}
		result+="]";
		return result;
	}
	
	@Override
	public int size() {
		return size;
	}

	@Override
	public boolean isEmpty() {
		return size==0;
	}

	@Override
	public boolean contains(Object o) {
		int idx=o.hashCode()%capacity;
		LinkedList<E> list= hashTable[idx];
		return list.contains(o);
	}

	@Override
	public Iterator<E> iterator() {
		return new MyHashSetIterator<E>(hashTable);
	}

	@Override
	public Object[] toArray() {
		Object[] array=new Object[size];
		int idx=0;
		for(Object val:this) {
			array[idx++]=val;	
		}
		return array;
	}
	

	@Override
	public <T> T[] toArray(T[] a) {
		if (a.length<size) {
			a=(T[])Array.newInstance(a.getClass().componentType(),size);
		}
		int idx=0;
		for(Object val:this) {
			a[idx++]=(T)val;	
		} 
		return a;
	}

	@Override
	public boolean add(E e) {
		int idx=e.hashCode()%capacity;
		LinkedList<E> list= hashTable[idx];
		if(!list.contains(e)) {
			 list.add(e);
			 size++;
			 return true;
		}else {
			return false;
		}
	}

	@Override
	public boolean remove(Object o) {
		int idx=o.hashCode()%capacity;
		LinkedList<E> list=hashTable[idx];
		boolean isRemoved=list.remove(o);
		if(isRemoved)
			size--;
		return isRemoved;
	}

	@Override
	public boolean containsAll(Collection<?> c) {
		for(Object val:c) {
			if(!this.contains(val))
				return false;
		}
		return true;
	}

	@Override
	public boolean addAll(Collection<? extends E> c) {
		boolean isChanged=false;
		for(E instance:c) {
			 if(this.add(instance))
				 isChanged=true;
		}
		return false;
	}
	

	@Override
	public boolean retainAll(Collection<?> c) {
		ArrayList<E> retainList=new ArrayList<E>();
		boolean isChanged=false;
		for(E val:this) {
			if(c.contains(val)) {
				retainList.add(val);
			}else {
				isChanged=true;
			}
		}
		this.clear();
		for(E val:retainList) {
			this.add(val);
		}
		
		return isChanged;
	}
	

	@Override
	public boolean removeAll(Collection<?> c) {
		boolean isChanged=false;
		for(Object val:c) {
			if(this.contains(val)) {
				this.remove(val);
				isChanged=true;
			}
		}
		return isChanged;
	}

	@Override
	public void clear() {
		hashTable=new LinkedList[capacity];
		for(int i=0;i<capacity;i++) {
			hashTable[i]=new LinkedList<E>();
		}
		size=0;
		
	}

}
