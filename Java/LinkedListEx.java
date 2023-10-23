import java.util.*;

/*
class Student { 
	private int id;
	private String name;
	public Student(int id, String n) { this.id = id; this.name = n; }
	public int getId() { return id; }
	public String getName() { return name; }	
}
*/

public class LinkedListEx {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// create LinkedList
	    LinkedList<String> animals = new LinkedList<>();
	    String aName;
	    
	    // Add elements to LinkedList
	    animals.add("Dog");
	    animals.add("Cat");
	    animals.add("Cow");
	    System.out.println("LinkedList: " + animals);
	    
	 // add() method with the index parameter
	    animals.add(1, "Horse");
	    System.out.println("Updated LinkedList: " + animals);
		System.out.println("# of elements in LinkedList= " + animals.size());
		
		aName = animals.get(1);
		System.out.println("Element at index 1: " + aName);
		
		// change element at index 3
		animals.set(3, "Tiger");
		System.out.println("Updated LinkedList: " + animals);
		
	}

}
