class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            if (nums.size() - i <= nums[i]){
                return nums.size() - i;
            } else if (nums.size() - i == nums[i] + 1){
                return -1;
            }
        }
        return -1;
    }
};