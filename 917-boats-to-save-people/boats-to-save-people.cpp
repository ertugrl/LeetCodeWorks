class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int right = people.size() - 1, left = 0;
        int counter = 0;
        sort(people.begin(), people.end());

        while (left < right){
            if (people[left] + people[right] <= limit){
                counter++;
                left++;
                right--;
            } else {
                counter++;
                right--;
            }
        }

        // Situation that there is only one remaining person
        if (right == left) counter++;
        
        // Situation that the sum of the weights of two remaining people exceedes the limit
        else if (people[left - 1] + people[right + 1] > limit) counter += 2;

        return counter;
    }
};