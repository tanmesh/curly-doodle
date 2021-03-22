using namespace std;

int minimumWaitingTime(vector<int> queries) {
  sort(queries.begin(), queries.end());
	
	int queriesLeft = queries.size() - 1;
	int result = 0;
	
	for(int i=1; i<queries.size(); ++i) {
		result += queriesLeft * queries[i-1];
		queriesLeft--;
	}
  return result;
}
