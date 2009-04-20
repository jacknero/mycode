import java.math.BigInteger;
import java.util.Scanner;

public class Main {

public static void main(String[] args) {

Scanner scanner = new Scanner(System.in);
while (scanner.hasNext()) {
int radix = scanner.nextInt();
if(radix==0)break;
String m = scanner.next();
String p = scanner.next();
b(m, p, radix);
}
}

static void b(String mm, String pp, int radix) {

BigInteger m = new BigInteger(mm, radix);
BigInteger p = new BigInteger(pp, radix);
// System.out.println(m.mod(p));
System.out.println(m.mod(p).toString(radix));

}

}