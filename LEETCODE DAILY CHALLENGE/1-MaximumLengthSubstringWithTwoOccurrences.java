import java.util.HashMap;

class Solution {
    public int maximumLengthSubstring(String s) {
        int n = s.length();
        int j = 0;
        int ans = 0;

        HashMap<Character, Integer> mp = new HashMap<>();

        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);

            mp.put(ch, mp.getOrDefault(ch, 0) + 1);

            while (mp.get(ch) > 2) {
                char left = s.charAt(j);
                mp.put(left, mp.get(left) - 1);
                j++;
            }

            ans = Math.max(ans, i - j + 1);
        }

        return ans;
    }
}