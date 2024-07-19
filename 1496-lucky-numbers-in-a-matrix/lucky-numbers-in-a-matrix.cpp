class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int maxx = INT_MIN;
        for (int i = 0; i < matrix.size(); ++i) {
            int minNum = INT_MAX;
            for (int j = 0; j < matrix[0].size(); ++j) {
                minNum = min(minNum, matrix[i][j]);
            }
            maxx = max(maxx, minNum);
        }

        int minn = INT_MAX;
        for (int j = 0; j < matrix[0].size(); ++j) {
            int maxNum = INT_MIN;
            for (int i = 0; i < matrix.size(); ++i) {
                maxNum = max(maxNum, matrix[i][j]);
            }
            minn = min(minn, maxNum);
        }

        if (maxx == minn) return {maxx};

        return {};
    }
};