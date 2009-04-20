import java.util.*;
import java.text.*;

class Main{

  public static void main(String s[]){

    Scanner c=new Scanner(System.in);
    double n;
    DecimalFormat d = new DecimalFormat("0.00000000000000");

    for(; (n=c.nextDouble()) > 0;)
    {
      double t = ( n - 2.0 ) * Math.log1p( -1.0 / n );
      n = Math.exp( t ) -5e-15;
      System.out.println(d.format( n ));
    }
  }
}
