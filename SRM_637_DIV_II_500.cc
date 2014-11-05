#include<vector>
#include<string>
#include<iostream>

using namespace std;

class PathGameDiv2 {
private:
    
public:
    int calc(vector<string> board) {
        int n=board[0].size();
        int row,num;
        int ans;

		row=num=n;
        for(int i=0;i<n;i ++) {
            if(board[0][i]=='#') {
                row = 1;
                num = i;
                break;
            }
            if(board[1][i]=='#') {
                row = 0;
                num = i;
                break;
            }
        }
        ans=num;
        for(int i=num;i<n-1;i++) {
            if(board[row][i+1]=='.') {
                if(board[1-row][i]=='.') {
                	board[1-row][i]='#';
                	ans++;
                }
            }
            else {
                if(board[1-row][i]=='#') return 0;
                else {
                	board[row][i]='#';
                	row=1-row;
                }
            }
        }
        if(board[1-row][n-1]=='.') ans++;
        return ans;
    }
};
