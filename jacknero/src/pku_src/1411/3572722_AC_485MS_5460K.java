import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int[] prm = new int[20000];
        makePNTable(prm);
        while(true){
            int m = sc.nextInt();
            int a = sc.nextInt();
            int b = sc.nextInt();
            
            if(m==0 && a==0 && b==0) break;

            int i;
            for(i=0;prm[i]*prm[i]<=m;i++){
                //do nothing
            }
        
            int pi,qi,mpi,mqi;
            pi = qi = mpi = mqi = i-1;
            int max = prm[mpi] * prm[mqi];
        
            while(b*prm[pi]>=a*prm[qi]){
                if(prm[qi]*prm[pi]<=m){
                    qi++;
                    if(prm[qi]*prm[pi]<=m){
                        if(prm[qi]*prm[pi]>max && b*prm[pi]>=a*prm[qi]){
                            mpi = pi;
                            mqi = qi;
                            max = prm[pi] * prm[qi];
                        }
                    }
                }
                else{
                    if(pi==0) break;
                    
                    pi--;
                    if(prm[qi]*prm[pi]<=m){
                        if(prm[qi]*prm[pi]>max && b*prm[pi]>=a*prm[qi]){
                            mpi = pi;
                            mqi = qi;
                            max = prm[pi] * prm[qi];
                        }
                    }
                }
            }
            
            System.out.println(prm[mpi]+" "+prm[mqi]);
        }
    }
    /* make list of Prime Numbers : size = 50000 */
    private static void makePNTable(int[] p){
        int i,j,k;
        int flag ;
        k = 0;
        p[k++] = 2;
        for(i=3;i<50000;i+=2){
            flag = 0;
            for(j=0;(p[j]*p[j])<=i;j++){
                if(i % p[j] == 0){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                p[k++] = i;
            }
        }
    }
}