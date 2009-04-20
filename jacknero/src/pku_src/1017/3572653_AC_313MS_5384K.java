import java.util.*;

public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        while(true){
            int p1 = sc.nextInt();
            int p2 = sc.nextInt();
            int p3 = sc.nextInt();
            int p4 = sc.nextInt();
            int p5 = sc.nextInt();
            int p6 = sc.nextInt();
            if (p1 + p2 + p3 + p4 + p5 + p6 == 0) break;
            System.out.println(solve(p1, p2, p3, p4, p5, p6));
        }
    }

    private static int solve(int p1, int p2, int p3, int p4, int p5, int p6) {
        // size 6x6
        if (p6 > 0) {
            return p6 + solve(p1, p2, p3, p4, p5, 0);
        }

        // size 5x5
        if (p5 > 0) {
            int rp1 = Math.max(p1 - 11 * p5, 0);
            return p5 + solve(rp1, p2, p3, p4, 0, 0);
        }

        // size 4x4
        if (p4 > 0) {
            int inp2 = Math.min(5 * p4, p2);
            int rp2 = p2 - inp2;
            int inp1 = Math.min(20 * p4 - 4 * inp2, p1);
            int rp1 = p1 - inp1;
            return p4 + solve(rp1, rp2, p3, 0, 0, 0);
        }

        // size 3x3
        if (p3 >= 4) {
            return p3 / 4 + solve(p1, p2, p3 % 4, 0, 0, 0);
        } else if (p3 > 0) {
            int inp2;
            int rp2;
            int inp1;
            int rp1;
            switch (p3) {
            case 3:
                inp2 = Math.min(1, p2);
                rp2 = p2 - inp2;
                inp1 = Math.min(9 - 4 * inp2, p1);
                rp1 = p1 - inp1;
                return 1 + solve(rp1, rp2, 0, 0, 0, 0);
            case 2:
                inp2 = Math.min(3, p2);
                rp2 = p2 - inp2;
                inp1 = Math.min(18 - 4 * inp2, p1);
                rp1 = p1 - inp1;
                return 1 + solve(rp1, rp2, 0, 0, 0, 0);
            default:/* 1 */
                inp2 = Math.min(5, p2);
                rp2 = p2 - inp2;
                inp1 = Math.min(27 - 4 * inp2, p1);
                rp1 = p1 - inp1;
                return 1 + solve(rp1, rp2, 0, 0, 0, 0);
            }
        }

        // size 2x2 1x1
        return ((4 * p2 + p1) + 35) / 36;
    }
}

class Point {
    int x, y;
}

class Solver {
    int m;

    int n;

    int a[][];

    int s[][];

    public Solver(int m, int n, int[][] a) {
        // TODO Auto-generated constructor stub
        this.m = m;
        this.n = n;
        this.a = a;
    }
}