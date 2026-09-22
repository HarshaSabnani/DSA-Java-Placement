import java.util.*;

public class MissingNumber {

    public static int missingNumber(int[] nums) {

        int n = nums.length;
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;

        for (int num : nums) {
            actualSum += num;
        }

        return expectedSum - actualSum;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter array size: ");
        int n = sc.nextInt();

        int[] nums = new int[n];

        System.out.print("Enter " + n + " numbers from 0 to " + n + ": ");

        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        int answer = missingNumber(nums);

        System.out.println("Missing Number = " + answer);

        sc.close();
    }
}