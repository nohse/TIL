package kr.kmooc.dataEngineering.homework2_3;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;
import java.util.Queue;
import java.util.Random;


/**
 * Hello world!
 *
 */
public class Test 
{
    public static void main( String[] args )
    {
    	System.out.println("<Assignment 2-3>");
    	List<Integer> arrayList = new ArrayList<Integer>();
    	Random r = new Random();
    	for(int i = 0 ; i < 1000 ; i++)
    		arrayList.add(r.nextInt(1000));
    	
    	LinkedList<Integer> testLinkedList = new LinkedList<Integer>();
    	for(Integer val : arrayList)
    		testLinkedList.add(val);
    	
    	List<Integer> yourLinkedList = new MyLinkedList<Integer>();
    	for(int i = 0 ; i < 1000 ; i++)
    		yourLinkedList.add(i,arrayList.get(i)); // add test 
    	boolean isPass = true;
    	
    	System.out.println("size test: " + (testLinkedList.size() == yourLinkedList.size()));
    	System.out.println("isEmpty test: " + (testLinkedList.size() == yourLinkedList.size()));
    	
    	for(int i = 0 ; i < testLinkedList.size(); i++) {
    		if(!testLinkedList.get(i).equals(yourLinkedList.get(i))) {
    			isPass = false;
    			break;
    		}
    	}
    	System.out.println("get test : "+ isPass);
    	
    	
    	for(int i = 0 ; i < 100 ; i++) {
    		Integer val = arrayList.get(r.nextInt(1000));
    		if(testLinkedList.contains(val) != yourLinkedList.contains(val)){
    			isPass = false;
    			break;
    		}			
    	}
    	System.out.println("contains test: " + isPass);
    	isPass =true;
    	for(int i = 0 ; i < 100 ; i++) {
    		if(!testLinkedList.remove(i).equals(yourLinkedList.remove(i))) {
    			isPass = false;
    			break;
    		}
    	}
    	System.out.println("remove test : " +isPass);
    	
    	
    	Integer value = arrayList.get(r.nextInt(1000));
    	if(testLinkedList.indexOf(value) == yourLinkedList.indexOf(value))
    		System.out.println("indexOf test : true");
    	else
    		System.out.println("indexOf test : false");

    	if(testLinkedList.lastIndexOf(value) == yourLinkedList.lastIndexOf(value))
    		System.out.println("lastIndexOf test : true");
    	else
    		System.out.println("lastIndexOf test : false");
	
    			
    	for(int i =0 ; i< testLinkedList.size(); i++) {
    		Integer v = r.nextInt(1000);
    		testLinkedList.set(i, v);
    		yourLinkedList.set(i, v);
    	}
   	
    	Iterator<Integer> listIterator = testLinkedList.iterator();
    	Iterator<Integer> yourIterator = yourLinkedList.iterator();
    	while(listIterator.hasNext() && yourIterator.hasNext()) {
    		if(!listIterator.next().equals(yourIterator.next())) {
    			isPass = false;
    			break;
    		}
    	}
    	System.out.println("set test : " + isPass);	
    	System.out.println("Iterator test: " + isPass);
    	
    	ListIterator<Integer> listListIterator = testLinkedList.listIterator(testLinkedList.size());
    	ListIterator<Integer> yourListIterator = yourLinkedList.listIterator(yourLinkedList.size());
    	isPass = true;
    	while(listListIterator.hasPrevious() && yourListIterator.hasPrevious()) {
    		if(!listListIterator.previous().equals(yourListIterator.previous())) {
    			isPass = false;
    			break;
    		}
    	}
    	System.out.println("listIterator test: " + isPass);
    	Object[] testArray = testLinkedList.toArray();
    	Object[] yourArray = yourLinkedList.toArray();
    	isPass = true;
    	for(int i = 0 ; i < testArray.length ; i++)
    		if(!testArray[i].equals(yourArray[i])) {
    			isPass = false;
    			break;
    		}
    	System.out.println("toArray test : " + isPass);
    
        isPass = true;
    	testLinkedList.clear();
    	yourLinkedList.clear();
    	
    	Queue<Integer> testQueue = new LinkedList<>(testLinkedList);
        Queue<Integer> yourQueue = new MyLinkedList<>(yourLinkedList);
        
    	if(testLinkedList.size() != yourLinkedList.size())
    		isPass = false;
    	System.out.println("clear test : " + isPass);
       
    	System.out.println("<Queue Test>");
        Integer val = r.nextInt();
        testQueue.offer(val);
        yourQueue.offer(val);
        val = r.nextInt();
        testQueue.offer(val);
        yourQueue.offer(val);
        
        try {
			System.out.println("remove test : "+ testQueue.remove().equals(yourQueue.remove()) );
		} catch (Exception e) {
			System.out.println("remove test : false");
		}
    	System.out.println("poll test : " + testQueue.poll().equals(yourQueue.poll()));
        try {
        	System.out.println("element test: "+ testQueue.element().equals(yourQueue.element()) );
    			
        }catch(Exception e){
        	System.out.println("element test: true");
        }
        if(testQueue.peek() == null && yourQueue.peek() == null)
        	System.out.println("peek test : true");
        else 
        	System.out.println("peek test : false");
        

    }
}
