import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		float sum = 0;
		while (sc.hasNext()) {
			sum += sc.nextFloat();
		}
		System.out.printf("$%.2f\n", sum / 12);
	}
}
