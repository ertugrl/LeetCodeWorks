class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n), result;
        stack<int> stIdx;

        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(),
            [&](int lhs, int rhs) { return positions[lhs] < positions[rhs]; });

        for (int currIdx : indices) {
            if (directions[currIdx] == 'R') {
                stIdx.push(currIdx);
            } else {
                while (!stIdx.empty() && healths[currIdx] > 0) {
                    int topIdx = stIdx.top();
                    stIdx.pop();

                    // Current robot survives, top robot is destroyed
                    if (healths[topIdx] < healths[currIdx]) {
                        healths[currIdx]--;
                        healths[topIdx] = 0;

                    } else if (healths[topIdx] > healths[currIdx]) {
                        // Top robot survives, current robot is destroyed
                        healths[topIdx]--;
                        healths[currIdx] = 0;
                        stIdx.push(topIdx);

                    } else {
                        // Both robots are destroyed
                        healths[topIdx] = 0;
                        healths[currIdx] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }

        return result;
    }
};