import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int c=0;c<n;c++){
            String line = sc.next();
            ArrayList<Integer> segs = new ArrayList<Integer>();
            segs.add(0);
            for(int i=1;i<line.length();i++){
                if(line.charAt(i-1)=='1'&&line.charAt(i)=='0'){
                    segs.add(i);
                }
            }
            segs.add(line.length());
            
            while(true){
                boolean end = true;
                
                for(int i=0;i<segs.size()-2;i++){
                    String s1 = line.substring(segs.get(i), segs.get(i+1));
                    String s2 = line.substring(segs.get(i+1), segs.get(i+2));
                    if(isNecklace(s1.concat(s2))){
                        segs.remove(i+1);
                        end = false;
                    }
                }
                
                if(end) break;
            }
            
            for(int i=0;i<segs.size()-1;i++){
                System.out.print("("+line.substring(segs.get(i), segs.get(i+1))+")");
            }
            System.out.println();
        }
    }
    public static boolean isNecklace(String s){
        int n = s.length();
        for(int i=1;i<n;i++){
            String s1 = rotate(s, i);
            if(s.compareTo(s1)>0) return false;
        }
        return true;
    }
    public static String rotate(String s, int d){
        char[] ret = new char[s.length()];
        for(int i=0;i<s.length();i++){
            ret[i] = s.charAt((i+d)%s.length());
        }
        return new String(ret);
    }
}