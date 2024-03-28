class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            count[nums[right]]++;

            // Shrink the window from the left if condition is violated
            while (count[nums[right]] > k) {
                count[nums[left]]--;
                left++;
            }

            // Update maxLength if a new maximum is found
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
