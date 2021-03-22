#include <vector>
using namespace std;

vector<vector<int>> taskAssignment(int k, vector<int> tasks) {
  vector<pair<int, int>> tasksWithPos;
	for(int i=0; i<tasks.size(); ++i) {
		tasksWithPos.push_back({tasks[i], i});
	}
	sort(tasksWithPos.begin(), tasksWithPos.end());
	
	vector<vector<int>> result;
	int n = tasksWithPos.size();
	for(int i=0; i<(n+1)/2; ++i) {
		result.push_back({tasksWithPos[i].second,tasksWithPos[n - 1 - i].second});
	}
	
  return result;
}
