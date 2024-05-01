class Solution {
public:
    string reversePrefix(string word, char ch) {
        string revStr = "";
        string lastStr = "";
        bool isChange = false;
        for (int i = 0; i < word.size(); i++){
            if (ch == word[i]){
                revStr = word.substr(0, i + 1);
                lastStr = word.substr(i + 1, word.size() - (i + 1));
                isChange = true;
                break;
            }
        }
        reverse(revStr.begin(), revStr.end());
        revStr.append(lastStr);
        return (isChange ? revStr : word);
    }
};