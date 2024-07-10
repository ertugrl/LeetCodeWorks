class Solution {
public:
    int minOperations(vector<string>& logs) {
        int result = 0;
        for (int i = 0; i < logs.size(); ++i) {
            if (logs[i].substr(0,2) == "./") {
                continue;
            } else if (logs[i].substr(0,2) == "..") {
                result = max(0, result - 1);
            } else { // "./" or "x/"
                result++;
            }
        }

        return result;
    }
};