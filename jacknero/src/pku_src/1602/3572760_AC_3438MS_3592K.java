import java.util.*;
public class Main {
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        String mode = sc.next();
        if(mode.equals("A")){
            int n = sc.nextInt();
            char[] str = new char[n];
            str = sc.next().toCharArray();
            
            if(n==1){
                System.out.println(str);
                System.out.println(1);
                return;
            }
            
            // n>1
            ZipString[] zs = new ZipString[n];
            
            for(int i=0;i<n;i++){
                char head = str[i];
                char tail = str[(i+n-1)%n];
                ZipString z = new ZipString(i,head,tail);
                zs[i] = z;
            }
            Arrays.sort(zs);
            
            char[] zstr = new char[n];
            int p = -1;
            for(int i=0;i<n;i++){
                zstr[i] = zs[i].tail;
                if(zs[i].k==1) p = i;
            }
            
            System.out.println(zstr);
            System.out.println(p+1);
        }
        else if(mode.equals("B")){
            int n = sc.nextInt();
            char[] zstr = new char[n];
            zstr = sc.next().toCharArray();
            int p = sc.nextInt()-1;
            
            char[] zstr_next = new char[n];
            for(int i=0;i<n;i++) zstr_next[i] = zstr[i];
            Arrays.sort(zstr_next);
            
            int[] m = new int[26];
            Arrays.fill(m,-1);
            for(int i=0;i<n;i++) m[(zstr_next[i])-'a'] = i;
            
            char[] str = new char[n];
            int a = -1;
            for(int i=0;i<n;i++){
                if(zstr_next[i]==zstr[p]){
                    a = i;
                    break;
                }
            }
            str[n-1] = zstr[a];
            
            for(int i=n-1;i>0;i--){
                int k = m[str[i]-'a'];
                str[i-1] = zstr[k];
                m[str[i]-'a'] = k-1;
            }
            
            System.out.println(str);
        }
        else throw new Exception();
    }
}
class ZipString implements Comparable<ZipString>{
    int k;
    char head;
    char tail;
    ZipString(int k, char head,char tail) {
        this.k = k;
        this.head = head;
        this.tail = tail;
    }
    public boolean equals(Object o){
        ZipString z = (ZipString)o;
        return this.head==z.head;
    }
    public int compareTo(ZipString z){
        return this.head-z.head;
    }
}