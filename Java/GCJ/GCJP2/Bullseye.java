import java.util.Scanner;

public class Bullseye {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int i = 1; i <= cases; i++) {
			long r = sc.nextLong();
			long t = sc.nextLong();
			double n =Math.sqrt(r)*Math.sqrt(4*r - 4 + 1/r + 8*t/r);
			n += -2*r + 1;
			n /= 4;
			System.out.println("Case #" + i + ": " + (long)n);
		}
	}
}
