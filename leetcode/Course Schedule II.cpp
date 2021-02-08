class Node {
public:
    int nodeValue;
    vector<Node*> prereq;
    bool visited;
    bool visiting;

    Node(int nodeValue) {
        this->nodeValue = nodeValue;
        prereq = {};
        visited = false;
        visiting = false;
    }
};

class Graph {
public:
    vector<Node*> nodes;
    unordered_map<int, Node*> graph;

    Graph(int numCourses) {
        nodes = {};
        for (int i = 0; i < numCourses; ++i) {
            addNode(i);
        }
    }

    void addPrereq(int x, int y) {
        Node* xNode = getNode(x);
        Node* yNode = getNode(y);
        xNode->prereq.push_back(yNode);
    }

private:
    void addNode(int nodeValue) {
        graph[nodeValue] = new Node(nodeValue);
        nodes.push_back(graph[nodeValue]);
    }

    Node* getNode(int nodeValue) {
        if (graph.find(nodeValue) == graph.end()) {
            addNode(nodeValue);
        }
        return graph[nodeValue];
    }
};

class Solution {
public:
    bool dfs(Node* node, Graph* g, vector<int> &order) {
        if (node->visited) { return false; }

        if (node->visiting) { return true; }

        node->visiting = true;

        for (auto childNode : node->prereq) {
            if (dfs(childNode, g, order)) {
                return true;
            }
        }

        node->visited = true;
        node->visiting = false;
        order.push_back(node->nodeValue);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Graph *g = new Graph(numCourses);
        for (auto prerequisite : prerequisites) {
            int x = prerequisite[0];
            int y = prerequisite[1];
            g->addPrereq(x, y);
        }

        vector<int> order;
        vector<Node*> nodes = g->nodes;
        for (auto node : nodes) {
            if (dfs(node, g, order) == true) {
                return {};
            }
        }

        return order;
    }
};