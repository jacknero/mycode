import java.util.*;
public class Main {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int c=0;c<n;c++){
            String original = sc.next();
            int m = original.length();
            char[] min = original.toCharArray();
            Character[] rmin = new Character[m];
            for(int i=0;i<m;i++) rmin[i] = min[i];
            Arrays.sort(rmin, new CharacterComparator());
            for(int i=0;i<m;i++) min[i] = rmin[i];

            System.out.println(new String(min));
            
            if(m==1) continue;
            
            int[] perm = new int[m];
            for(int i=0;i<m;i++){
                perm[i] = i;
            }
            int l = m - 2;
            
            while(true){
                
                boolean[] used = new boolean[m];
                for(int i=0;i<m;i++) used[i] = false;
                for(int i=0;i<l;i++) used[perm[i]] = true;
                int k = perm[l] + 1;
                while(k<m && perm[l]>=0 && min[k]==min[perm[l]]) k++;
                while(k<m && used[k]) k++;
                
                if(k<m){
                    perm[l] = k;
                    if(l==m-1){
                        char[] cs = new char[m];
                        for(int i=0;i<m;i++) cs[i] = min[perm[i]];
                        String s = new String(cs);
                        System.out.println(s);
                    }
                    else if(l<m-1){
                        perm[l+1] = -1;
                        l++;
                    }
                }
                else l--;
                
                if(l<0) break;
            }
        }
    }
}

class CharacterComparator implements Comparator<Character>{
    public int compare(Character c1, Character c2){
            int x1, x2;
            if('a'<=c1&&c1<='z') x1 = (c1-'a') * 2 + 1;
            else x1 = (c1-'A') * 2;
            if('a'<=c2&&c2<='z') x2 = (c2-'a') * 2 + 1;
            else x2 = (c2-'A') * 2;
            
            if(x1>x2) return 1;
            else if(x1<x2) return -1;
            else return 0;
    }
}