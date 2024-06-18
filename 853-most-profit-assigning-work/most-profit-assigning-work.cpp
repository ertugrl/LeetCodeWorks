class Solution {
public:
    int getProfit(vector<pair<int, int>>& works, int ability, int size) {
        // If there is no proper work for the worker
        if (works[0].first > ability) {
            return 0;
        }

        // Binary search in ordered difficulty values to find the job that is closest to the worker's ability
        // This binary search works differently than others
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
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
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
                // When there are multiple works with the same difficulty value
                // We need to update previous profit values of these works
                /* for this case, "35"
                    difficulty =
                        [23,30,35,35,35,43,46,47,81,83,98]
                    profit =
                        [8,11,11,20,25,33,37,60,72,87,95]
                    worker =
                        [95,46,47,97,11,35,99,56,41,92]
                */
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