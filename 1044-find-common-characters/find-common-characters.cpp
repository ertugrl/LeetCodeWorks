class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> base;
        for (char c : words[0]){
            base[c]++;
        }

        for (int i = 1; i < words.size(); ++i){
            unordered_map<char, int> other;
            for (char c : words[i]){
                other[c]++;
            }
            for (auto& pair : base){
                if (other.find(pair.first) == other.end()){ // The char does not exist
                    base[pair.first] = 0;
                } else {
                    base[pair.first] = min(base[pair.first], other[pair.first]);
                }
            }
        }

        vector<string> result;
        for (auto& pair : base){
            while (pair.second){
                string str(1, pair.first);
                result.push_back(str);
                pair.second--;
            }
        }

        return result;
    }
};