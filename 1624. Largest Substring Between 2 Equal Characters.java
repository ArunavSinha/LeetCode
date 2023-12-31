class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int result = -1;
        
        for (int i = 0; i <= s.length()-1; i++){
            for (int j = s.length()-1; j >= 0; j--){
                if (s.charAt(i) == s.charAt(j)){
                    int distance = Math.abs(j - i) - 1;
                    result = Math.max(distance, result);
                }
            }            
        }

        return result;
    }
}