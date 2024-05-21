class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int size = nums.size();
        int uppBound = 1 << size;
        for (int i = 0; i < uppBound; i++){
            vector<int> innerV;
            int nthBit = 0;
            for (int j = i; j > 0; j /= 2){
                if (j % 2 != 0){
                    innerV.push_back(nums[nthBit]);
                }
                nthBit++;
            }
            result.push_back(innerV);
        }

        return result;
    }
};