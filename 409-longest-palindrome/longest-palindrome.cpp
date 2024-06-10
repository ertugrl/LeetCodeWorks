class Solution {
public:
    int longestPalindrome(string s) {
        int result = 0;
        unordered_map<char, int> mp;
        for (char c : s){
            mp[c]++;
        }
        bool ifOdd = false;
        for (auto& pair : mp){
            if (pair.second % 2 == 1) ifOdd = true;
            result += (pair.second >> 1) << 1;
        }

        return result + ifOdd;
    }
};