class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> v(m, vector<int>(n ,1e4+1));
        queue<pair<int,int>> q;

        vector<pair<int,int>> neigh = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                mat[i][j] = !mat[i][j];
                if(mat[i][j]){
                    q.push({i,j});
                    v[i][j] = 0;
                } 
            }
        }
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();

            for(auto [dy, dx] : neigh){
                int a = i + dy;
                int b = j + dx;

                if(a>=0 && a<m && b>=0 && b<n && !mat[a][b]){
                    v[a][b] = min(v[a][b], v[i][j] + 1);
                    mat[a][b] = 1;
                    q.push({a,b});
                }
            }
        }
        return v;
    }
};