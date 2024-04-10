class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        deque<int> dq;
        dq.push_front(deck[deck.size() - 1]);
        for (int i = deck.size() - 2; i >= 0; --i){
            // for dq = [11, 17, 13]
            dq.push_front(dq.back()); // 13,11,17,13
            dq.pop_back(); // 13,11,17
            dq.push_front(deck[i]); // 7,13,11,17
        }
        
        return {dq.begin(), dq.end()};
    }
};