class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxNum = -1;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++){
            if (mp.find(nums[i] * (-1)) == mp.end())
                mp[nums[i]]++;
            else
                maxNum = maxNum < abs(nums[i]) ? abs(nums[i]) : maxNum;
        }
        return maxNum;
    }
};