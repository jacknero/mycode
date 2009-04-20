import java.util.*;
import java.math.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            String line = sc.nextLine();
            BigInteger input = new BigInteger(line.substring(2),8);
            BigDecimal d = new BigDecimal(input);
            for(int i=0;i<line.length()-2;i++){
                d = d.divide(new BigDecimal(8));
            }
            System.out.println(line + " [8] = " + d + " [10]");
        }
    }
}