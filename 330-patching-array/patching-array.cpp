class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int count = 0, idx = 0;
        long long maxNum = 0;
        
        while (maxNum < n){
            if (idx < nums.size() && nums[idx] <= maxNum + 1){
                maxNum += nums[idx++];
            } else {
                maxNum += maxNum + 1;
                count++;
            }
        }

        return count;
    }
};