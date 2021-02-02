int findBackEndSum(vector<int> &A, int bound, int i) {
	int elementCnt = 0;
	int sum = 0;
	while (elementCnt < bound) {
		sum += A[i];
		++elementCnt;
		--i;
	}
	return sum;
}

int findFrontEndSum(vector<int> &A, int bound, int i) {
	int elementCnt = 0;
	int sum = 0;
	while (elementCnt < bound) {
		sum += A[i];
		++elementCnt;
		++i;
	}
	return sum;
}

int Solution::solve(vector<int> &A, int B) {
	int ans = INT_MIN;

	int frontEndSum = findFrontEndSum(A, B, 0);
	int backEndSum = 0;

	ans = max(ans, frontEndSum + backEndSum);

	int frontEndBound = B - 1;
	int i = B - 1;
	while (i >= 0) {
		frontEndSum = frontEndSum - A[i];
		backEndSum = findBackEndSum(A, B - i, A.size() - 1);
		ans = max(ans, frontEndSum + backEndSum);
		i--;
	}

	return ans;
}
