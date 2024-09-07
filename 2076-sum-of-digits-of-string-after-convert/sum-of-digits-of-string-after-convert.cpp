class Solution {
public:
    int getLucky(string s, int k) {
        string result = "";
        for (char c : s) {
            int num = c - 'a' + 1;
            result += to_string(num);
        }

        for (int i = 0; i < k; i++) {
            result = sumOfDigits(result);
        }

        return stoi(result);
    }

    string sumOfDigits(string alphabetString) {
        int sum = 0;
        for (char c : alphabetString) {
            sum += c - '0';
            cout << sum << endl;
        }
        return to_string(sum);
    }
};