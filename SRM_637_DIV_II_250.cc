#include<vector>
#include<cstring>

using namespace std;

class GreaterGameDiv2 {
    public:
        int calc(vector<int> hand, vector<int> sothe) {
	        int ans = 0;
            for(int i=0;i<hand.size();i++) {
            	if(hand[i]>sothe[i]) {
            		ans++;
            	}
            }
            return ans;
        }
};
