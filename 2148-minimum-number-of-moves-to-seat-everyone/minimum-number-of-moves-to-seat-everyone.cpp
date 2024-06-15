class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int result = 0;
        for (int i = 0; i < seats.size(); ++i){
            result += abs(seats[i] - students[i]);
        }
        
        return result;
    }
};