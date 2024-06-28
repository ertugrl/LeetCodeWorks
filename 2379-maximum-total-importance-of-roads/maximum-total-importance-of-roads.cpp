class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> mp;
        long long sum = 0;
        for (int i = 0; i < roads.size(); ++i) {
            mp[roads[i][0]]++;
            mp[roads[i][1]]++;
        }
        
        priority_queue<int> pq;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            pq.push(it->second);
        }

        int pq_size = pq.size();
        for (long long i = n; i > n - pq_size; --i) {
            sum += i * pq.top();
            pq.pop();
        }

        return sum;
    }
};