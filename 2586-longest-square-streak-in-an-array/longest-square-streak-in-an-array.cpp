#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("O3", "unroll-loops")
#pragma GCC optimize ("-ffloat-store")

auto init = []() { 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
} ();



class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<long long> hashSet;
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
                hashSet.erase(num);
            }
            maxCount = max(maxCount, counter);
        }

        return maxCount == 1 ? -1 : maxCount;
    }
};