class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int, int, greater<int>> mp;
        for (int i = 0; i < score.size(); i++){
            mp[score[i]] = i;
        }
        
        int top = 1;
        vector<string> s(score.size());
        for (auto &it: mp){
            if (top == 1) s[it.second] = "Gold Medal";
                
            else if (top == 2) s[it.second] = "Silver Medal";
                
            else if (top == 3) s[it.second] = "Bronze Medal";
                
            else s[it.second] = to_string(top);

            top++;
        }

        return s;
    }
};
