import java.util.*;

public class Main {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        for(int i=0;i<m;i++){
            int f = sc.nextInt();
            int y = sc.nextInt();
            int n = sc.nextInt();
            int max = Integer.MIN_VALUE;
            for(int j=0;j<n;j++){
                int mode = sc.nextInt();
                double r = sc.nextDouble();
                int c = sc.nextInt();
                if(mode==0) max = Math.max(max, single(f, y, r, c));
                else max = Math.max(max, compound(f, y, r, c));
            }
            System.out.println(max);
        }
    }
    private static int single(int a, int year, double ratio, int charge){
        int interest = 0;
        for(int i=0;i<year;i++){
            interest += a * ratio;
            a -= charge;
        }
        return a + interest;
    }
    private static int compound(int a, int year, double ratio, int charge){
        if(year==0) return a;
        else return compound(a + (int)(a * ratio) - charge, year - 1, ratio, charge);
    }
}