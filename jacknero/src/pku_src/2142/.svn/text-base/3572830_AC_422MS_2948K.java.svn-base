import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int a = sc.nextInt();
            int b = sc.nextInt();
            int d = sc.nextInt();
            if(a==0&&b==0&&d==0) break;
            
            int x1,y1,x2,y2,x,y;
            x1 = d/a;
            if(a*x1<d) x1++;
            while((a*x1-d)%b!=0) x1++;
            y1 = (a*x1-d)/b;
            
            y2 = d/b;
            if(b*y2<d) y2++;
            while((b*y2-d)%a!=0) y2++;
            x2 = (b*y2-d)/a;
            
            if(x1+y1<x2+y2){
                x = x1; y = y1;
            }
            else if(x1+y1>x2+y2){
                x = x2; y = y2;
            }
            else{
                if(a*x1+b*y1<a*x2+b*y2){
                    x = x1; y = y1;
                }
                else{
                    x = x2; y = y2;
                }
            }
            
            if(a<d&&b<d){
                int x3,y3;
                boolean exist;
                x3 = y3 = -1;
                exist = false;
                if(a<b){
                    x3 = 1;
                    while(a*x3<d){
                        if((d-a*x3)%b==0){
                            y3 = (d-a*x3)/b;
                            exist = true;
                            break;
                        }
                        x3++;
                    }
                }
                else{
                    y3 = 1;
                    while(b*y3<d){
                        if((d-b*y3)%a==0){
                            x3 = (d-b*y3)/a;
                            exist = true;
                            break;
                        }
                        y3++;
                    }
                }
                
                if(exist){
                    if(x3+y3<x+y){
                        x = x3; y = y3;
                    }
                    else if(x3+y3==x+y&&a*x3+b*y3<a*x+b*y){
                        x = x3; y = y3;
                    }
                }
            }
            
            System.out.println(x+" "+y);
        }
    }
}