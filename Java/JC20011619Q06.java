
class Parent {

   // private methods are not overridden

   protected void m1()

   {

          System.out.println("From parent m1()");

   }

 

   protected void m2()

   {

          m1();

          System.out.println("From parent m2()");

   }

}

 

class Child extends Parent {

   public // new m1() method
//
//   // unique to Child class
//
   void m1()

   {

          System.out.println("From child m1()");

   }

 

   // overriding method

   // with more accessibility

   @Override public void m2()

   {

          super.m1();

          System.out.println("From child m2()");

   }

}

 

//Driver class

class JC20011619Q06 {

   public static void main(String[] args)

   {
	   	  System.out.println("20011619노성현");
          Parent obj1 = new Parent();

          obj1.m2();

          Parent obj2 = new Child();

          obj2.m2();

   }

}