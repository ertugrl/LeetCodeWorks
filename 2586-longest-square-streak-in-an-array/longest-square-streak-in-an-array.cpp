class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> hashSet;
        for (int i = 0; i < nums.size(); ++i) {
            hashSet.insert(nums[i]);
        }

        long long maxCount = 1;
        
        for (long long num : hashSet) {
            cout << num << endl;
            long long counter = 1;
            while (hashSet.find(num * num) != hashSet.end()) {
                num = num * num;
                counter++;
            }
            maxCount = max(maxCount, counter);
        }

        if (maxCount == 1) { return -1; }

        return maxCount;
    }
};