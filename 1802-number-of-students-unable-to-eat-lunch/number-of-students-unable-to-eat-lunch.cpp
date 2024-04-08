class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // Store students in a queue
        queue<int> stu;
        for (int i: students) stu.push(i);

        // Store sandwiches in a stack
        stack<int> sand;
        for (int i = sandwiches.size() - 1; i >= 0; --i) sand.push(sandwiches[i]);

        int unpairCount = 0;
        while (!stu.empty() && unpairCount != stu.size()){
            if (stu.front() != sand.top()){ // Not match
                stu.push(stu.front());
                stu.pop();
                unpairCount++;
            } else { // Match
                stu.pop();
                sand.pop();
                unpairCount = 0;
            }
        }
        if (unpairCount == stu.size()) return unpairCount;
        else return 0;
        
    }
};