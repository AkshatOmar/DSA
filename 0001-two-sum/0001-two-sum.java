class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i = 0;i<n;i++) {
            mp.put(nums[i], i);
        }
        for(int i = 0;i<n;i++) {
            int val = target-nums[i];
            if(mp.containsKey(val) && mp.get(val) != i){
                return new int[] {mp.get(val), i};
            }
        }
        return new int[] {};
    }
}