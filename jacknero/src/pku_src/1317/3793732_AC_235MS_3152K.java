import java.util.Scanner;

public class Main {

public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
while (true) {
int k = scanner.nextInt();
if (k == 0)
break;
String line = scanner.next();
char[] cs = line.toCharArray();

int[] cc = new int[cs.length];
for (int i = 0; i < cs.length; i++) {
cc[i] = a(cs[i]);
}
int[] pc = decrypt(k, cc);
for (int i : pc) {
System.out.print(b(i));
}
System.out.println();

}

}

static int[] crypt(int k, int[] pc) {

int[] cc = new int[pc.length];
int n = pc.length;
for (int i = 0; i < pc.length; i++) {
cc[i] = i == 0 ? pc[0] : (pc[(k * i) % n] - i) % 28;
}

return cc;
}

static int[] decrypt(int k, int[] cc) {

int[] pc = new int[cc.length];
int n = pc.length;

for (int i = 0; i < pc.length; i++) {
pc[(k * i) % n] = (cc[i] + i) % 28;
}

return pc;
}

static int a(char c) {

if (c == '_') {
return 0;
}

if (c == '.') {
return 27;
}

if ('a' <= c && c <= 'z') {
return c - 'a' + 1;
}

return c;
}

static char b(int c) {

if (c == 0) {
return '_';
}

if (c == 27) {
return '.';
}

if (1 <= c && c <= 26) {
return (char) ((c - 1) + 'a');
}

return (char) c;
}
}