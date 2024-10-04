class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum = 0;
        long long chem = 0;
        int n = skill.size();

        sort(skill.begin(), skill.end());
        int targetSum = skill[0] + skill[n - 1];

        for (int i = 0; i < n / 2 ; ++i) {
            long long currentSum = skill[i] + skill[n - i - 1];
            if (targetSum != currentSum) {
                return -1;
            }

            chem += (long long) skill[i] * (long long) skill[n - i - 1];
        }
        return chem;
    }
};

/*

i1 * i2 = A,     S = A ^ (n/2)
calculate the multiplication of every number => S
360


*/