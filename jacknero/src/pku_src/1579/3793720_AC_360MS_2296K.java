import java.util.Scanner;

public class Main {

public static void main(String[] args) {

int i, j, k;
int a, b, c;
int[][][] w = new int[21][21][21];
for (i = 0; i < 21; i++) {
for (j = 0; j < 21; j++) {
w[0][i][j] = w[i][0][j] = w[i][j][0] = 1;
}
}
for (i = 1; i <= 20; i++) {
for (j = 1; j <= 20; j++) {
for (k = 1; k <= 20; k++) {
if (i < j && j < k) {
w[i][j][k] += w[i][j][k - 1] + w[i][j - 1][k - 1]
- w[i][j - 1][k];

} else {
w[i][j][k] += w[i - 1][j][k] + w[i - 1][j - 1][k]
+ w[i - 1][j][k - 1] - w[i - 1][j - 1][k - 1];
}
}
}
}
Scanner scanner = new Scanner(System.in);

while (true) {

a = scanner.nextInt();
b = scanner.nextInt();
c = scanner.nextInt();

if (a == b && b == c && c == -1)
break;

i = a;
j = b;
k = c;

if (a <= 0 || b <= 0 || c <= 0) {
i = j = k = 0;
} else if (a > 20 || b > 20 || c > 20) {
i = j = k = 20;
}
System.out.printf("w(%d, %d, %d) = %d%n", a, b, c, w[i][j][k]);

}

}

}