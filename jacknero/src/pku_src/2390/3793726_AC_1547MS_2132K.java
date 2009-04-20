import java.util.Scanner;

public class Main {
public static void main(String[] args) {
// R, M, and Y
Scanner scanner = new Scanner(System.in);
int R = scanner.nextInt();
long M = scanner.nextLong();
int Y = scanner.nextInt();
int pos = 0;
double r = 1 + (R / 100.0);
double a = M;
while (pos++ < Y) {
a = a * r;
}
System.out.println((long)Math.floor(a));
}

}