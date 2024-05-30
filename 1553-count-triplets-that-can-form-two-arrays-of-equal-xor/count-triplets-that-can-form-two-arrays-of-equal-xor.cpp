class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int triplets = 0;

        for (int i = 0; i < arr.size() - 1; i++){
            int curXor = arr[i];
            for (int k = i + 1; k < arr.size(); k++){
                curXor ^= arr[k];
                if (curXor == 0) triplets += k - i;
            }
        }

        return triplets;
    }
};