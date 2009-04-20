import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            if(n==0) break;
            int d = sc.nextInt();
            
            String[] input = new String[n];
            for(int i=0;i<n;i++){
                input[i] = sc.next();
            }
            
            TreeSet<StringPair> output = new TreeSet<StringPair>();
            Object[] input_del = new Object[n];
            for(int i=0;i<n;i++){
                input_del[i] = new LinkedHashSet<String>();
                addAllDelete(input[i],(LinkedHashSet<String>)input_del[i]);
            }
            
            if(d==1){
                for(int i=0;i<n;i++){
                    String s1 = input[i];
                    HashSet<String> del = (LinkedHashSet<String>)input_del[i];
                    HashSet<String> swap = new HashSet<String>();
                    addAllSwap(s1,swap);
                    for(int j=0;j<n;j++){
                        if(i==j) continue;
                        String s2 = input[j];
                        if(s1.length()==s2.length()){
                            if(i<j) continue;
                            //S
                            if(swap.contains(s2)){
                                output.add(new StringPair(s1,s2));
                                continue;
                            }
                            //R
                            if(replacedist(s1,s2)<=1){
                                output.add(new StringPair(s1,s2));
                                continue;
                            }
                        }
                        else if(s1.length()==s2.length()+1){
                            //D
                            if(del.contains(s2)) output.add(new StringPair(s1,s2));
                        }
                    }
                }
            }
            else{
                for(int i=0;i<n;i++){
                    String s1 = input[i];
                    LinkedHashSet<String> del = (LinkedHashSet<String>)input_del[i];
                    HashSet<String> deldel = new HashSet<String>();
                    for(String s:del){
                        addAllDelete(s,deldel);
                    }
                    
                    LinkedHashSet<String> swap = new LinkedHashSet<String>();
                    addAllSwap(s1,swap);
                    HashSet<String> swap2 = new HashSet<String>();
                    addAllSwap2(s1,swap2);
                    
                    HashSet<String> delswap = new HashSet<String>();
                    for(String s:del){
                        addAllSwap(s,delswap);
                    }
                    for(int j=0;j<n;j++){
                        if(i==j) continue;
                        String s2 = input[j];
                        if(s1.length()==s2.length()){
                            if(i<j) continue;
                            //S,SS
                            if(swap2.contains(s2)){
                                output.add(new StringPair(s1,s2));
                                continue;
                            }
                            //R,RR
                            if(replacedist(s1,s2)<=2){
                                output.add(new StringPair(s1,s2));
                                continue;
                            }
                            //SR
                            boolean cont = false;
                            for(String s:swap){
                                if(replacedist(s,s2)<=1){
                                    output.add(new StringPair(s1,s2));
                                    cont = true;
                                    break;
                                }
                            }
                            if(cont) continue;
                            //DI
                            cont = false;
                            for(String s:del){
                                if(((LinkedHashSet<String>)input_del[j]).contains(s)){
                                    output.add(new StringPair(s1,s2));
                                    cont = true;
                                    break;
                                }
                            }
                            if(cont) continue;
                        }
                        else if(s1.length()==s2.length()+1){
                            //D
                            if(del.contains(s2)){
                                output.add(new StringPair(s1,s2));
                                continue;
                            }
                            //DS                            
                            if(delswap.contains(s2)){
                                output.add(new StringPair(s1,s2));
                                continue;
                            }
                            //DR
                            for(String s:del){
                                if(replacedist(s,s2)<=1){
                                    output.add(new StringPair(s1,s2));
                                }
                            }                    
                        }
                        else if(s1.length()==s2.length()+2){
                            if(deldel.contains(s2)) output.add(new StringPair(s1,s2));
                        }
                    }
                }
            }
            for(StringPair sp:output){
                System.out.println(sp.s1+","+sp.s2);
            }
            System.out.println(output.size());
        }
    }
    private static int replacedist(String s1,String s2){
        if(s1.length()!=s2.length()) return -1;
        int ret = 0;
        for(int i=0;i<s1.length();i++){
            if(s1.charAt(i)!=s2.charAt(i)) ret++;
        }
        return ret;
    }
    
    private static void addAllDelete(String s, HashSet<String> h) {
        for(int k=0;k<s.length();k++){
            String news = delete(s,k);
            if(!h.contains(news)) h.add(news);
        }
    }
    private static void addAllSwap(String s,HashSet<String> h){
        for(int k=0;k<s.length()-1;k++){
            String news = swap(s,k);
            if(!h.contains(news)) h.add(news);
        }
    }
    private static void addAllSwap2(String s,HashSet<String> h){
        for(int k=0;k<s.length()-1;k++){
            String news = swap(s,k);
            if(!h.contains(news)) h.add(news);
            for(int l=0;l<s.length()-1;l++){
                String news2 = swap(news,l);
                if(!h.contains(news2)) h.add(news2);
            }
        }
    }
    private static String delete(String s,int index){
        char[] ret = new char[s.length()-1];
        int p = 0;
        for(int i=0;i<s.length();i++){
            if(i!=index){
                ret[p] = s.charAt(i);
                p++;
            }
        }
        return new String(ret);
    }
    private static String swap(String s,int index){
        char[] ret = new char[s.length()];
        for(int i=0;i<s.length();i++){
            if(i!=index&&i!=index+1) ret[i] = s.charAt(i);
            else if(i==index) ret[i] = s.charAt(i+1);
            else ret[i] = s.charAt(i-1);
        }
        return new String(ret);
    }
}
class StringPair implements Comparable<StringPair>{
    String s1;
    String s2;
    StringPair(String s1, String s2) {
        if(s1.compareTo(s2)<0){
            this.s1 = s1;
            this.s2 = s2;
        }
        else{
            this.s1 = s2;
            this.s2 = s1;
        }
    }
    public boolean equals(Object o){
        StringPair sp = (StringPair)o;
        return this.s1.equals(sp.s1)&&this.s2.equals(sp.s2);
    }
    public int compareTo(StringPair sp){
        if(!this.s1.equals(sp.s1)) return this.s1.compareTo(sp.s1);
        else return this.s2.compareTo(sp.s2);
    }
}