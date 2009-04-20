
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
while (scanner.hasNext()) {
int t = scanner.nextInt();
if (t == 0)
break;

int d = 0;
int u = 0;
int max = 1299709;
for (int i = t; 1 < i; i--) {
if (isPrime(i)) {
d = i;
break;
}
}
for (int i = t; t <= max; i++) {
if (isPrime(i)) {
u = i;
break;
}
}
System.out.println(u - d);
}
}

static boolean isPrime(long n) {
return BigInteger.valueOf(n).isProbablePrime(10);
}
}