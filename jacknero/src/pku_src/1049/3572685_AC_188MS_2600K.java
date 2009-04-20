import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            String input = sc.next();
            if(input.charAt(0)=='8') break;
            Processor proc = new Processor(input);
            proc.execute();
            proc.println();
        }
    }
}

class Processor{
    int[] mem;
    int pc;
    int rega;
    int regb;
    Processor(String s){
        mem = new int[256];
        for(int i=0;i<256;i++){
            mem[i] = char_to_int(s.charAt(i));
        }
        pc = 0;
        rega = 0;
        regb = 0;
    }
    private static int char_to_int(char c){
        if('0'<=c&&c<='9') return c-'0';
        else/*'A'<=c&&c<='F'*/ return c-'A'+10;
    }
    public void execute(){
        int cnt = 0;
        boolean stop = false;
        while(!stop){
            switch(mem[pc]){
            case 0:
                rega = mem[mem[pc+1]*16+mem[pc+2]];
                pc += 3;
                break;
            case 1:
                mem[mem[pc+1]*16+mem[pc+2]] = rega;
                pc += 3;
                break;
            case 2:
                rega = rega + regb;
                regb = rega - regb;
                rega = rega - regb;
                pc += 1;
                break;
            case 3:
                int sum = rega + regb;
                rega = sum%16;
                regb = sum/16;
                pc += 1;
                break;
            case 4:
                rega++;
                if(rega==16) rega = 0;
                pc += 1;
                break;
            case 5:
                rega--;
                if(rega==-1) rega = 15;
                pc += 1;
                break;
            case 6:
                if(rega==0) pc = mem[pc+1]*16+mem[pc+2];
                else pc += 3;
                break;
            case 7:
                pc = mem[pc+1]*16+mem[pc+2];
                break;
            case 8:
                stop = true;
                break;
            }
        }
    }
    public void println(){
        char[] output = new char[256];
        for(int i=0;i<256;i++){
            if(mem[i]<=9) output[i] = (char)('0'+mem[i]);
            else output[i] = (char)('A'+mem[i]-10);
        }
        System.out.println(output);
    }
}