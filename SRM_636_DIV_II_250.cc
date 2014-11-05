#include<vector>

using namespace std;

class GameOfStones {
    public:
        int count(vector<int> stones) {
            int n;
            int sum=0;
            int ans = 0;
            n = stones.size();
            for(int i=0;i<n;i++) {
                sum += stones[i];
            }
            if(sum%n!=0) return -1;
            sum /= n;
            for(int i=0;i<n;i++) {
                if(stones[i]<sum) {
                    if((sum-stones[i])%2!=0) return -1;
                    ans += (sum-stones[i])/2;
                }
            }
            return ans;
        }
}
