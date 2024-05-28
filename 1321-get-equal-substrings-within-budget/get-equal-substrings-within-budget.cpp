class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> cost(n);
        
        // Calculate the cost array
        for (int i = 0; i < n; i++) {
            cost[i] = abs(s[i] - t[i]);
        }
        
        int maxLength = 0;
        int currentCost = 0;
        int start = 0;
        
        for (int end = 0; end < n; end++) {
            currentCost += cost[end];
            
            // If the currentCost exceeds maxCost, shrink the window from the left
            while (currentCost > maxCost) {
                currentCost -= cost[start];
                start++;
            }
            
            // Calculate the length of the current valid substring
            maxLength = max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }
};
