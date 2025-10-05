class Solution {
public:
    bool isValid(vector<string>&temp,int row,int col,int n) {
        //upward
        for(int i = row-1;i>=0;i--) {
            if(temp[i][col] == 'Q') return false;
        }
        //left diagonal
        for(int i = row-1, j= col-1;i>=0&&j>=0;i--,j--) {
            if(temp[i][j] == 'Q') return false;
        }
        //Right diagonal
        for(int i = row-1, j= col+1;i>=0&&j<n;i--,j++) {
            if(temp[i][j] == 'Q') return false;
        }
        return true;
    }
    void helper(vector<vector<string>>&ans, int n, vector<string>&temp, int row) {
        if(row == n) {
            ans.push_back(temp);
            return;
        }
        for(int col = 0;col<n;col++) {
            if(isValid(temp,row,col,n)) {
                temp[row][col] = 'Q';
                helper(ans,n, temp, row+1);
                temp[row][col] = '.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp(n,string(n,'.'));
        helper(ans,n, temp ,0);
        return ans;
    }
};