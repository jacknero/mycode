import java.util.*;
import java.util.regex.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        for(int i=0;i<n;i++){
            String line1 = sc.nextLine();
            Pattern pattern;
            pattern = Pattern.compile("<|>");
            String[] strs = pattern.split(line1,-1);
            System.out.print
                (strs[0]+strs[1]+strs[2]+strs[3]+strs[4]);
            System.out.println();
            String line2 = sc.nextLine();
            line2 = line2.substring(0,line2.length()-3);
            System.out.print
                (line2+strs[3]+strs[2]+strs[1]+strs[4]);
            System.out.println();
        }
    }
}