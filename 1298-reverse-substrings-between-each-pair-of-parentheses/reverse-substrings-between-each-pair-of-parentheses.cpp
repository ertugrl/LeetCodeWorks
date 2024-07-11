class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            char c;
            queue<char> q;
            if (s[i] == ')') {
                while (st.top() != '(') {
                    c = st.top();
                    st.pop();
                    q.push(c);
                }
                st.pop(); // '(' is popped

                while (!q.empty()) {
                    st.push(q.front());
                    q.pop();
                }
            } else {
                st.push(s[i]);
            }
        }
        
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

/*

Push all chars of the string
    if ')' is encountered
        pop all letters from the stack and push each of them one-by-one to temp queue
        (until '(' is encountered)
        pop chars from the queue to the 

*/