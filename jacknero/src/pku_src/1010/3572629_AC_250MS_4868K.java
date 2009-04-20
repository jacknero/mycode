import java.util.*;

class StampSet implements Comparable {
	int[] stamps = new int[4];
	int size = 0, diff = 0, max = 0;
	StampSet(int s0, int s1, int s2, int s3, int diff) {
		this.stamps[0] = s0;
		this.stamps[1] = s1;
		this.stamps[2] = s2;
		this.stamps[3] = s3;
		this.diff = diff;
		for (int i = 0; i < stamps.length; i++) {
			if (stamps[i] != 0) {
				this.size++;
				this.max = Math.max(this.max, stamps[i]);
			}
		}
	}
	public int compareTo(Object o) {
		StampSet other = (StampSet) o;
		if (this.diff != other.diff)
			return other.diff - this.diff;
		if (this.size != other.size)
			return this.size - other.size;
		return other.max - this.max;
	}
	public String toString() {
		String tmp = "";
		for (int i = 0; i < stamps.length; i++)
			if (stamps[i] != 0)
				tmp = tmp.concat(" " + stamps[i]);
		return tmp;
	}
}

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in).useDelimiter("[^0-9]+");
		while (sc.hasNextInt()) {
			ArrayList<Integer> tmp = new ArrayList<Integer>();
			tmp.add(0);
			while (true) {
				int t = sc.nextInt();
				if (t == 0)
					break;
				tmp.add(t);
			}
			Integer[] stamps = tmp.toArray(new Integer[0]);
			while (true) {
				int c = sc.nextInt();
				if (c == 0)
					break;
				StampSet result = null;
				boolean  resaln = true;
				for (int i = 0; i < stamps.length; i++) {
				for (int j = i; j < stamps.length; j++) {
				for (int k = j; k < stamps.length; k++) {
				for (int l = k; l < stamps.length; l++) {
					if (stamps[i] + stamps[j] + stamps[k] + stamps[l] == c) {
						int diff = 0;
						if (i != 0) ++diff; if (j != i) ++diff; if (k != j) ++diff; if (l != k) ++diff;
						StampSet ts = new StampSet(stamps[i], stamps[j], stamps[k], stamps[l], diff);
						if (result == null || result.compareTo(ts) > 0) {
							result = ts;
							resaln = true;
						}
						else if (result.compareTo(ts) == 0) {
							resaln = false;
						}
					}
				} } } }

				if (result != null) {
					System.out.println(c + " (" + result.diff + "):" + (resaln ? result : " tie"));
				}
				else {
					System.out.println(c + " ---- none");
				}
			}
		}
	}
}
