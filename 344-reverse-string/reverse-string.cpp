class Solution {
public:
    void reverseString(vector<char>& s) {
        char tmpChar;
        for (int i = 0; i < (s.size() / 2); ++i){
            tmpChar = s[i];
            s[i] = s[s.size() - (1 + i)];
            s[s.size() - (i + 1)] = tmpChar;
        }
    }
};