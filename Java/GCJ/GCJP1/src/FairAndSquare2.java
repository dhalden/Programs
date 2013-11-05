import java.util.Scanner;

public class FairAndSquare2 {

 public static void main(String args[]) { Scanner sc = new Scanner(System.in); int cases = sc.nextInt(); for (int i = 1; i <= cases; i++) { long low = sc.nextLong(); long upp = sc.nextLong(); long odd = 1; long test = 1; int count = 0; while (test < low) { odd += 2; test += odd; } while (test <= upp) { if (isPalindrome(""+test) && isPalindrome(""+(int)Math.sqrt((double)test))) { count++; } odd += 2; test += odd; } System.out.println("Case #" + i + ": " + count); } } public static boolean isPalindrome(String test) { boolean result = false; if (test.length() <= 1) { result = true; } else if (test.charAt(0) == test.charAt(test.length()-1)) { result = isPalindrome(test.substring(1, test.length()-1)); } return result;  }
}
