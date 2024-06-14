class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(nums.begin(), nums.end());
        int result = 0; 
        for (int i = 1; i < nums.size(); ++i){
            int curr = nums[i];
            int prev = nums[i - 1];
            for (int j = 0; j <= prev - curr; ++j){
                nums[i]++;
                result++;
            }
        }

        return result;
    }
};