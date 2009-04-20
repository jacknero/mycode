import java.util.*;

public class Main {
	public static void main(String args[]) {
		String[] Haab = {
			"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"
		};
		String[] Tzolkin = {
			"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"
		};
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		for (int i = 0; i < Haab.length; i++) {
			map.put(Haab[i], i);
		}
		Scanner sc = new Scanner(System.in).useDelimiter("(\\s|\\.|\\n)+");
		int n = sc.nextInt();
		System.out.println(n);
		for (int i = 0; i < n; ++i) {
			int t = sc.nextInt() + map.get(sc.next()) * 20 + sc.nextInt() * 365;
			System.out.println((t % 13 + 1) + " " + Tzolkin[t % 20] + " " + (t / 260));
		}
	}
}
