import java.io.*;
import java.util.*;

//内部では部屋番号は0から開始するものとして処理．出力で調整．

class room{
    int door[],ptr;//ドアの行き先の部屋の配列，ptrは配列をスタック的に扱うための変数
    int level;//入り口からの距離
    
    //コンストラクタ，ドア配列の大きさを部屋ごとに変えるため
    room(int n){
        int i;
        door = new int[n];
        ptr = 0;
    }
    
    //部屋の入り口からの距離をセットする
    void setlevel(int i){
        level = i;
    }
    
    //ドア配列に新しい行き先をプッシュする
    void add(int i){
        door[ptr] = i;
        ptr++;
    }
    
    //その部屋に未探索のドアはあるか
    boolean isFull(){
        if(ptr == door.length) return true;
        else return false;
    }
}

public class Main{
    static void makeMap(BufferedReader in){
        int input[] = new int[3000];//入力行を配列化したもの
        int inputlinesize;//入力行にある数字の個数
        int inputsize;//入力にある数字の個数
        room r[];//部屋配列
        int numr;//部屋の数
        int ptr;//探索者が何番の部屋にいるかを示す
        int ptrlev;//探索者の深さ
        int ptrmax;//探索者が探索した部屋の個数を示す
        int i,j,k;
        
        //Inputの読み込み
        inputsize = 0;
        do{
            try{
            StringTokenizer st = new StringTokenizer(in.readLine());
            inputlinesize = st.countTokens();
            for(i=inputsize;i<(inputsize+inputlinesize);i++){
                input[i] = Integer.parseInt(st.nextToken());
            }
            inputsize += inputlinesize;
            }
            catch(Exception e){
            System.out.println(e.toString());
            System.exit(1);
            }
        }while(input[inputsize-1]!=0);
        inputsize--;
        
        try{
        //room配列をつくる
        //まず部屋数を決定
        numr = 0;
        for(i=0;i<inputsize;i++){
            if(input[i]>0) numr++;
        }
        r = new room[numr];
        //次に各部屋のドア数を決定
        j=0;
        for(i=0;i<inputsize;i++){
            if(input[i]>0){
                r[j] = new room(input[i]);
                j++;
            }
        }
        //map作成の本体
        ptr = 0;//現在探索者のいる部屋
        ptrmax = 0;//探索済みの部屋で部屋番号の最も大きいもの
        ptrlev = 0;//
        k=0;
        for(i=1;i<inputsize;i++){
            //探索者のいる部屋のドアがすべてオープン済のときはiを減らさないまま
            //ptrlevを減らし，ptrを一階層前に戻す．
            if(r[ptr].isFull()){
                ptrlev--;
                for(j=0;j<ptrmax;j++){
                    if(r[j].level == ptrlev) ptr=j;
                }
                i--;
            }
            //探索者のいる部屋のドアを開いて
            else{
                //行き先は新しい部屋
                if(input[i]>0){
                    ptrmax++;
                    ptrlev++;
                    r[ptr].add(ptrmax);
                    r[ptrmax].add(ptr);
                    r[ptrmax].setlevel(ptrlev);
                    ptr = ptrmax;
                }
                //行き先は探索済の部屋
                else{
                    //入り口からの距離の差が条件をみたす部屋で
                    //最後に発見した部屋が求める部屋
                    for(j=0;j<=ptrmax;j++){
                        if(r[j].level - r[ptr].level == input[i]) k = j;
                    }
                    r[ptr].add(k);
                    r[k].add(ptr);
                }
            }
        }
        //各roomの配列doorをソート
        for(i=0;i<numr;i++){
            Arrays.sort(r[i].door);
        }
        
        //出力
        for(i=0;i<numr;i++){
            System.out.print(i+1);
            for(j=0;j<r[i].door.length;j++){
                System.out.print(" "+(r[i].door[j]+1));
            }
            System.out.println();
        }
        
        }
        catch(Exception e){
            System.out.println(e.toString());
            System.exit(1);
        }
    }
    
    public static void main(String args[]){
        int n,i;
        BufferedReader in;
        try{
        in = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(in.readLine());
        for(i=0;i<n;i++) makeMap(in);
        }
        catch(Exception e){
            System.out.println(e.toString());
            System.exit(1);
        }
    }
}