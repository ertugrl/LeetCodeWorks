class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> v;
        int size = nums.size();
        int uppBound = 1 << size;
        for (int i = 0; i < uppBound; i++){
            vector<int> innerV;
            int nthBit = 0;
            for (int j = i; j > 0; j >>= 1){
                if (j & 1){
                    innerV.push_back(nums[nthBit]);
                }
                nthBit++;
            }
            sort(innerV.begin(), innerV.end());
            v.push_back(innerV);
        }

        set<vector<int>> tempSet(v.begin(), v.end());
        
        vector<vector<int>> result(tempSet.begin(), tempSet.end());

        return result;
    }
};