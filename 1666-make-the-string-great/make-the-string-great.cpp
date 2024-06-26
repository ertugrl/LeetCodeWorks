class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.size(); ++i){
            if (st.empty()) st.push(s[i]);
            else if (s[i] != st.top() && toupper(st.top()) == toupper(s[i])){
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        string result;
        while (!st.empty()){
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};


/* Better solution

class Solution {
public:
    string makeGood(string s) 
    {
        string res;
        for (char c : s) {
            if (!res.empty() && (toupper(c) == toupper(res.back())) && (c - res.back() != 0)) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        
        return res;
    }
};

*/