package kr.kmooc.dataEngineering.homework2_3;

import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;
import java.util.NoSuchElementException;
import java.util.Queue;

public class MyLinkedList<E> implements List<E>, Queue<E>{

	private MyNode<E> first;
	private MyNode<E> last;
	private int size=0;
	
	public MyLinkedList() {
		first =null;
		last=null;
		size=0;
	}
	public MyLinkedList(Collection<? extends E> c) {
		this();
		for(E value:c) {
			add(value);
		}
	}

	@Override
	public E element() {
		if(size==0) {
			throw new NoSuchElementException();
		}
		else {
			return get(0);
		}
	}

	@Override
	public boolean offer(E e) {
		if(first==null) {
			//비어 있을 때
				
				MyNode<E> newNode=new MyNode<E>(null, e,null);
				first=newNode;
				last=newNode;
				size++;
			}else {
				//비어 있지 않을 때
				MyNode<E> newNode=new MyNode<E>(last,e,null);
				last.setNext(newNode);
				last=newNode;
			size++;
		}
		return true;
	}

	@Override
	public E peek() {
		if(size==0) {
			return null;
		}else {
			return get(0);
		}
	}

	@Override
	public E poll() {
		if(size==0) {
			return null;
		}else {
			return remove(0);
		}
	}

	@Override
	public E remove() {
		if(size==0) {
			throw new NoSuchElementException();
		}else {
			return remove(0);
		}
	}

	@Override
	public boolean add(E e) {
		if(first==null) {
			//비어 있을 때
				
				MyNode<E> newNode=new MyNode<E>(null, e,null);
				first=newNode;
				last=newNode;
				size++;
			}else {
				//비어 있지 않을 때
				MyNode<E> newNode=new MyNode<E>(last,e,null);
				last.setNext(newNode);
				last=newNode;
				size++;
		}
		return true;
	}

	@Override
	public String toString() {
		if(size==0)
			return "[]";
		String result="[";
		result +=first.getItem();
		MyNode<E> cursor=first.getNext();
		while(cursor!=null) {
			result+=", "+cursor.getItem();
			cursor=cursor.getNext();
		}
		result+="]";
		return result;
	}
	@Override
	public void add(int index, E element) {
		  if (index < 0 || index > size) {
		        throw new IndexOutOfBoundsException();
		    }
		  if(size==0) {
			  // 가장 마지막에 추가
			  add(element);
		  }else {
			  //중간에 추가
			  MyNode<E> next= getNode(index);
			  MyNode<E> prev=getNode(index-1);
			  //새로운 노드 추가
			  MyNode<E> newNode= new MyNode<E>(prev,element,next);
			  if(prev!=null) {
				  //처음 위치에 추가하는 것이 아님
				  prev.setNext(newNode);
			  }else {
				  first=newNode;
			  }
			  if(next!=null) {
				  next.setPrev(newNode);
			  }else {
				  last=newNode;
			  }
			  size++;
		  }
	}

	@Override
	public boolean addAll(Collection<? extends E> arg0) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean addAll(int arg0, Collection<? extends E> arg1) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public void clear() {
		while(size!=0) {
			remove(0);
		}
	}

	@Override
	public boolean contains(Object o) {
		if(size()==0)
			return false;
		MyNode<E> cursor=first;
		do {
			if(cursor.getItem().equals(o))
				return true;
			cursor=cursor.getNext();
		}while(cursor!=null);
		return false;
	}

	@Override
	public boolean containsAll(Collection<?> arg0) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public E get(int index) {
		if(index>=size()||index<0)
			throw new IndexOutOfBoundsException("Index "+index+" out of bounds for length "+size);
		int cIdx=0;
		MyNode<E> cursor=first;
		do {
			if(cIdx==index)
				return cursor.getItem();
			cursor=cursor.getNext();
			cIdx++;
		}while(cursor!=null);
		return null;
	}
	public MyNode<E>  getNode(int index) {
		if(index>size()||index<0)
			throw new IndexOutOfBoundsException("Index "+index+" out of bounds for length "+size);
		int cIdx=0;
		MyNode<E> cursor=first;
		do {
			if(cIdx==index)
				return cursor;
			cursor=cursor.getNext();
			cIdx++;
		}while(cursor!=null);
		return null;
	}
	private MyNode<E>  getNode(Object o) {
		int cIdx=0;
		MyNode<E> cursor=first;
		do {
			if(cursor.getItem().equals(o))
				return cursor;
			cursor=cursor.getNext();
			cIdx++;
		}while(cursor!=null);
		return null;
	}

	@Override
	public int indexOf(Object o) {
		int cIdx=0;
		MyNode<E> cursor=first;
		do {
			if(cursor.getItem().equals(o))
				return cIdx;
			cursor=cursor.getNext();
			cIdx++;
		}while(cursor!=null);
		return -1;
	}

	@Override
	public boolean isEmpty() {
		return size==0;
	}

	@Override
	public Iterator<E> iterator() {
		return new MyLinkedListListIterator<E>(this, 0);
	}

	@Override
	public int lastIndexOf(Object o) {
		int cIdx=size-1;
		MyNode<E> cursor=last;
		do {
			if(cursor.getItem().equals(o))
				return cIdx;
			cursor=cursor.getPrev();
			cIdx--;
		}while(cursor!=null);
		return -1;
	}

	@Override
	public ListIterator<E> listIterator() {
		return new MyLinkedListListIterator<E>(this, 0);
	}

	@Override
	public ListIterator<E> listIterator(int index) {
		return new MyLinkedListListIterator<E>(this, index);
	}

	@Override
	public boolean remove(Object o) {
		MyNode<E> nodeToRemove=getNode(o);
		if(nodeToRemove==null)
			return false;
		MyNode<E> next=nodeToRemove.getNext();
		MyNode<E> prev=nodeToRemove.getPrev();
		if(prev==null) {
			//nodeToRemove가 first 였음
			first=next;
		}else {
			prev.setNext(next);
		}
		if(next==null) {
			//nodeToRemove가 last였음
			last=prev;
		}else {
			next.setPrev(prev);
		}
		size--;
		return true;
	}

	@Override
	public E remove(int index) {
		MyNode<E> nodeToRemove=getNode(index);
		E element=nodeToRemove.getItem();
		MyNode<E> next=nodeToRemove.getNext();
		MyNode<E> prev=nodeToRemove.getPrev();
		if(prev==null) {
			//nodeToRemove가 first 였음
			first=next;
		}else {
			prev.setNext(next);
		}
		if(next==null) {
			//nodeToRemove가 last였음
			last=prev;
		}else {
			next.setPrev(prev);
		}
		size--;
		return element;
	}

	@Override
	public boolean removeAll(Collection<?> arg0) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean retainAll(Collection<?> arg0) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public E set(int index, E element) {
		MyNode<E> node=getNode(index);
		E previousOne=node.getItem();
		node.setItem(element);
		return previousOne;
	}

	@Override
	public int size() {
		return size;
	}

	@Override
	public List<E> subList(int arg0, int arg1) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Object[] toArray() {
		Object[] array=new Object[size];
		int idx=0;
		for (E val: this) {
			array[idx++]=val;
		}
		return array;
	}

	@Override
	public <T> T[] toArray(T[] arg0) {
		// TODO Auto-generated method stub
		return null;
	}

}
