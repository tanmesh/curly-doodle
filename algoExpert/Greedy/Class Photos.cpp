#include <vector>
using namespace std;

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
	sort(redShirtHeights.begin(), redShirtHeights.end());
	sort(blueShirtHeights.begin(), blueShirtHeights.end());
	
  int dir = redShirtHeights[0] - blueShirtHeights[0];
	for(int i=0; i<redShirtHeights.size(); ++i) {
		int thisDir = redShirtHeights[i] - blueShirtHeights[i];
		if(thisDir * dir <= 0) {
			return false;
		}
	}
  return true;
}
