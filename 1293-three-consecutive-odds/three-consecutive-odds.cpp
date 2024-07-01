class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int counter = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] & 1 == 1) {
                counter++;
                if (counter == 3) return true;
            } else {
                counter = 0;
            }
        }
        return false;
    }
};