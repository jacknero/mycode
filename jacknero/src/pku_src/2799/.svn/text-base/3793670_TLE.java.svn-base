import java.util.Scanner;

public class Main {

public static void main(String[] args) {

Scanner scanner = new Scanner(System.in);

int n = scanner.nextInt();
scanner.nextLine();

M mm = new M();
while (0 < n--) {
mm.add(toInt(toInts(scanner.nextLine())));
}

int a = mm.s2;
int b = mm.s1;

int m = mask(a, b);

printIPAddress(m & a);
printSubnet(m);
}

static class M {

int s1;
int s2;
boolean isInit = false;

public void add(int s) {
if (!isInit) {
s1 = s;
s2 = s;
isInit = true;
return;
}

s1 = min(s, s1);
s2 = max(s2, s);

}

int min(int a, int b) {

if ((b0(a) != b0(b)))
return b0(a) < b0(b) ? a : b;
if ((b1(a) != b1(b)))
return b1(a) < b1(b) ? a : b;
if ((b2(a) != b2(b)))
return b2(a) < b2(b) ? a : b;
if ((b3(a) != b3(b)))
return b3(a) < b3(b) ? a : b;

return b;
}

int max(int a, int b) {
if ((b0(a) != b0(b)))
return b0(a) < b0(b) ? b : a;
if ((b1(a) != b1(b)))
return b1(a) < b1(b) ? b : a;
if ((b2(a) != b2(b)))
return b2(a) < b2(b) ? b : a;
if ((b3(a) != b3(b)))
return b3(a) < b3(b) ? b : a;

return a;
}

int b0(int i) {
return (i >>> 24) & 0xff;
}

int b1(int i) {
return (i >>> 16) & 0xff;
}

int b2(int i) {
return (i >>> 8) & 0xff;
}

int b3(int i) {
return (i >>> 0) & 0xff;
}

/*
* デバッグ用
*/
static String net(int i) {
int b0 = (i >> 24) & 0xff;
int b1 = (i >> 16) & 0xff;
int b2 = (i >> 8) & 0xff;
int b3 = i & 0xff;
return String.format("%03d.%03d.%03d.%03d", b0, b1, b2, b3);
}

/*
* デバッグ用
*/
public String toString() {
return String.format("%s %s", net(s1), net(s2));
}
}

/**
* <p>
* ネットワークマスクを求めます。
* </p>
*
* @param a
* @param b
* @return
*/
public static int mask(int a, int b) {
for (int i = 0; i < 32; i++) {
if (a >>> i == b >>> i) {
return 0xffffffff << (i);
}
}
return 0x0;
}

/**
* <p>
* intの配列からipアドレスのint表現にします。
* </p>
*
* @param b
* @return
*/
static int toInt(int... b) {
int l = b[0] << 24;
l += b[1] << 16;
l += b[2] << 8;
l += b[3];
return l;
}

/**
* <p>
* サブネットマスクを印字します。
* </p>
*
* @param i
*/
static void printSubnet(int i) {
int b0 = (i >> 24) & 0xff;
int b1 = (i >> 16) & 0xff;
int b2 = (i >> 8) & 0xff;
int b3 = i & 0xff;
System.out.printf("%d.%d.%d.%d%n", b0, b1, b2, b3);
}

/**
* <p>
* ipv4の値をint値にします。
* </p>
*
* @param b0
* @param b1
* @param b2
* @param b3
* @return
*/
static int toInt(int b0, int b1, int b2, int b3) {
int l = b0 << 24;
l += b1 << 16;
l += b2 << 8;
l += b3;
return l;
}

/**
* <p>
* int値からipv4の値を出力します。
* </p>
*
* @param i
*/
static void printIPAddress(int i) {
System.out.println(ipv4(i));
}

/**
* <p>
* int値からxxx.xxx.xxx.xxxの表現にします。
* </p>
*
* @param i
* @return
*/
static String ipv4(int i) {
int b0 = (i >> 24) & 0xff;
int b1 = (i >> 16) & 0xff;
int b2 = (i >> 8) & 0xff;
int b3 = i & 0xff;
return String.format("%d.%d.%d.%d", b0, b1, b2, b3);
}

/**
* <p>
* int値からxxx.xxx.xxx.xxxの表現にします。
* </p>
*
* @param i
* @return
*/
static String ipv4_2(String s) {
String[] ss = s.split("\\.");

int b0 = Integer.parseInt(ss[0]);
int b1 = Integer.parseInt(ss[1]);
int b2 = Integer.parseInt(ss[2]);
int b3 = Integer.parseInt(ss[3]);
return String.format("%03d.%03d.%03d.%03d", b0, b1, b2, b3);
}

/**
* <p>
* ipアドレス表現の文字列からintの配列にします。
* </p>
*
* @param s
* @return
*/
static int[] toInts(String s) {

String[] ss = s.split("\\.");

return new int[] { Integer.parseInt(ss[0]), Integer.parseInt(ss[1]),
Integer.parseInt(ss[2]), Integer.parseInt(ss[3]) };
}

static int[] toInts(int i) {
int b0 = (i >> 24) & 0xff;
int b1 = (i >> 16) & 0xff;
int b2 = (i >> 8) & 0xff;
int b3 = i & 0xff;
return new int[] { b0, b1, b2, b3 };
}

}