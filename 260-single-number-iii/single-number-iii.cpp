class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR = 0;
        for (int i = 0; i <  nums.size(); ++i){
            XOR ^= nums[i];
        }

        cout << XOR;

        int trailingZeros = __builtin_ctz(XOR); // 1000 => 3

        vector<int> G0; // Group with bit 0 according to the index where the rightmost 1 bit of the XOR is located
        vector<int> G1; // Group with bit 1 according to the index where the rightmost 1 bit of the XOR is located

        for (int i = 0; i < nums.size(); ++i){
            if ((nums[i] >> trailingZeros) % 2 == 0) G0.push_back(nums[i]);
            else G1.push_back(nums[i]);
        }

        vector<int> result;
        XOR = 0;
        for (int i = 0; i < G0.size(); ++i){
            XOR ^= G0[i];
        }
        result.push_back(XOR);

        XOR = 0;
        for (int i = 0; i < G1.size(); ++i){
            XOR ^= G1[i];
        }
        result.push_back(XOR);

        return result;
    }
};