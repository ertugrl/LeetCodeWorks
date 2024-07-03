class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) return 0;

        sort(nums.begin(), nums.end());
        
        // int left = 0, right = nums.size() - 1;
        // for (int i = 0; i < 3; ++i) {
        //     if (nums[left + 1] - nums[left] < nums[right] - nums[right - 1]) {
        //         right--;
        //     } else {
        //         left++;
        //     }
        // }

        int diff = INT_MAX;
        for (int i = 0; i < 4; ++i) {
            if (nums[nums.size() + i - 4] - nums[i] < diff)
                diff = nums[nums.size() + i - 4] - nums[i];
        }

        return diff;
    }
};