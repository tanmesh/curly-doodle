#define WHITE 0
#define BLACK 1

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, int> colour;
        queue<int> bfsQueue;

        for (int i = 0; i < graph.size(); ++i) {
            if (colour.find(i) != colour.end()) {
                continue;
            }
            colour[i] = WHITE;
            bfsQueue.push(i);

            while (!bfsQueue.empty()) {
                int currNode = bfsQueue.front();
                bfsQueue.pop();

                for (auto childNode : graph[currNode]) {
                    if (colour.find(childNode) != colour.end()) {
                        if (colour[childNode] == colour[currNode]) {
                            return false;
                        }
                    } else {
                        bfsQueue.push(childNode);
                        colour[childNode] = (colour[currNode] + 1) % 2;
                    }

                }
            }
        }

        return true;
    }
};