vector<vector<int>> dirs = {{0,1} , {0,-1} , {1,0} , {-1,0}};

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty()) return;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        
        for(int r = 0; r < m; ++r){
            for(int c = 0; c < n ; ++c)
                if(!grid[r][c]) q.push({r,c});
        }

        while(!q.empty()){
            auto[r,c] = q.front();
            q.pop();

            for(auto& d : dirs){
                int x = d[0]+r;
                int y = d[1]+c;

                if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != INT_MAX)
                    continue;
                grid[x][y] = grid[r][c]+1;
                q.push({x,y});
            }
        }
    }
};