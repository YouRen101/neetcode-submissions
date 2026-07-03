class Solution {
public:
    string encode(vector<string>& strs){
        string str = "";
        for(auto& s : strs)
            str += to_string(s.size()) + "#" + s;
        /*dùng dấu # để phân tách giữa số và string vì chẳng may string dày đến
        1000 chữ số chứ đâu chỉ là phần tử đầu trong string*/
        return str;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#')
                j++;
            int length = stoi(s.substr(i , j-i));
            i = j+1;
            j = i+length;
            res.push_back(s.substr(i,j-i));
            i = j;
        }
        return res;
    }
};
