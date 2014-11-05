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

class CandleTimerEasy {
    private:
        bool light[20];
        int degree[20];
        int ans;
        vector<int> stack;
        int time[20];
        unordered_map<double, bool> mmap;
        unordered_map<double, bool>::const_iterator got;
        int n;
        int mat[20][20];

    public:
        void check(int x)
        {
            int now;
            int length;
            int cur;
            double finish;
            double tmp;

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
                                    if(time[i]+length==time[cur]) {
                                        continue;
                                    }
                                    else {
                                        if(time[i]+length>time[cur]) {
                                            tmp = time[cur]-time[i]+1.0*(length-(time[cur]-time[i]))/2;
                                            if(tmp>finish) finish=tmp;
                                        }
                                        else {
                                            time[cur]=time[i]+length;
                                            now--;
                                            break;
                                        }
                                    }
                                }
                                else {
                                    if(time[cur]+length==time[i]) {
                                        continue;
                                    }
                                    else {
                                        if(time[cur]+length>time[i]) {
                                            tmp = time[i]-time[cur]+ 1.0*(length-(time[i]-time[cur]))/2;
                                            if(tmp>finish) finish=tmp;
                                        }
                                        else {
                                            time[i]=time[cur]+length;
                                            stack.push_back(i);
                                        }
                                    }
                                }
                            }
                            else {
                                stack.push_back(i);
                                time[i]=length + time[cur];
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
                        mmap.insert(pair<double, bool>(finish,1));
                    }
                }
            }
            else {
                light[x]=0;
                check(x+1);
                if(degree[x]==1) light[x]=1;
                check(x+1);
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
