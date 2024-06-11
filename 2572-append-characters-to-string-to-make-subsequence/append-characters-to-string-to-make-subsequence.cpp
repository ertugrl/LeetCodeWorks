class Solution {
public:
    int appendCharacters(string s, string t) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int tIndex = 0;
        for (int i = 0; (i < s.size()) && (tIndex < t.size()); ++i){
            if (s[i] == t[tIndex]) tIndex++;
        }

        return t.size() - tIndex;
    }
};