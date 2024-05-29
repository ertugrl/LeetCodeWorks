class Solution {
public:
    int numSteps(string s) {
        int totSteps = s.size() - 2;
        for (int i = 1; i < s.size(); i++){
            if (s[i] == '1'){
                totSteps++;
                break;
            }
        }
        bool isOne = false;
        for (int i = s.size() - 1; i >= 0; i--){
            if (s[i] == '1'){
                if (i > 0) isOne = true;
                totSteps++;
                int j = i;
                while (s[j] == '1' && j > 0){
                    s[j--] = '0';
                }
                if (s[j] == '0'){
                    s[j] = '1';
                }
            }
        }


        return totSteps;
    }
};