class Solution {
    public int[] twoSum(int[] nums, int target) { // my brute force solution
        for (int i = 0; i <= nums.length-1; i++){
            for (int j = nums.length-1; j >= 0; j--){
                if (((nums[i] + nums[j]) == target) && (i != j)){
                    return new int[]{i, j};
                }
            }
        }
        return new int[]{};
    }

    public int[] TwoSum(int[] nums, int target) { // my Optimized solution (HashMap)
        Map<Integer, Integer> map = new HashMap<>();
        int n = nums.length;

        for (int i = 0; i < n; i++){
            map.put(nums[i], i);
        }

        for (int j = 0; j < n; j++){
            int complement = target - nums[j];
            if (map.containsKey(complement) && map.get(complement) != j){
                return new int[]{j, map.get(complement)};
            }
        }
        return new int[]{};
    }
}