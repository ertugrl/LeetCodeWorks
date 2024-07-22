class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> indices(names.size());
        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(), [&](int lhs, int rhs) {
            return heights[lhs] > heights[rhs];
        });

        vector<string> sortedNames(names.size());
        for (int i = 0; i < names.size(); ++i) {
            sortedNames[i] = names[indices[i]];
        }

        return sortedNames;
    }
};