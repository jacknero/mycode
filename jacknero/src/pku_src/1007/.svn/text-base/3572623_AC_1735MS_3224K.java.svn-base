import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), m = sc.nextInt();
		TreeMap<Integer, String> dna = new TreeMap<Integer, String>();
		for (int i = 0; i < m; i++) {
			int v = 0;
			String s = sc.next();
			for (int j = 0; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					if (s.charAt(j) > s.charAt(k)) ++v;
				}
			}
			dna.put(v * m + i, s);
		}
		Iterator it = dna.keySet().iterator();
		while (it.hasNext()) {
			System.out.println(dna.get(it.next()));
		}
	}
}
