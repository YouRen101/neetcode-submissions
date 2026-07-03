class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board){
	unordered_set<int> cols[9];
	unordered_set<int> rows[9];
	unordered_set<int> boxes[9];
	for(int r = 0; r < 9; ++r){
		for(int c = 0; c < 9; ++c){
			int val = board[r][c];
			if(val == '.') continue;
			int boxIndex = (r/3)*3 + c/3;
			if(rows[r].count(val) || cols[c].count(val) || boxes[boxIndex].count(val))
				return 0;
			rows[r].insert(val);
			cols[c].insert(val);
			boxes[boxIndex].insert(val);
		}
	}
	return 1;
}
};
