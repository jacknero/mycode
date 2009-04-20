import java.math.BigDecimal;
import java.util.*;
public class Main
{
            public static void main(String args[]) throws Exception
            {
                    Scanner cin=new Scanner(System.in);
                    cin.hasNext();
                    BigDecimal a= cin.nextBigDecimal();
					int b=cin.nextInt();
                    a = a.pow(b);
                    System.out.println(a.toPlainString().replaceAll("^0|\\.?0*$",""));
            }
}