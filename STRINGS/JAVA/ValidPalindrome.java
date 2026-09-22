import java.util.*;

public class ValidPalindrome {

    public static boolean isPalindrome(String s) {

        s = s.toLowerCase();
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            while (left < right && !Character.isLetterOrDigit(s.charAt(left))) {
                left++;
            }

            while (left < right && !Character.isLetterOrDigit(s.charAt(right))) {
                right--;
            }

            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String s = sc.nextLine();

        if (isPalindrome(s)) {
            System.out.println("Valid Palindrome");
        } else {
            System.out.println("Not a Palindrome");
        }

        sc.close();
    }
}