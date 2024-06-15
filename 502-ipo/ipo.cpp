class Solution {
public:
    static bool comparator(const pair<int, int>& a, const pair<int, int>& b){
        return a.first < b.first;
    }

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < profits.size(); ++i){
            pairs.push_back(pair(capital[i], profits[i]));
        }

        sort(pairs.begin(), pairs.end(), comparator);

        priority_queue<int> pq;

        int cur = 0;
        for (int i = 0; i < k; ++i){
            while (cur < pairs.size() && w >= pairs[cur].first){
                pq.push(pairs[cur].second);
                cur++;
            }

            if (pq.empty()){
                break;
            }

            w += pq.top();
            pq.pop();
        }

        return w;
    }
};