class Solution {
public:
    int passThePillow(int n, int time) {
        int mod = (n - 1) * 2;
        int opr = time % mod;

        if (opr == 0) return 1;
        if (opr <= n - 1) return opr + 1;
        return (n << 1) - (1 + opr); // n - (opr - n)
    }
};

// 1  2
// 2  3
// 3  4
// 4  3
// 5  2
// 6  1
// 7  2
// 8  3
// 9  4
// 10 3
// 11 2
// 12 1
// 13 2