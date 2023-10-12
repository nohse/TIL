package util;

public class MyUtil {
	public static void main (String[] args) {

		ReadText rT = new ReadText("num1");
		String line="";
		
		while ((line = rT.readLine()) != null) {
			  System.out.println(line);
		}
	
	}
}
