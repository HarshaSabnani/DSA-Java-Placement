class Solution {
    public int longestSubsequence(int[] nums) {
        int n = nums.length;
        int totalXOR = 0;
        boolean hasNonZero = true;
        for(int x : nums) {
            totalXOR ^= x;
            if(x > 0) {
                hasNonZero = false;
            }
        }
        if(totalXOR > 0) {
            return n;
        }
        return hasNonZero ? 0 : n-1;
    }
}