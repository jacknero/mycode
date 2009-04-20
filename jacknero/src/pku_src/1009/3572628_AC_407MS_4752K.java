import java.util.*;

class Output {
	int v = -1, l = 0;
	void set(int v, int l) {
		if (this.v == v) {
			this.l += l;
			return;
		}
		if (this.v != -1) {
			System.out.println(this.v + " " + this.l);
		}
		this.v = v;
		this.l = l;
	}
}

class RLE {
	public class Pair {
		int value, length;
		Pair (int value, int length) {
			this.value = value;
			this.length = length;
		}
	}
	public class Pixel {
		int pos = 0, cur = 0;
		int getLength() {
			return rle.get(pos).length - cur;
		}
		int get() {
			return rle.get(pos).value;
		}
		int prev() {
			if (pos <= 0) {
				return -1;
			}
			else if (cur == 0) {
				return rle.get(pos - 1).value;
			}
			else {
				return rle.get(pos).value;
			}
		}
		int next() {
			if (pos >= rle.size() - 1) {
				return -1;
			}
			else if (getLength() == 1) {
				return rle.get(pos + 1).value;
			}
			else {
				return rle.get(pos).value;
			}
		}
		void move(int dis) {
			while (pos < rle.size()) {
				int tmp = getLength();
				if (dis < tmp) {
					break;
				}
				dis -= tmp;
				++pos;
				cur = 0;
			}
			cur += dis;
		}
	}
	ArrayList<Pair> rle;
	RLE () {
		rle = new ArrayList<Pair>();
	}
	void add(int v, int l) {
		rle.add(new Pair(v, l));
	}
	Pixel getPixel(int d) {
		Pixel r = new Pixel();
		         r.move(d);
		return r;
	}
}

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		while (true) {
			int width = sc.nextInt();
			if (width == 0)
				break;
			System.out.println(width);
			RLE img = new RLE();
			img.add(-1, width);
			while (true) {
				int v = sc.nextInt(), l = sc.nextInt();
				if (v == 0 && l == 0)
					break;
				img.add(v, l);
			}
			img.add(-1, width);
			Output out = new Output();
			RLE.Pixel[] p = new RLE.Pixel[3];
			for (int i = 0; i < 3; i++) {
				p[i] = img.getPixel(width * i);
			}
			int x = 0;
			while (true) {
				int home = p[1].get();
				if (home == -1) {
					break;
				}
				int[][] cache = new int[3][3];
				for (int i = 0; i < 3; ++i) {
					int[] tmp = { p[i].prev(), p[i].get(), p[i].next() };
					for (int j = 0; j < 3; ++j) {
						cache[i][j] = (tmp[j] == -1) ? 0 : Math.abs(home - tmp[j]);
					}
				}
				int res = 0;
				if (x > 0) {
					for (int i = 0; i < 3; ++i) {
						res = Math.max(res, cache[i][0]);
					}
				}
				res = Math.max(Math.max(res, cache[0][1]), cache[2][1]);
				if (x < width - 1) {
					for (int i = 0; i < 3; ++i) {
						res = Math.max(res, cache[i][2]);
					}
				}
				int skip = 1000000000;
				for (int i = 0; i < 3; ++i) {
					skip = Math.min(skip, p[i].getLength());
				}
				skip = (p[0].cur > 0 && p[1].cur > 0 && p[2].cur > 0 && skip > 2) ? skip - 1 : 1;
				out.set(res, skip);
				for (int i = 0; i < 3; ++i) {
					p[i].move(skip);
				}
				x = (x + skip) % width;
			}
			out.set(-1, 0);
			System.out.println("0 0");
		}
		System.out.println("0");
	}
}
