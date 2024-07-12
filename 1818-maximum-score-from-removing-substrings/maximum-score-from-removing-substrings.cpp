class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int result = 0;
        int high, low;
        string highStr, lowStr;
        
        if (x > y) {
            highStr = "ab";
            high = x;
            lowStr = "ba";
            low = y;
        } else {
            highStr = "ba";
            high = y;
            lowStr = "ab";
            low = x;
        }

        deque<char> dqForHigh;
        for (char c : s) {
            if (c == highStr[1] && !dqForHigh.empty() && dqForHigh.back() == highStr[0]) {
                result += high;
                dqForHigh.pop_back();
            } else {
                dqForHigh.push_back(c);
            }
        }

        stack<char> stForLow;
        int dqSize = dqForHigh.size();
        for (int i = 0; i < dqSize; ++i) {
            char c = dqForHigh.front();
            if (c == lowStr[1] && !stForLow.empty() && stForLow.top() == lowStr[0]) {
                result += low;
                stForLow.pop();
            } else {
                stForLow.push(c);
            }
            dqForHigh.pop_front();
        }

        return result;
    }
};