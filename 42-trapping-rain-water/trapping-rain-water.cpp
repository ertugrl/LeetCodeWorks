class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;

        int left = 0, right, water = 0;
        // From left to right
        for (right = 1; right < height.size(); ++right){
            if (height[left] <= height[right]){
                for (int i = left + 1; i < right; ++i){
                    water += min(height[left], height[right]) - height[i];
                }
                left = right;
            }
        }

        // From right to max elevation's index
        int maxElvt = left;
        // Since right=height.size() in the end of 1st for loop
        right--;
        for (left = right - 1; left >= maxElvt; --left){
            if (height[right] <= height[left]){
                for (int i = right - 1; i > left; --i){
                    water += min(height[left], height[right]) - height[i];
                }
                right = left;
            }
        }

        return water;
    }
};

/*
3 0 1 2 1 2 1

#
# * * # * # *
# * # # # # #

*/

/*
4  2  0  3  2  5

          #
# * * * * #
# * * # * #
# # * # # #
# # * # # #

*/