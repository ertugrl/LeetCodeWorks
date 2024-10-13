class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr;
        for (int i : arr) { sortedArr.push_back(i); }
        sort(sortedArr.begin(), sortedArr.end());

        unordered_map<int, int> mp;

        int x = 0;

        for (int i = 0; i < arr.size(); ++i) {
            if (mp.find(sortedArr[i]) == mp.end()) {
                mp[sortedArr[i]] = i + 1 - x;
            } else {
                x++;
            }
        }

        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = mp[arr[i]];
        }

        return arr;
    }
};