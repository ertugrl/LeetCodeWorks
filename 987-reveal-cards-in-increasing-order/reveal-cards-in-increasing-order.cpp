class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        deque<int> dq;
        dq.push_front(deck[deck.size() - 1]);
        for (int i = deck.size() - 2; i >= 0; --i){
            // for dq = [11, 17, 13]
            int tmp = dq.back(); // tmp=13
            dq.pop_back(); // 11,17
            dq.push_front(tmp); // 13,11,17
            dq.push_front(deck[i]); // 7,13,11,17
        }
        vector<int> result;
        for (int i = 0; i < deck.size(); ++i){
            result.push_back(dq.front());
            dq.pop_front();
        }
        return result;
    }
};