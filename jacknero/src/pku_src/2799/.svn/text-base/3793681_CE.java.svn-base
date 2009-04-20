import java.util.Random;
import java.util.Set;
import java.util.TreeSet;

public class CopyOfMain {

public static void main(String[] args) {

M mm = new M();

Set<String> set = new TreeSet<String>() {

private static final long serialVersionUID = 1L;

public String toString() {
return String.format("%s %s", first(), last());
}
};

String[] ss = { "192.168.131.046", "192.168.244.150",
"192.168.001.242", "192.168.255.022" };

// for (String s : ss) {
// mm.add(toInt(toInts(s)));
// set.add(s);
// }

// 192.168.131.046
// 192.168.244.150
// 192.168.001.242
// 192.168.255.022

for (int i = 0; i < 100; i++) {
String s = randomIp();
mm.add(toInt(toInts(s)));
set.add(s);
}

int a = toInt(toInts(mm.s2));
int b = toInt(toInts(mm.s1));

System.out.println(mm);
System.out.println(set);

int m = mask(a, b);

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

// System.out.printf("%d%n%d %n", s1, min(s, s1));
s1 = min(s, s1);

s2 = max(s2, s);

}

int min(int a, int b) {

// System.out.printf("%d %d %s%n", b0(a), b0(b), b0(a) < b0(b));
// System.out.printf("%d %d %s%n", b1(a), b1(b), b1(a) < b1(b));
// System.out.printf("%d %d %s%n", b2(a), b2(b), b2(a) < b2(b));
// System.out.printf("%d %d %s%n", b3(a), b3(b), b3(a) < b3(b));
// System.out.println("-------------------");
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

static String net(int i) {
int b0 = (i >> 24) & 0xff;
int b1 = (i >> 16) & 0xff;
int b2 = (i >> 8) & 0xff;
int b3 = i & 0xff;
return String.format("%03d.%03d.%03d.%03d", b0, b1, b2, b3);
}

public String toString() {
return String.format("%s %s", net(s1), net(s2));
}
}

public static int mask(int a, int b) {
for (int i = 0; i < 32; i++) {
// printB(a >>> i);
if (a >>> i == b >>> i) {
// System.out.println("aaa:" + i);
return 0xffffffff << (i);
}
}
return 0x0;
}

static int toInt(int... b) {
int l = b[0] << 24;
l += b[1] << 16;
l += b[2] << 8;
l += b[3];
return l;
}

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

static int r() {
return new Random().nextInt(256);
}

static String randomIp() {
return String.format("%03d.%03d.%03d.%03d", r(), 168, r(), 10);
}

}