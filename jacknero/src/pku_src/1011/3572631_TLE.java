import java.util.*;

class Sticks {
	int n, c = 0, sum = 0;
	int[] sticks;
	boolean[] used;
	Sticks(int n) {
		this.n  = n;
		sticks  = new int[n];
		used    = new boolean[n + 1];
		used[n] = false;
	}
	void add(int l) {
		sum      += l;
		sticks[c] = l;
		used[c++] = false;
	}
	void sort() {
		Arrays.sort(sticks);
	}
	boolean search(int rest, int i, int len, int count) {
		if (rest == 0) {
			return check(len, count - 1);
		}
		// 最後まで行くと失敗
		if (i == n) {
			return false;
		}
		// i番目が使え、長さに収まる
		else if (!used[i] && sticks[i] <= rest) {
			used[i] = true;
			if (search(rest - sticks[i], i + 1, len, count)) {
				return true;
			}
			used[i] = false;
		}
		// 次に使えそうな奴を調べる
		while (used[++i]);
		return i == n ? false : search(rest, i, len, count);
	}
	boolean check(int len, int count) {
		// 残り本数が0なら完了
		if (count == 0) {
			return true;
		}
		// 次に使える候補を探す
		int i = -1;
		while (used[++i]);
		used[i] = true;
		if (search(len - sticks[i], i + 1, len, count)) {
			return true;
		}
		used[i] = false;
		return false;
	}
	public String toString() {
		int len;
		// 最大から合計値が候補
		for (len = sticks[n - 1]; len <= sum; len++) {
			if (sum % len == 0 && check(len, sum / len))
				break;
		}
		return "" + len;
	}
}

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		while (true) {
			int n = sc.nextInt();
			if (n == 0)
				break;
			int total = 0;
			Sticks sticks = new Sticks(n);
			for (int i = 0; i < n; i++) {
				sticks.add(sc.nextInt());
			}
			sticks.sort();
			System.out.println(sticks);
		}
	}
}
