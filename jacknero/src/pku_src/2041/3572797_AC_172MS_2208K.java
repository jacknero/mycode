import java.util.*;

public class Main {
    static void inverseJ(char st[],int n){
        int i;
        for(i=n-1;i>=0;i--){
            st[i+1] = st[i];
        }
        st[0] = st[n];
    }

    static void inverseC(char st[],int n){
        int i;
        st[n] = st[0];
        for(i=0;i<n;i++){
            st[i] = st[i+1];
        }
    }

    static void inverseE(char st[],int n){
        char[] temp = new char[30];
        if(n%2==0){
            for(int i=0;i < n/2;i++){
                temp[i] =st[i+n/2];
                st[i+n/2] = st[i];
            }
            for(int i=0;i < n/2;i++){
                st[i] = temp[i];
            }
        }
        else{
            for(int i=0;i < n/2;i++){
                temp[i] = st[i+1+n/2];
                st[i+1+n/2] = st[i];
            }
            for(int i=0;i < n/2;i++){
                st[i] = temp[i];
            }
        }
    }

    static void inverseA(char st[],int n){
        char[] temp = new char[30];
        for(int i=0;i<n;i++){
            temp[n-1-i] = st[i];
        }
        for(int i=0;i<n;i++){
            st[i] = temp[i];
        }
    }

    static void inverseP(char st[],int n){
        int i;
        for(i=0;i<n;i++){
            if(isdigit(st[i])){
                if(st[i]=='0') st[i] = '9';
                else st[i]--;
            }
        }
    }

    static void inverseM(char st[],int n){
        int i;
        for(i=0;i<n;i++){
            if(isdigit(st[i])){
                if(st[i]=='9') st[i] = '0';
                else st[i]++;
            }
        }
    }
    
    static boolean isdigit(char c){
        return '0'<=c&&c<='9';
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        for(int i=n;i>0;i--){
            String serv = sc.next();
            int numServ = serv.length();
            String mes = sc.next();
            int mesSize = mes.length();
            char[] mesarray = new char[mesSize+1];
            for(int j=0;j<mesSize;j++) mesarray[j] = mes.charAt(j);
            mesarray[mesSize] = 0;
            
            for(int j=numServ;j>0;j--){
                if(serv.charAt(j-1) == 'J') inverseJ(mesarray,mesSize);
                else if(serv.charAt(j-1) == 'C') inverseC(mesarray,mesSize);
                else if(serv.charAt(j-1) == 'E') inverseE(mesarray,mesSize);
                else if(serv.charAt(j-1) == 'A') inverseA(mesarray,mesSize);
                else if(serv.charAt(j-1) == 'P') inverseP(mesarray,mesSize);
                else if(serv.charAt(j-1) == 'M') inverseM(mesarray,mesSize);
            }
            
            for(int j=0;j<mesSize;j++) System.out.print(mesarray[j]);
            System.out.println();
        }
    }
}