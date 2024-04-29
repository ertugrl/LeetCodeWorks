class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> digit;
        int result = 0;
        // Perform a bitwise XOR operation between each pair of integers
        for (int i: nums){
            result ^= i;
        }

        // !!! this gives the number of different bits
        result ^= k;

        // Calculate how many 1's in the result
        int counter = 0;
        while (result){
            counter += result % 2; 
            result /= 2;
        }
        return counter;
    }
};