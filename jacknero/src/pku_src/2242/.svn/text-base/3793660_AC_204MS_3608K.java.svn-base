import java.util.Scanner;

public class Main {

public static void main(String[] args) {

Scanner scanner = new Scanner(System.in);
while (scanner.hasNext()) {
double x1 = scanner.nextDouble();
double y1 = scanner.nextDouble();
double x2 = scanner.nextDouble();
double y2 = scanner.nextDouble();
double x3 = scanner.nextDouble();
double y3 = scanner.nextDouble();
System.out.printf("%.2f%n", circumradius(x1, y1, x2, y2, x3, y3));
}

}

static double distance(double x1, double y1, double x2, double y2) {
return Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
}

static double circumradius(double x1, double y1, double x2, double y2,
double x3, double y3) {
double a = distance(x1, y1, x2, y2);
double b = distance(x2, y2, x3, y3);
double c = distance(x3, y3, x1, y1);

double A = a * b * c;
double E1 = a + b + c;
double E2 = -a + b + c;
double E3 = a - b + c;
double E4 = a + b - c;
double B = A / Math.sqrt(E1 * E2 * E3 * E4);

return B * 2 * Math.PI;
}
}