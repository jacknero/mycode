import java.util.*;

public class Main {
	public static void main(String args[]) {
		int N = 276;
		double[] dic = new double[N];
		         dic[0] = 0.5;
		for (int i = 1; i < N; i++) {
			dic[i] = dic[i - 1] + 1.0 / (i + 2);
		}
		Scanner sc = new Scanner(System.in);
		while (true) {
			float l = sc.nextFloat();
			if (l == 0.0) break;
			System.out.println((Math.abs(Arrays.binarySearch(dic, l))) + " card(s)");
		}
	}
}
