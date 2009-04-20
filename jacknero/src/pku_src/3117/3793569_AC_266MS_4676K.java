
import java.util.Scanner;

public class Main {
public static void main(String[] args) {

Scanner scanner = new Scanner(System.in);

while (true) {
int t = scanner.nextInt();
int m = scanner.nextInt();
if (t == 0 && m == 0)
break;
int c = 0;
for(int i=0;i<t;i++){
scanner.next();
c += scanner.nextInt();
}
System.out.println((3*m)-c);
}
}
}