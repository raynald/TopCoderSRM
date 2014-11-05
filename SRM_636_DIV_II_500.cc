#include<vector>
#include<cstring>
#include<iostream>

using namespace std;

class SortishDiv2 {
    private:
        int n;
        int cur;
        int ans;
        bool v[110];
		int fina;
		vector<int> seq;
		
    public:
        void search(int x) {
            int tmp;
            
			if(cur > fina) return;
            if(x == n) {
            	if(cur == fina)
	                ans ++;
	            return;
            }
            if(seq[x] != 0) {
                tmp = 0;
                for(int j=0;j<x;j++) if(seq[j]>seq[x]) tmp++;
                cur += n-seq[x]-tmp;
                search(x + 1);
                cur -= n-seq[x]-tmp;
            }
            else {
                for(int i=1;i<=n;i++) {
                    if(v[i]) continue;
                    seq[x] = i;
                    v[i] = 1;
                    tmp = 0;
                    for(int j=0;j<x;j++) if(seq[j]>i) tmp++;
                    cur += n-i-tmp;
                    search(x+1);
                    seq[x] = 0;
                    v[i] = 0;
                    cur -= n-i-tmp;
                }
            }
        }

        int ways(int sortedness, vector<int> s) {
            n = s.size();
            cur = 0;
            ans = 0;
            fina = sortedness;
            seq = s;
            memset(v,0,sizeof(v));
            for(int i=0;i<s.size();i++) v[s[i]]=1;
            search(0);
            return ans;
        }
};

