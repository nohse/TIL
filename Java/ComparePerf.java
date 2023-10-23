import java.util.*;
import java.time.*;

public class ComparePerf {
	public static void testVector (int iter) {
		int i;
		Vector<Integer> vector = new Vector<>();
		long start1, end1;
		
		//start1 = System.currentTimeMillis();
		start1 = System.nanoTime();
		for (i=0; i < iter; i++) {
			vector.add((int) Math.random() * 1000000);
		}
		//end1 = System.currentTimeMillis();
		end1 = System.nanoTime();
		System.out.println("Elapsed time in nano seconds= " + (end1 - start1));
	}
	
	public static void testArrayList (int iter) {
		int i;
		ArrayList<Integer> array = new ArrayList<>();
		long start1, end1;
		
		//start1 = System.currentTimeMillis();
		start1 = System.nanoTime();
		for (i=0; i < iter; i++) {
			array.add((int) Math.random() * 1000000);
		}
		//end1 = System.currentTimeMillis();
		end1 = System.nanoTime();
		System.out.println("Elapsed time in nano seconds= " + (end1 - start1));
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		testVector(10000000);
		testArrayList(10000000);
	}

}
