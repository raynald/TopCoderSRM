#include<vector>
#include<map>

using namespace std;

class NarrowPassage2 {
    private:
        struct cmp {
            int ind;
            int val;
            cmp() {}
            cmp(int x, int y) {
                ind = x;
                val = y;
            }
            bool operator<(const cmp &y) const {
                return ind<y.ind;
            }
        };

        int m;
        int ans;
        map<vector<cmp>,bool> mmap;
        map<vector<cmp>,bool>::iterator got;
    public:
        void search(vector<cmp> size) {
            vector<cmp> tmp;
            got = mmap.find(size);
            if(got==mmap.end()) {
                ans++;
                mmap.insert(pair<vector<cmp>, bool>(size,1));
                for(int i=0;i<size.size()-1;i++) {
                    if(size[i].val+size[i+1].val<=m) {
                        tmp=size;
                        tmp[i]=size[i+1];
                        tmp[i+1]=size[i];
                        search(tmp);
                    }
                }
            }
        }
        int count(vector<int> size, int maxSizeSum) {
            ans = 0;
            m = maxSizeSum;
            mmap.clear();
            vector<cmp> tmp;
            for(int i=0;i<size.size();i++)
                tmp.push_back(cmp(i,size[i]));
            search(tmp);
            return ans;
        }
};

