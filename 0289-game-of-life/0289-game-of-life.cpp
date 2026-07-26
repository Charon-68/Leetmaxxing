class Solution {
    // Removed {0,0} so a cell doesn't count itself
    vector<pair<int,int>> neigh = {{-1,-1}, {-1,0}, {-1,1},
                                {0,-1},          {0,1},
                                {1,-1},  {1,0},  {1,1}};
    int check(int i, int j, vector<vector<int>>& board){
        int ans = 0;
        for(auto [dy,dx] : neigh){
            int a = i + dy;
            int b = j + dx;
            if(a >= 0 && a < board.size() && b >= 0 && b < board[0].size() && abs(board[a][b]) == 1) {
                ans++;
            }
        }
        return ans;
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
                                
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                int live = check(i, j, board);
                
                if(board[i][j] == 1){
                    if(live < 2 || live > 3) {
                        board[i][j] = -1; // Mark as "was alive, now dead"
                    }
                }
                else {
                    if(live == 3) {
                        board[i][j] = 2; // Mark as "was dead, now alive"
                    }
                }
            }
        }
        
        // Final pass to clean up our dummy transition states
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == -1) board[i][j] = 0;
                else if(board[i][j] == 2) board[i][j] = 1;
            }
        }
        return;
    }
};