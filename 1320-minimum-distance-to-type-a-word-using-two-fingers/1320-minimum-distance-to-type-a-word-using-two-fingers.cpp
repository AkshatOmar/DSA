class Solution {
public:
    int dp[301][7][7][7][7];
    pair<int,int> getCoord(char ch) {
        int num =  ch - 'A';
        return {num/6, num%6};

    }
    int dist(int x1,int y1, int x2, int y2) {
        return abs(x1-x2) + abs(y1 - y2);
    }
    int solve(string &word, int i, int x1,int y1,int x2,int y2) {
        if(i>=word.size()) {
            return 0;
        }
        if(dp[i][x1+1][y1+1][x2+1][y2+1] != -1) return dp[i][x1+1][y1+1][x2+1][y2+1];
        auto [x,y] = getCoord(word[i]);
        // no one used
        if(x1 == -1 && y1 == -1 && x2 == -1 && y2 == -1) {
            return dp[i][x1+1][y1+1][x2+1][y2+1] = solve(word,i+1,x,y,x2,y2);
        }
        //f2 not used
        if(x2 == -1 && y2 == -1) {
            int moveF2 =  solve(word,i+1,x1,y1,x,y);
            int moveF1 = dist(x1,y1,x,y) + solve(word,i+1,x,y,x2,y2);
            return dp[i][x1+1][y1+1][x2+1][y2+1] = min(moveF1,moveF2);
        }
        int moveF1 = dist(x1,y1,x,y) + solve(word,i+1,x,y,x2,y2);
        int moveF2 = dist(x2,y2,x,y) + solve(word,i+1,x1,y1,x,y);

        return dp[i][x1+1][y1+1][x2+1][y2+1] = min(moveF1,moveF2);
    }

    int minimumDistance(string word) {
        int n = word.size();
        memset(dp,-1,sizeof(dp));
        return solve(word,0,-1,-1,-1,-1);

    }
};