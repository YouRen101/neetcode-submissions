vector<vector<int>> dirs = {{0,1} , {0,-1} , {1,0} , {-1,0}};

class Solution {
public:
    vector<int> labs = vector<int>(15001, -1);

    int find_set(int v){
        return labs[v] < 0 ? v : labs[v] = find_set(labs[v]);
    }

    bool uni_set(int a,  int b){
        a = find_set(a);
        b = find_set(b);

        if(a != b){
            if(labs[a] > labs[b]) swap(a,b);
            labs[a] += labs[b];
            labs[b] = a;
            return 1;
        }

        return 0;
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;         

        int n = grid.size();
        int m = grid[0].size();
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < m; ++c){
                if(grid[r][c] == '1'){
                    res++;
                    for(auto& d : dirs){
                         int x = d[0]+r;
                         int y = d[1]+c;
                         if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == '1'
                                 && uni_set(r*101 + c, x*101 + y))
                                 res--;
                    }
                }
            }
        }
        
        return res;
    }
};
