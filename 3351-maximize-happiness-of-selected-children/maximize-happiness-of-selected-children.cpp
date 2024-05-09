class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        map<int, int, greater<int>> mp;
        for (int i = 0; i < happiness.size(); i++){
            mp[happiness[i]]++;
        }

        int selNum = 0;
        long long result = 0;
        for (auto &it: mp){
            if (selNum == k || it.first - selNum <= 0) break;
            for (int i = 0; i < it.second; i++){
                if (selNum == k || it.first - selNum <= 0) break;
                result += it.first - selNum++;
            }
        }

        return result;
    }
};