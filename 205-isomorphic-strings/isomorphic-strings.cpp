class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> StoT;
        unordered_map<char, char> TtoS;
        for (int i = 0; i < s.size(); ++i){
            if (StoT.find(s[i]) != StoT.end()){
                if (StoT[s[i]] != t[i]) return false; 
            }
            if (TtoS.find(t[i]) != TtoS.end()){
                if (TtoS[t[i]] != s[i]) return false; 
            }
            StoT[s[i]] = t[i];
            TtoS[t[i]] = s[i];
        }
        return true;
    }
};