class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        vector<pair<int,int>> neigh = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        int ans = -1;
        q.push({-1,-1});
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();

            if(i == -1 && j == -1){
                ans++ ;
                if(q.empty()) break;
                else q.push({-1,-1});
            }
            else{
                for(auto [dy,dx] : neigh){
                    int y = i + dy;
                    int x = j + dx;
                    if(y>=0 && y<m && x>=0 && x<n && grid[y][x] == 1){
                        grid[y][x] = 2;
                        q.push({y,x});
                    }
                }
            }
        }
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};