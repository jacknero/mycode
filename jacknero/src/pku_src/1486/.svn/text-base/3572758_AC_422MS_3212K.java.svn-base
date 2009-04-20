import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int casenum = 0;
        while(true){
            int n = sc.nextInt();
            if(n==0) break;
            casenum++;
            
            Rectangle[] rs = new Rectangle[n];
            for(int i=0;i<n;i++){
                rs[i] = new Rectangle(sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt());
            }
            
            int[] xs = new int[n];
            int[] ys = new int[n];
            for(int i=0;i<n;i++){
                xs[i] = sc.nextInt();
                ys[i] = sc.nextInt();
            }
            
            boolean table[][] = new boolean[n][n];
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    table[i][j] = rs[i].in(xs[j], ys[j]);
                }
            }
            
            boolean determined_i[] = new boolean[n];
            boolean determined_j[] = new boolean[n];
            int ans[] = new int[n];
            Arrays.fill(determined_i, false);
            Arrays.fill(determined_j, false);
            Arrays.fill(ans, -1);
            
            while(true){
                boolean end = true;
                for(int i=0;i<n;i++){
                    if(determined_i[i]) continue;
                    int cnt = 0;
                    int lastj = -1;
                    for(int j=0;j<n;j++){
                        if(determined_j[j]) continue;
                        if(table[i][j]){
                            lastj = j;
                            cnt++;
                        }
                    }
                    if(cnt==1){
                        ans[i] = lastj;
                        determined_i[i] = true;
                        determined_j[lastj] = true;
                        end = false;
                    }
                }
                for(int j=0;j<n;j++){
                    if(determined_j[j]) continue;
                    int cnt = 0;
                    int lasti = -1;
                    for(int i=0;i<n;i++){
                        if(determined_i[i]) continue;
                        if(table[i][j]){
                            lasti = i;
                            cnt++;
                        }
                    }
                    if(cnt==1){
                        ans[lasti] = j;
                        determined_i[lasti] = true;
                        determined_j[j] = true;
                        end = false;
                    }
                }
                if(end) break;
            }
            
            boolean none = true;
            for(int i=0;i<n;i++)
                if(determined_i[i]) none = false;
            
            System.out.printf("Heap %d\r\n",casenum);
            if(none){
                System.out.println("none");
            }
            else{
                for(int i=0;i<n;i++){
                    if(determined_i[i]) System.out.printf("(%c,%d) ", 'A'+i, 1+ans[i]);
                }
                System.out.println();
            }
            System.out.println();
        }
    }
}

class Rectangle{
    int xmin;
    int xmax;
    int ymin;
    int ymax;
    public Rectangle(int xmin, int xmax, int ymin, int ymax) {
        super();
        // TODO Auto-generated constructor stub
        this.xmin = xmin;
        this.xmax = xmax;
        this.ymin = ymin;
        this.ymax = ymax;
    }
    public boolean in(int x, int y){
        return (xmin<x && x<xmax && ymin<y && y<ymax);
    }
}