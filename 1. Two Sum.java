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
}