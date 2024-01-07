import java.util.*;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> unique = new HashSet<>();
        int i = 0, j = 0, max = 0;

        while (j < s.length()){
            if (!unique.contains(s.charAt(j))){
                unique.add(s.charAt(j++));
                max = Math.max(max, unique.size());
            }
            else {
                unique.remove(s.charAt(i++));
            }
        }

        return max;
    }
}