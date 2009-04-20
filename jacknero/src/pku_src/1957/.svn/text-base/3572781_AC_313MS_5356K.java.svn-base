import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        for(int i=0;i<n;i++){
            String seq1 = sc.nextLine();
            String seq2 = sc.nextLine();
            sc.nextLine();
            
            Solver sol = new Solver(seq1,seq2);
            System.out.println(sol.solve());
        }
    }
}

class Solver{
    char[] seq1;
    char[] seq2;
    Solver(String seq1,String seq2){
        this.seq1 = seq1.toCharArray();
        this.seq2 = seq2.toCharArray();
    }
    public boolean solve(){
        Table t1 = new Table(seq1);
        for(int i=0;i<6;i++){
            Table t2 = new Table(seq2);
            if(t1.equals(t2)) return true;
            rotate(seq2);
        }
        return false;
    }
    

    private static void rotate(char[] seq){
        for(int i=0;i<seq.length;i++){
            seq[i]++;
            if(seq[i]>='g') seq[i]-=6;
        }
    }
}

class Table{
    int xsize;
    int ysize;
    boolean[][] egg;
    public Table(char[] seq){
        //decide parameter for initTable
        int x = 0;
        int y = 0;
        int minx = 0;
        int miny = 0;
        int maxx = 0;
        int maxy = 0;
        for(int i=0;i<seq.length;i++){
            switch(seq[i]){
            case 'a':
                x++;y++;break;
            case 'b':
                y++;break;
            case 'c':
                x--;break;
            case 'd':
                x--;y--;break;
            case 'e':
                y--;break;
            case 'f':
                x++;
            }
            if(x<minx) minx = x;
            if(y<miny) miny = y;
            if(x>maxx) maxx = x;
            if(y>maxy) maxy = y;
        }
        int xsize = maxx-minx+1;
        int ysize = maxy-miny+1;
        
        //initialize table for egg arrangement 
        initTable(ysize,xsize);
        //place eggs on egg table
        place(-miny,-minx,seq);
    }
    private void initTable(int ysize,int xsize){
        this.ysize = ysize;
        this.xsize = xsize;
        egg = new boolean[this.ysize][this.xsize];
        for(int i=0;i<this.ysize;i++){
            for(int j=0;j<this.xsize;j++){
                egg[i][j] = false;
            }
        }
    }
    private void place(int iy,int ix,char[] seq){
        egg[iy][ix] = true;
        for(int i=0;i<seq.length;i++){
            switch(seq[i]){
            case 'a':
                ix++;iy++;break;
            case 'b':
                iy++;break;
            case 'c':
                ix--;break;
            case 'd':
                ix--;iy--;break;
            case 'e':
                iy--;break;
            case 'f':
                ix++;
            }
            egg[iy][ix] = true;
        }
    }

    public boolean equals(Object o){
        Table t = (Table)o;
        if(this.ysize!=t.ysize||this.xsize!=t.xsize) return false;
        
        for(int i=0;i<this.ysize;i++){
            for(int j=0;j<this.xsize;j++){
                if(this.egg[i][j]!=t.egg[i][j]) return false;
            }
        }
        return true;
    }
}