import java.text.DecimalFormat;
import java.util.Scanner;

public class Main {

public static void main(String[] args) {

Scanner scanner = new Scanner(System.in);
int N = scanner.nextInt();
while (0 < N--) {
int c = scanner.nextInt();
int a = 0;
int[] is = new int[c];
for (int i = 0; i < c; i++) {
is[i] = scanner.nextInt();
a += is[i];
}
a(a, is);

}
}

static void a(int a, int[] is) {
int len = is.length;
int ave = a /= len;
int c = 0;
for (int i : is) {
c += ave < i ? 1 : 0;
}
double d = ((c * 1.) / (len * 1.)) * 100;
DecimalFormat format = new DecimalFormat("#0.000");
System.out.println(format.format(d) + "%");
}
}