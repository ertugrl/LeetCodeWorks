class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> prefSum(s.size() + 1, 0);
        
        for (int i = 1; i <= s.size(); i++) {
            prefSum[i] = prefSum[i - 1] + abs(s[i - 1] - t[i - 1]);
            cout << prefSum[i] << endl;
        }

        int rg = 1, lf = 0, maxLength = 0;
        while (rg <= s.size()){
            if (prefSum[rg] - prefSum[lf] <= maxCost){
                maxLength = max(maxLength, rg - lf);
                rg++;
            } else {
                lf++;
            }
        }

        return maxLength;
    }
};