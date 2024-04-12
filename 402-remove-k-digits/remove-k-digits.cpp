class Solution {
public:
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

        // If there are still rights to delete digits
        for (int i = 0; i < k - removedNumber; ++i) digit.pop();

        // Combine stack's content and rest of the given string
        string result = "";
        int stackSize = digit.size();
        for (int i = 0; i < stackSize; ++i){
            // Add digits in reverse order of the desired result
            result += digit.top();
            digit.pop();
        }
        reverse(result.begin(), result.end());

        result += num.substr(cur); // Rest of the string

        // Remove initial zeros like "0015" -> "15"
        int index;
        for (index = 0; index < result.size(); ++index){
            if (result[index] != '0') return result.substr(index);
        }

        return "0";
    }
};