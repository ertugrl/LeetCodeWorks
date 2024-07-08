class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;
        int remain, exchanged;
        while (numBottles >= numExchange) {
            remain = numBottles % numExchange;
            exchanged = numBottles / numExchange; 
            result += exchanged;
            numBottles = remain + exchanged; 
        }

        return result;
    }
};