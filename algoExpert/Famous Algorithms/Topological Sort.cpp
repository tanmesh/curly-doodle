#include <vector>
#include <stack>
using namespace std;

/*
	Node class
*/
class JobNode {
public:
	int job;
	vector<JobNode* > prereqs;
	bool visited;
	bool visiting;

	JobNode(int job) {
		this->job = job;
		prereqs = {};
		visited = false;
		visiting = false;
	}
};

/*
	JobGraph

	Graph class made up using Node class

	member functions:
		addPrereq --- make Adjacency List
		addNode 	--- make a Node object
		getNode		---	returns Node object
*/
class JobGraph {
public:
	vector<JobNode* > nodes;
	unordered_map<int, JobNode* > graph;

	JobGraph(vector<int> jobs) {
		nodes = {};
		for (auto job : jobs) {
			addNode(job);
		}
	}

	void addPrereq(int job, int prereq) {
		JobNode *jobNode = getNode(job);
		JobNode *prereqNode = getNode(prereq);
		jobNode->prereqs.push_back(prereqNode);
	}

private:
	void addNode(int job) {
		graph[job] = new JobNode(job);
		nodes.push_back(graph[job]);
	}

	JobNode *getNode(int job) {
		if (graph.find(job) == graph.end()) {
			addNode(job);
		}
		return graph[job];
	}
};

bool depthFirstTraversal(JobNode *node, vector<int> *orderedJobs) {
	if (node->visited) {
		return false;
	}
	if (node->visiting) {
		return true;
	}
	node->visiting = true;
	for (JobNode *prereqNode : node->prereqs) {
		if (depthFirstTraversal(prereqNode, orderedJobs)) {
			return true;
		}
	}
	node->visited = true;
	node->visiting = false;
	orderedJobs->push_back(node->job);
	return false;
}

vector<int> getOrderedJobs(JobGraph *graph) {
	vector<int> orderedJobs = {};
	vector<JobNode *> nodes = graph->nodes;
	for (auto node : nodes) {
		if (depthFirstTraversal(node, &orderedJobs)) {
			return {};
		}
	}
	return orderedJobs;
}

JobGraph *createJobGraph(vector<int> &jobs, vector<vector<int>> &deps) {
	JobGraph *graph = new JobGraph(jobs);
	for (auto dep : deps) {
		graph->addPrereq(dep[1], dep[0]);
	}
	return graph;
}

/*
	Main Function
*/
vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
	JobGraph *jobGraph = createJobGraph(jobs, deps);
	return getOrderedJobs(jobGraph);
}

