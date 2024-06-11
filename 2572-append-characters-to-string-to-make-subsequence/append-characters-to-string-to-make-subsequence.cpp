class Solution {
public:
    int appendCharacters(string s, string t) {
        int tIndex = 0;
        for (int i = 0; (i < s.size()) && (tIndex < t.size()); ++i){
            if (s[i] == t[tIndex]) tIndex++;
        }

        return t.size() - tIndex;
    }
};