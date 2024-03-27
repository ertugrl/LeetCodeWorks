class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int result = 0;
        int slow = 0, fast = 0, product = 1;
        while (fast < nums.size()){
            product *= nums[fast];

            while (product >= k){
                product /= nums[slow];
                slow++;
            }
            result += fast - slow + 1;
            fast++;
        }
        return result;
    }
};