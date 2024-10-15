class Solution {
public:
    long long minimumSteps(string s) {
        long long result = 0;
        int oneCounter = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') { oneCounter++; }
            else { result += oneCounter; }
        }

        return result;
    }
};