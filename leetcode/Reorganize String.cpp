class Solution {
    void update(string &result, priority_queue<pair<int, char>> &pq) {
        pair<int, char> currentPair = pq.top();
        pq.pop();

        result += currentPair.second;
        --currentPair.first;
        if(currentPair.first > 0) {
            pq.push({currentPair.first, currentPair.second});    
        }
    }
public:
    string reorganizeString(string S) {
        unordered_map<char, int> map;
        for(int i=0; i<S.length(); ++i) {
            ++map[S[i]];
        }
        
        priority_queue<pair<int, char>> pq;
        for(auto it: map) {
            pq.push({it.second, it.first});
        }
        
        string result = "";
    
        while(!pq.empty()) {    
            if(result.length() == 0 || result[result.length() - 1] != pq.top().second) {
                update(result, pq);
            } else {
                pair<int, char> previousPair = pq.top();
                pq.pop();
                
                if(pq.empty()) {
                    return "";
                }
                
                update(result, pq);
                
                pq.push(previousPair);
            }
        }
        return result;
    }
};