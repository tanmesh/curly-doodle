#include <bits/stdc++.h>

using namespace std; 

#define all(a)          a.begin(), a.end()
#define allr(a)         a.rbegin(), a.rend()
#define F				first
#define S				second
#define pb              push_back
#define ll				long long
#define f(i, a, n)		for(int i=a; i<n; ++i)
#define find(a, b)		(find(a.begin(), a.end(), b) == a.end())		
#define fast 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define watch(x) 		cout << (#x) << " is " << (x) << endl

int main () {
  	fast
  	int t;
  	cin >> t;
  	vector<int> input_cards(t);
  	int maxx_card_cnt = 0;
  	for(int i=0; i<t; ++i) {
  		cin >> input_cards[i];
  		maxx_card_cnt = max(maxx_card_cnt , input_cards[i]);
  	}
  	vector<int> cards;
  	int i=0, curr_card = 0;
  	while(curr_card < maxx_card_cnt) {
  		curr_card = curr_card + i + 2*(i+1);
  		cards.push_back(curr_card);
  		i++;
  	}
  	for(int i=0; i<input_cards.size(); ++i) {
  		int pyramid_cnt = 0;
  		curr_card = input_cards[i];
  		while(curr_card >= 2) {
  			int id = lower_bound(all(cards), curr_card) - cards.begin();
  			if(curr_card != cards[id]) {
  				--id;
  			}
  			curr_card -= cards[id];
  			++pyramid_cnt;
  		}
  		cout << pyramid_cnt << endl;
  	}
	return 0;
}