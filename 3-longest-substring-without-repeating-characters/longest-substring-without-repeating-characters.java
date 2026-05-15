import java.util.HashSet;
import java.util.Set;

class Solution {
    public int lengthOfLongestSubstring(String s) {

        int l = 0;
        int r = 0;
        int ans = 0;

        Set<Character> set = new HashSet<>();

        while (r < s.length()) {

            if (set.contains(s.charAt(r))) {
                set.remove(s.charAt(l));
                l++;
            } else {
                set.add(s.charAt(r));
                r++;

                ans = Math.max(ans, set.size());
            }
        }

        return ans;
    }
}