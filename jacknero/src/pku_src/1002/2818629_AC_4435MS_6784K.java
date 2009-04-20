//Problem 1002
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Scanner;

class Phone {
	int num, times;
	Phone left, right;
	public Phone(int val) {
		num = val;
		times = 1;
		left = right = null;
	}
}

public class Main {
	
	private final static char[] table =
//		  A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,
		{'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6',
//		 P, ,R,S,T,U,V,W,X,Y
		 '7','7','7','7','8','8','8','9','9','9'};
	private static char[] output = {'0','0','0','-','0','0','0','0'};
	private static boolean noDuplicates = true;
	
         //插入新电话号码到二叉排序树
	public static void add(Phone tree, Phone newPhone) {
		if(newPhone.num<tree.num) {
			if(tree.left!=null) add(tree.left,newPhone);
			else tree.left = newPhone;
		}else if(newPhone.num>tree.num) {
			if(tree.right!=null) add(tree.right,newPhone);
			else tree.right = newPhone;
		}else {
			tree.times++;
		}
	}
	
         //中序遍历二叉排序树
	public static void midtraval(Phone tree) {
		if(tree!=null) {
			if(tree.left!=null) midtraval(tree.left);
			if(tree.times>1) {
				noDuplicates = false;
				for(int i=7; i>=0; i--) {
					if(i==3) continue;
					output[i] = (char)(tree.num%10+48);
					tree.num /= 10;
				}
				System.out.print(output);
				System.out.println(" " + tree.times);
			}
			if(tree.right!=null) midtraval(tree.right);
		}
	}
	
	public static void main(String[] args) throws IOException {
		Scanner stdin = new Scanner(System.in);
		int numbers = Integer.parseInt(stdin.nextLine());
		int length, delta, i, k;
		Phone root = null;
		char[] num = {'0','0','0','0','0','0','0'};
		while(numbers!=0) {
			String s = stdin.nextLine();
			length = s.length();
			for(i=length-1, k=6; i>=0; i--) {
				delta = s.charAt(i) - 'A';
				if(delta>=0) {
					num[k--] = table[delta];
				}else if(delta!= '-' - 'A') {
					num[k--] = s.charAt(i);
				}
			}
			if(root==null) root = new Phone(Integer.parseInt(new String(num)));
			else {
				Phone newPhone = new Phone(Integer.parseInt(new String(num)));
				add(root,newPhone);
			}
			numbers--;
		}
		midtraval(root);
		if(noDuplicates) System.out.println("No duplicates.");
	}
}///:~