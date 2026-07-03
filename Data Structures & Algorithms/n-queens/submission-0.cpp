class Solution {
public:
    vector<vector<string>> res;

    void backtrack(vector<bool>& upper, vector<bool>& lower ,
            vector<bool>& main , vector<string>& brd , int r ){
        int n = brd.size();
        if(r >= n){
            res.push_back(brd);
            return;
        }

        for(int c = 0 ; c < n ; ++c){
            if(!upper[r-c+n] && !lower[r+c] && !main[c]){
                upper[r-c+n] = 1;
                lower[r+c] = 1;
                main[c] = 1;

                brd[r][c] = 'Q';
                backtrack(upper , lower , main , brd , r+1);

                brd[r][c] = '.';
                upper[r-c+n] = 0;
                lower[r+c] = 0;
                main[c] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> brd( n ,string(n,'.'));
        vector<bool> upper(2*(n-1)+1 , 0), lower(2*(n-1)+1 , 0) , main(n,0);
        backtrack(upper , lower , main , brd , 0);
        
        return res;
    }
};
