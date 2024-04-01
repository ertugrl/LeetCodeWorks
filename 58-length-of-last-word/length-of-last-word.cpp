class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (s[i] == ' '){
            i--;
            if (i < 0) break;
        }
        int j = i;
        while (s[j] != ' '){
            j--;
            if (j < 0) break;
        }
        return i - j;
    }
};