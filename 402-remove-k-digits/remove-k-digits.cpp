class Solution {
public:
    // int charToInt(char c){
    //     return c - '0';
    // }
    string removeKdigits(string num, int k) {
        if (num.size() == k) return "0";
        
        stack<char> digit;
        digit.push(num[0]);

        int cur = 1;
        int removedNumber = 0;

        while (cur < num.size() && removedNumber < k){
            if (!digit.empty() && digit.top() > num[cur]){
                digit.pop();
                removedNumber++;
            } else {
                digit.push(num[cur]);
                cur++;
            }
        }
        for (int i = 0; i < k - removedNumber; ++i) digit.pop();

        string result = "";
        int stackSize = digit.size();
        for (int i = 0; i < stackSize; ++i){
            result += digit.top();
            digit.pop();
        }
        reverse(result.begin(), result.end());
        result += num.substr(cur);

        int index;
        for (index = 0; index < result.size(); ++index){
            if (result[index] != '0') return result.substr(index);
        }

        return "0";
    }
};