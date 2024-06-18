class Solution {
public:
    int getProfit(vector<pair<int, int>>& works, int ability, int size) {
        // If there is no proper work for the worker
        if (works[0].first > ability) {
            return 0;
        }

        // Binary search in ordered difficulty values to find the job that is closest to the worker's ability
        int left = 0, mid = 0, right = size;
        while (left <= right) {
            mid = (left + right) / 2;
            if (works[mid].first == ability) {
                return works[mid].second;
            }
            if (left == mid) {
                return works[mid].second;
            }

            // Update the boundaries
            if (works[mid].first < ability ) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return 0;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> works;
        int size = profit.size();
        for (int i = 0; i < size; ++i) {
            works.push_back(pair(difficulty[i], profit[i]));
        }

        // This is actually not necessary, sort() function does this by default (ordering by first values)
        sort(works.begin(), works.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first < b.first;
        });

        // Update max profit that can be obtained from any job with current diffc.
        int maxProf = 0;
        for (int i = 0; i < size; ++i) {
            if (works[i].second > maxProf) {
                maxProf = works[i].second;
                int tmp = i;
                while (tmp > 0 && works[tmp - 1].first == works[tmp].first) {
                    works[tmp-- - 1].second = maxProf;
                }
            } else {
                works[i].second = maxProf;
            }
            cout << works[i].second << endl;
        }

        int result = 0;
        for (int i = 0; i < worker.size(); ++i) {
            cout << worker[i] << " =>" << getProfit(works, worker[i], size) << endl;
            result += getProfit(works, worker[i], size);
        }

        return result;
    }
};