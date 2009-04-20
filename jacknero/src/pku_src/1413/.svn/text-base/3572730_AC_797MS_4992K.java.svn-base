import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        double p[] = new double[9];
        for(int i=0;i<=8;i++) p[i] = prob(i);

        int n = sc.nextInt();
        sc.nextLine();
        for(int i=0;i<n;i++){
            String line = sc.nextLine();
            int marked = (line.indexOf('*')-5)/5;
            int table[][] = new int[4][4];
            int q[][] = new int[2][2];
            int qcnt = 0;
            for(int j=0;j<4;j++){
                line = sc.nextLine();
                for(int k=j+1;k<4;k++){
                    char ca = line.charAt(6+5*k);
                    char cb = line.charAt(8+5*k);
                    if(ca=='_'&&cb=='_'){
                        q[qcnt][0] = j;
                        q[qcnt][1] = k;
                        qcnt++;
                    }
                    else{
                        table[j][k] = ca-'0';
                        table[k][j] = cb-'0';
                    }
                }
            }
            
            double ret = 0.0;
            for(int j=0;j<=8;j++){
                table[q[0][0]][q[0][1]] = j;
                for(int k=0;k<=8;k++){
                    table[q[0][1]][q[0][0]] = k;
                    for(int l=0;l<=8;l++){
                        table[q[1][0]][q[1][1]] = l;
                        for(int m=0;m<=8;m++){
                            table[q[1][1]][q[1][0]] = m;
                            Solver sol = new Solver(table);
                            ret += p[j]*p[k]*p[l]*p[m]*sol.win(marked);
                        }
                    }
                }
            }
            
            System.out.printf("%.7f\r\n",ret);
        }
    }
    private static double prob(int p){
        return (fact(8)/(fact(p)*fact(8-p)))*(exp3(8-p)/65536.0);
    }
    private static double fact(int n){
        int ret = 1;
        while(n>1){
            ret *= n;
            n--;
        }
        return (double)ret;
    }
    private static double exp3(int n){
        int ret = 1;
        while(n>0){
            ret *= 3;
            n--;
        }
        return (double)ret;
    }
}

class Solver{
    int[][] table;
    boolean locmask[];
    int locmaskc;
    boolean mask[];
    int maskc;
    int point[];
    int pmax;
    int pmaxcnt;
    int rest;
    Solver(int[][] table) {
        this.table = table;
        
        locmask = new boolean[4];
        mask = new boolean[4];
        point = new int[4];
    }
    
    public double win(int n){
        for(int i=0;i<4;i++) locmask[i] = true;
        locmaskc = 4;
        rest = 2;
        
        while(true){
            // load previous local mask to grobal mask
            for(int i=0;i<4;i++) mask[i] = locmask[i];
            maskc = locmaskc;
            
            // PHASE A,D
            calcpointA();
            double ret = calcret(n);
            if(ret>=0.0) return ret;
            
            //PHASE B,E
            calcpointB();
            ret = calcret(n);
            if(ret>=0.0) return ret;
            
            //PHASE C,F
            calcpointC();
            ret = calcret(n);
            if(ret>=0.0) return ret;
            
            if(locmaskc==maskc) return (double)rest/(double)maskc;
        }
    }

    private void calcpmax() {
        pmax = Integer.MIN_VALUE;
        pmaxcnt = 0;
        for(int i=0;i<4;i++){
            if(point[i]>pmax) pmax = point[i];
        }
        for(int i=0;i<4;i++){
            if(point[i]==pmax) pmaxcnt++;
        }
    }

    private void calcpointC() {
        for(int i=0;i<4;i++) point[i] = Integer.MIN_VALUE;
        for(int i=0;i<4;i++){
            if(!locmask[i]) continue;
            point[i] = 0;
            for(int j=0;j<4;j++){
                if(i==j||!mask[j]) continue;
                point[i] += table[i][j];
            }
        }
    }

    private void calcpointB() {
        for(int i=0;i<4;i++) point[i] = Integer.MIN_VALUE;
        for(int i=0;i<4;i++){
            if(!locmask[i]) continue;
            point[i] = 0;
            for(int j=0;j<4;j++){
                if(i==j||!mask[j]) continue;
                point[i] += table[i][j]-table[j][i];
            }
        }
    }

    private void calcpointA() {
        for(int i=0;i<4;i++) point[i] = Integer.MIN_VALUE;
        for(int i=0;i<4;i++){
            if(!locmask[i]) continue;
            point[i] = 0;
            for(int j=0;j<4;j++){
                if(i==j||!mask[j]) continue;
                if(table[i][j]>table[j][i]) point[i] += 3;
                else if(table[i][j]==table[j][i]) point[i] += 1;
            }
        }
    }
    
    private double calcret(int n){
        calcpmax();
        if(rest==2){
            if(pmaxcnt==1){
                if(point[n]==pmax) return 1.0;
                else{
                    rest = 1;
                    for(int i=0;i<4;i++){
                        if(point[i]==pmax){
                            locmask[i] = false;
                            point[i] = Integer.MIN_VALUE;
                        }
                    }
                    return calcret(n);
                }
            }
            else if(pmaxcnt==2){
                if(point[n]==pmax) return 1.0;
                else return 0.0;
            }
            else{
                if(point[n]!=pmax) return 0.0;
                
                locmaskc = 0;
                for(int i=0;i<4;i++){
                    locmask[i] &= point[i]==pmax;
                    if(locmask[i]) locmaskc++;
                }
                return -1.0;
            }
        }
        else{
            if(pmaxcnt==1){
                if(point[n]==pmax) return 1.0;
                else return 0.0;
            }
            else{
                if(point[n]!=pmax) return 0.0;
                
                locmaskc = 0;
                for(int i=0;i<4;i++){
                    locmask[i] &= point[i]==pmax;
                    if(locmask[i]) locmaskc++;
                }
                return -1.0;
            }
        }
    }
}