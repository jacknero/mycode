import java.util.*;
public class Main
{
            public static void main(String args[]) throws Exception
            {
                    Scanner cin=new Scanner(System.in);
                    double a=cin.nextDouble(),b=cin.nextInt();
                    double c=a;
                    for(int i = 0; i < b; i++){
                    	a *= a;
                    }
                    System.out.println(c);
            }
}