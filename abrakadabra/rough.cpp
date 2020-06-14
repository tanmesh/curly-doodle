#include <bits/stdc++.h>

using namespace std;

void print_(vector<int> & a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << endl;
}


void reverse(vector<int> &A, int i) {
    int n = A.size();
    int j = n - 1;
    while (i < j) {
        swap(A[i], A[j]);
        ++i;
        --j;
    }
}

vector<int> nextPermutation(vector<int> &A) {
    int n = A.size();
    int i = n - 2;
    while (i >= 0 && A[i] >= A[i + 1]) {
        --i;
    }
    if (i >= 0) {
        int j = n - 1;
        while (j >= 0 && A[j] <= A[i]) {
            --j;
        }
        swap(A[i], A[j]);
    }
    reverse(A, i + 1);
    return A;
}


int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    nextPermutation(a);

    print_(a);
    return 0;
}
