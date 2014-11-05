#include<vector>
#include<string>
#include<cstring>

using namespace std;

class ShadowSculpture {
private:
    int n;
public:
    string possible(vector<string> XY, vector <string> YZ, vector <string> ZX) {
        string tmp;
		bool flag;
		
        n = XY.size();
        bool mat[n][n][n];

        memset(mat,0,sizeof(mat));
        //XY
        for(int i=0;i<n;i++) {
            tmp = XY[i];
            for(int j=0;j<n;j++) {
                if(tmp[j]=='Y') {
                    for(int k=0;k<n;k++)
                        mat[i][j][k]=1;
                }
            }
        }
        //YZ
        for(int i=0;i<n;i++) {
            tmp = YZ[i];
            for(int j=0;j<n;j++) {
                if(tmp[j]=='Y') {
                    flag = 0;
                    for(int k=0;k<n;k++)
                        if(mat[k][i][j]) {
                            flag = 1;
                            break;
                        }
                    if(!flag) return "Impossible";
                }
                else {
                    for(int k=0;k<n;k++)
                        if(mat[k][i][j]) {
                            mat[k][i][j] = 0;
                        }
                } 
            }
        }
        //ZX
        for(int i=0;i<n;i++) {
            tmp = ZX[i];
            for(int j=0;j<n;j++) {
                if(tmp[j]=='Y') {
                    flag = 0;
                    for(int k=0;k<n;k++)
                        if(mat[i][k][j]) {
                            flag = 1;
                            break;
                        }
                    if(!flag) return "Impossible";
                }
                else {
                    for(int k=0;k<n;k++)
                        if(mat[i][k][j]) {
                            mat[i][k][j] = 0;
                        }
                } 
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++) {
                    if(mat[i][j][k]) {
                        if((i>0 && !mat[i-1][j][k]) && (i<n && !mat[i+1][j][k]) && (j>0 && !mat[i][j-1][k]) && (j<n && !mat[i][j+1][k]) && (k>0 && !mat[i][j][k-1]) && (k<n && !mat[i][j][k+1])) {
                            return "Impossible";
                        }
                    }
                }
        return "Possible";
    }
};


