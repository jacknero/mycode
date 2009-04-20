/** Encoding: Shift JIS (CP932)
 *  Hanafuda Shuffle (PKU 1978)
 *  by pascal, 2006-12-22
 **/

import java.io.FileInputStream;
import java.io.InputStream;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Stack;

public class Main{
	static Scanner scanner;
	Stack<Integer> card;

	void solve(int p, int c){
		LinkedList<Integer> pl = new LinkedList<Integer>();
		LinkedList<Integer> cl = new LinkedList<Integer>();

		for(int i=0;i<p-1;i++)pl.offer(card.pop());
		for(int i=0;i<c;i++)cl.offer(card.pop());

		for(int i=0;i<p-1;i++){
			card.push(pl.getLast());
			pl.removeLast();
		}
		for(int i=0;i<c;i++){
			card.push(cl.getLast());
			cl.removeLast();
		}
	}

	Main(){
		int r,n;
		while(true){
			n = scanner.nextInt();
			r = scanner.nextInt();

			// 終了条件
			if (n==0) break;

			// カードの初期化
			card = new Stack<Integer>();
			for(int i=0;i<n;i++){
				card.push(i+1);
			}

			for(int i=0;i<r;i++){
				int p = scanner.nextInt();
				int c = scanner.nextInt();
				solve(p,c);
			}

			// 出力
			System.out.println(card.peek());
		}
	}

	public static void main(String[] args)throws Exception{
		InputStream in = System.in;
		// InputStream in = new FileInputStream("A1.input");

		//スキャナの初期化
		scanner = new Scanner(in);
		new Main();
	}
}