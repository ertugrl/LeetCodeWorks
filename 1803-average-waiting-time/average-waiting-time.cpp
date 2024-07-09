class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currTime = 0;
        double waitTime = 0;
        for (int i = 0; i < customers.size(); ++i) {
            int perWait = currTime - customers[i][0];
            if (perWait <= 0) {
                waitTime += customers[i][1];
                currTime += abs(perWait) + customers[i][1];
            } else {
                waitTime += perWait + customers[i][1];
                currTime += customers[i][1];
            }
        }
        return waitTime / customers.size();
    }
};