class Solution {
public:
    bool checkValidString(string s) {
        int leftBalance = 0;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '(' || s[i] == '*') leftBalance++;
            else leftBalance--;
            if (leftBalance < 0) return false; // ")..."
        }

        if (leftBalance == 0) return true; // The string is already balanced
        
        int rightBalance = 0; 
        for (int i = s.size() - 1; i >= 0; --i){
            if (s[i] == ')' || s[i] == '*') rightBalance++;
            else rightBalance--;
            if (rightBalance < 0) return false; // "...("
        }

        return true;
    }

};