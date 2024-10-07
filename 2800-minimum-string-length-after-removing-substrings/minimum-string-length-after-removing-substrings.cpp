class Solution {
public:
    int minLength(string s) {
        stack<char> letters;
        for (int i = 0; i < s.size(); ++i) {
            if (!letters.empty() && ((letters.top() == 'A' && s[i] == 'B') || 
                (letters.top() == 'C' && s[i] == 'D'))) {
                letters.pop();
                continue;
            }
            letters.push(s[i]);
        }

        int result = 0;
        while (!letters.empty()) {
            letters.pop();
            result++;
        }

        return result;
    }
};