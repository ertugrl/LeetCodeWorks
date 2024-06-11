class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (hand.size() % groupSize != 0) return false;
        unordered_map<int, int> mp;
        for (int i = 0; i < hand.size(); ++i){
            mp[hand[i]]++;
        }
        vector<int> v;
        for (auto& pair : mp){
            v.push_back(pair.first);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); ++i){
            while (mp[v[i]] > 0) { // Starting point
                for (int k = 0; k < groupSize; ++k) { // remaining elements
                    if (mp[v[i] + k] == 0) return false; // There is no consecutive element 
                    mp[v[i] + k]--;
                }
            }
        }

        return true;
    }
};

// 1,2,3,6,2,3,4,7,8
// 1 2 2 1 1 1 1
// 1 2 3 4 6 7 8
// 1 1 2 1 1 1 1

/*
v.size = 2
groupSize = 2
i 0
k 1

1 2 3
2 2 2
1 1 2
0 0 2


*/