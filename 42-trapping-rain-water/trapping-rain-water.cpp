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


/* Simpler solution from someone

class Solution {
public:
    //total water is trapped into the bars
    int trap(vector<int>& h) {
        int l=0,r=h.size()-1,lmax=INT_MIN,rmax=INT_MIN,ans=0;
        while(l<r){
            lmax=max(lmax,h[l]);
            rmax=max(rmax,h[r]);
            ans+=(lmax<rmax)?lmax-h[l++]:rmax-h[r--];
        }
        return ans;
    }
};

*/