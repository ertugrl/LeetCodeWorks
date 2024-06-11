class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr2.size(); ++i){
            mp[arr2[i]] = 0;
        }

        for (int i = 0; i < arr1.size(); ++i){
            if (mp.find(arr1[i]) != mp.end()){
                mp[arr1[i]]++;
            }
        }

        vector<int> result;
        for (int i = 0; i < arr2.size(); ++i){
            for (int j = 0; j < mp[arr2[i]]; ++j){
                result.push_back(arr2[i]);
            }
        }
        sort(arr1.begin(), arr1.end());
        for (int i = 0; i < arr1.size(); ++i){
            if (mp.find(arr1[i]) == mp.end()){
                result.push_back(arr1[i]);
            }
        }

        return result;
    }
};