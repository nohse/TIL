package kr.kmooc.dataEngineering.homework1;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;
import java.util.Random;

public class Test 
{
    public static void main( String[] args )
    {
    	
    	List<Integer> arrayList = new ArrayList<Integer>();
    	Random r = new Random();
    	for(int i = 0 ; i < 1000 ; i++)
    		arrayList.add(r.nextInt(1000));
    	
    	List<Integer> testArrayList = new ArrayList<Integer>();
    	for(Integer val : arrayList)
    		testArrayList.add(val);
    	
    	List<Integer> yourArrayList = new MyArrayList<Integer>();
    	for(int i = 0 ; i < 1000 ; i++)
    		yourArrayList.add(i, arrayList.get(i)); // add test 
    	boolean isPass = true;
    	
    	System.out.println("size test: " + (testArrayList.size() == yourArrayList.size()));
    	System.out.println("isEmpty test: " + (testArrayList.size() == yourArrayList.size()));
    	
    	for(int i = 0 ; i < testArrayList.size(); i++) {
    		if(!testArrayList.get(i).equals(yourArrayList.get(i))) {
    			isPass = false;
    			break;
    		}
    	}
    	System.out.println("get test : "+ isPass);
    	
    	
    	for(int i = 0 ; i < 100 ; i++) {
    		Integer val = arrayList.get(r.nextInt(1000));
    		if(testArrayList.contains(val) != yourArrayList.contains(val)){
    			isPass = false;
    			break;
    		}			
    	}
    	System.out.println("contains test: " + isPass);
    	isPass =true;
    	for(int i = 0 ; i < 100 ; i++) {
    		if(!testArrayList.remove(i).equals(yourArrayList.remove(i))) {
    			isPass = false;
    			break;
    		}
    	}
    	System.out.println("remove test : " +isPass);
    	
    	
    	Integer value = arrayList.get(r.nextInt(1000));
    	if(testArrayList.indexOf(value) == yourArrayList.indexOf(value))
    		System.out.println("indexOf test : true");
    	else
    		System.out.println("indexOf test : false");

    	if(testArrayList.lastIndexOf(value) == yourArrayList.lastIndexOf(value))
    		System.out.println("lastIndexOf test : true");
    	else
    		System.out.println("lastIndexOf test : false");
	
    			
    	for(int i =0 ; i< testArrayList.size(); i++) {
    		Integer v = r.nextInt(1000);
    		testArrayList.set(i, v);
    		yourArrayList.set(i, v);
    	}
    	Iterator<Integer> listIterator = testArrayList.iterator();
    	Iterator<Integer> yourIterator = yourArrayList.iterator();
    	while(listIterator.hasNext() && yourIterator.hasNext()) {
    		if(!listIterator.next().equals(yourIterator.next())) {
    			isPass = false;
    			break;
    		}
    	}
    	System.out.println("set test: " + isPass);	
    	System.out.println("Iterator test: " + isPass);
    	
    	ListIterator<Integer> listListIterator = testArrayList.listIterator(testArrayList.size());
    	ListIterator<Integer> yourListIterator = yourArrayList.listIterator(yourArrayList.size());
    	isPass = true;
    	while(listListIterator.hasPrevious() && yourListIterator.hasPrevious()) {
    		if(!listListIterator.previous().equals(yourListIterator.previous())) {
    			isPass = false;
    			break;
    		}
    	}
    	System.out.println("listIterator test: " + isPass);
    	
    	Object[] testArray = testArrayList.toArray();
    	Object[] yourArray = yourArrayList.toArray();
    	isPass = true;
    	for(int i = 0 ; i < testArray.length ; i++)
    		if(!testArray[i].equals(yourArray[i])) {
    			isPass = false;
    			break;
    		}
    	System.out.println("toArray test : " + isPass);
    	
    	isPass = true;
    	testArrayList.clear();
    	yourArrayList.clear();
    	
    	if(testArrayList.size() != yourArrayList.size())
    		isPass = false;
    	System.out.println("clear test : " + isPass);
    	
    }
}