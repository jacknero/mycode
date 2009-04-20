public class Main {

public static void main(String[] args) {
int t, j;
for (t = 2992; t < 10000; t++) {
int a = 0, b = 0, c = 0;
j = t;
//
a += b(t, 10, 4);
a += b(t, 10, 3);
a += b(t, 10, 2);
a += b(t, 10, 1);
b += b(t, 16, 4);
b += b(t, 16, 3);
b += b(t, 16, 2);
b += b(t, 16, 1);
c += b(t, 12, 4);
c += b(t, 12, 3);
c += b(t, 12, 2);
c += b(t, 12, 1);

if (a == b && b == c)
System.out.println(t);

}
}

static int b(int t, int i, int a) {
int b = 1;
int d = 1;
for (int j = 0; j < a - 1; j++) {
b *= i;
}
d = b * i;

return (int) ((t % d) / b);
}
}