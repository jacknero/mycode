public class Main {

public static void main(String[] args) {

Scanner scanner = new Scanner(System.in);

String key = scanner.nextLine();
String s = scanner.nextLine();
dec(key, s);

}

static void dec(final String k, String s) {

class Dec {

char dec(final char c) {
boolean isUpp = Character.isUpperCase(c);
char c2 = Character.toLowerCase(c);
if (!('a' <= c2 && c2 <= 'z'))
return c;
int idx = (int) ((int) c2 - (int) 'a');
char d = k.charAt(idx);
if (isUpp)
return Character.toUpperCase(d);
return d;
}
}
Dec dec = new Dec();
char[] cs2 = s.toCharArray();
for (int i = 0; i < cs2.length; i++) {
System.out.print(dec.dec(cs2[i]));
}

}
}