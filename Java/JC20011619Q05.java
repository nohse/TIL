class Sample {
	public int a;
	private int b;
	int c;
	
	void putb(int i) {
		b=i;
	}
	int getb() {
		return b;
	}
}

public class JC20011619Q05 {
	public static void main(String[] args) {
		System.out.println("노성현20011619");
		Sample aClass = new Sample();
		aClass.a = 10;
		/*aClass.b = 10;*/
		aClass.putb(10);
		aClass.c = 10;
		System.out.println(aClass.a+" "+aClass.getb()+" "+aClass.c);
	}

}
