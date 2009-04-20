import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int c = 0;
		while (true) {
			int p = sc.nextInt() % 23, e = sc.nextInt() % 28, i = sc.nextInt() % 33, d = sc.nextInt();
			if (p == -1 && e == -1 && i == -1 && d == -1)
				break;
			while (p != e) {
				if (p > e)
					e += 28;
				else
					p += 23;
			}
			while (p != i) {
				if (p > i)
					i += 33;
				else
					p += 644;
			}
			while (d - p >= 0)
				p += 21252;
			System.out.println("Case " + (++c) + ": the next triple peak occurs in " + (p - d) + " days.");
		}
	}
}
