import java.util.Scanner;

public class Main {
public static void main(String[] args) {

Scanner scanner = new Scanner(System.in);
int n = scanner.nextInt();
while (0 < n--) {
long r = scanner.nextLong();
c(r);
}
}

static void c(long l) {

if (l == 0 || l % 2 != 0) {
System.out.printf("%d %d%n", l, l);
return;
}
long l2 = l;
long l1 = l;
long r1 = l;
long[] L = { 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096,
8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576,
2097152, 4194304, 8388608, 16777216, 33554432, 67108864,
134217728, 268435456, 536870912, 1073741824, 2147483648L,
4294967296L, 8589934592L, 17179869184L };
int i = 0;
for (; i < L.length - 1; i++) {
l2 = l2 / 2;
if (l2 % 2 != 0) {
break;
}

}

// System.out.println(">>>" + L[i]);
l1 = (l - L[i]) + 1;
r1 = (l + L[i]) - 1;

System.out.printf("%d %d%n", l1, r1);
}

}