class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for (int i : nums) { pq.push(i); }

        long long result = 0;
        for (int i = 0; i < k; ++i) {
            int greatest = pq.top();
            result += greatest;
            pq.pop();
            pq.push(greatest % 3 == 0 ? (greatest / 3) : (greatest / 3) + 1 );
        }

        return result;
    }
};