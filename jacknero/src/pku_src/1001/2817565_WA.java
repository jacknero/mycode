import java.math.BigDecimal;
import java.util.*;
public class Main
{
            public static void main(String args[]) throws Exception
            {
                    Scanner cin=new Scanner(System.in);
                    BigDecimal a= new BigDecimal(cin.nextDouble());
					int b=cin.nextInt();
                    a = a.pow(b);
                    String c  = a.toPlainString().replaceAll("^0|\\.?0*$", "");
                    System.out.println(c);
            }
}