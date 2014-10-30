#include<vector>
#include<cstring>

using namespace std;

class GreaterGame {
    public:
        double calc(vector<int> hand, vector<int> sothe) {
            double ans = 0;
            double tmp = 0;
            int num=0;
            int N=hand.size();
            bool a[N*2+1];
            int sum[N*2+1];
            memset(a,0,sizeof(a));
            memset(sum,0,sizeof(sum));
            for(int i=0;i<N;i ++) {
                a[hand[i]]=1;
                if(sothe[i]>0) {
                    a[sothe[i]]=1;
                    if(hand[i]>sothe[i]) ans++;
                }
            }
            for(int i=1;i<=2*N;i++) {
                sum[i]=sum[i-1];
                if(a[i]==0) {
                    sum[i]++;
                    num++;
                }
            }
            for(int i=0;i<N;i++) {
                if(sothe[i]==-1) {
                    tmp+= hand[i];
                }
            }
            for(int i=1;i<=num;i++) tmp/=i;
            return ans+tmp;
        }
};
