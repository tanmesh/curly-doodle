#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#define all(a)                      a.begin(), a.end()
#define F							first
#define S							second
#define pb                          push_back
#define ll							long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std; 

int main () {
    fast
    int t;
    cin >> t;
    while(t--) {
       	int n; cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
        	cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(i%2==0) {
            	cout<<arr[n/2+i/2]<<" ";
            } else {
            	cout<<arr[n/2-(i+1)/2]<<" ";
            }

        }
        cout<<'\n';
    }
	return 0;
}