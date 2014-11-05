/**
 * Read the problem careful.
 *
 * Only ignite the leaves!!!
 */
#include<cstring>
#include<vector>
#include<unordered_map>
#include<iostream>

using namespace std;

class CandleTimer {
    private:
        bool light[200];
        int degree[200];
        int ans;
        vector<int> stack;
        int time[200];
        unordered_map<int, bool> mmap;
        unordered_map<int, bool>::const_iterator got;
        int n;
        int mat[200][200];

    public:
        void check(int x)
        {
            int now;
            int length;
            int cur;
            int finish;
            int tmp;

            if(x==n+1) {
                finish=0;
                stack.clear();
                for(int i=0;i<=n;i++) {
                    if(light[i]==1) {
                        stack.push_back(i);
                        time[i]=0;
                    }
                    else time[i]=-1;
                }
                now = 0;
                while(now<stack.size()) {
                    cur = stack[now];
                    for(int i=0;i<=n;i++) {
                        length = mat[cur][i];
                        if(length>0) {
                            if(time[i]>=0) {
                                if(time[cur]>time[i]) {
                                    if(time[i]+length*2==time[cur]) {
                                        continue;
                                    }
                                    else {
                                        if(time[i]+length*2>time[cur]) {
                                            tmp = (time[cur]-time[i])*2+(length-(time[cur]-time[i]));
                                            if(tmp>finish) finish=tmp;
                                        }
                                        else {
                                            time[cur]=time[i]+length*2;
                                            now--;
                                            break;
                                        }
                                    }
                                }
                                else {
                                    if(time[cur]+length*2==time[i]) {
                                        continue;
                                    }
                                    else {
                                        if(time[cur]+length*2>time[i]) {
                                            tmp = (time[i]-time[cur])*2+ (length-(time[i]-time[cur]));
                                            if(tmp>finish) finish=tmp;
                                        }
                                        else {
                                            time[i]=time[cur]+length*2;
                                            stack.push_back(i);
                                        }
                                    }
                                }
                            }
                            else {
                                stack.push_back(i);
                                time[i]=length*2 + time[cur];
                            } 
                        }
                    }
                    now++;
                }           
                for(int i=0;i<=n;i++) {
                    if(time[i]>finish) finish=time[i];
                }
                if(finish!=0) {
                    got = mmap.find(finish);
                    if(got==mmap.end()) {
                        ans++;
                        mmap.insert(pair<int, bool>(finish,1));
                    }
                }
            }
            else {
                light[x]=0;
                check(x+1);
                if(degree[x]==1) {
                    light[x]=1;
                    check(x+1);
                }
            }
        }

        int differentTime(vector<int> A, vector<int> B, vector<int> len) {
            n = A.size();       
            memset(mat,-1,sizeof(mat));
            memset(degree,0,sizeof(degree));
            mmap.clear();
            ans = 0;
            for(int i=0;i<n;i++) {
                degree[A[i]]++;
                degree[B[i]]++;
                mat[A[i]][B[i]]=len[i];
                mat[B[i]][A[i]]=len[i];
            }
            check(0);
            return ans;
        }
};

int main() {
    CandleTimer sol;
    vector<int> A;
    vector<int> B = {0,1,2,0,0,0,1,0,0,0,2,5,4,7,13,13,6,15,11,18,19,21,22,16,19,19,20,18,22,27};
    vector<int> len = {59,58,147,169,34,14,150,55,156,151,130,109,124,15,100,1,156,16,38,97,99,132,150,18,27,91,110,127,15,105};
    for(int i=1;i<=30;i++) A.push_back(i);
    cout << sol.differentTime(A, B, len) << endl;
    return 0;
}
