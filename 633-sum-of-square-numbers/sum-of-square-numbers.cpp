class Solution {
public:
    bool judgeSquareSum(long long c) {
        long long sqr = static_cast<long long>(sqrt(c >> 1));
        if (sqr * sqr == c >> 1 && !(c & 1)) {
            return true;
        }

        long long small = sqr;
        long long large = sqr + 1;
        long long control;
        while (small >= 0) {
            control = pow(small, 2) + pow(large, 2);
            if (control == c) {
                return true;
            } else if (control < c) {
                large++;
            } else {
                small--;
            }
        }

        return false;
    }
};