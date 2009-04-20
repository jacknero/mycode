import java.util.Scanner;

public class Main {

public static void main(String[] args) {

Scanner scanner = new Scanner(System.in);

while (scanner.hasNext()) {
int n = scanner.nextInt();
int k = scanner.nextInt();
System.out.println(f(n,k));
}
}


static long f(int n, int k){

long sum = n;
int a = n;
for(;k <= a;){

sum += a / k;
a = (a / k) + (a % k);
}
return sum;
}
}