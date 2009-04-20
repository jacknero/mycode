import java.util.*;
public class Main {
    static final double EPS = 1.0E-9;
    static final double GOAL = 4500;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            if(n==0) break;
            double v[] = new double[n];
            double t[] = new double[n];
            for(int i=0;i<n;i++){
                v[i] = sc.nextDouble() / 3.6;
                t[i] = sc.nextDouble();
            }
            
            double time = 0.0;
            double nowy = 0.0;
            double nowv = 0.0;
            double nowt = 0.0;
            while(true){
                double t0 = Double.MAX_VALUE;
                int o0 = -1;
                for(int i=0;i<n;i++){
                    if(nowv<v[i]){
                        double tmp = (v[i]*t[i]-nowv*nowt) / (v[i]-nowv);
                        if(tmp >= time-EPS){
                            if(tmp<t0-EPS){
                                t0 = tmp;
                                o0 = i;
                            }
                            else if(t0-EPS<=tmp && tmp<=t0+EPS){
                                if(o0!=-1){
                                    if(v[i]>v[o0]){
                                        t0 = tmp;
                                        o0 = i;                                        
                                    }
                                }
                                else{
                                    t0 = tmp;
                                    o0 = i;
                                }
                            }
                        }
                    }
                }
                
                if(o0==-1) break;
                
                if(nowy + (t0-time)*nowv >= GOAL-EPS) break;
                nowy += (t0-time)*nowv;
                
                time = t0;
                nowv = v[o0];
                nowt = t[o0];
            }
            double ans = time + (GOAL-nowy) / nowv;
            System.out.println((int)(Math.ceil(ans-EPS)));
        }
    }
}