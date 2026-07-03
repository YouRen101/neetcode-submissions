class Solution {
public:
    int evalRPN(vector<string>& tokens){
    string s = tokens.back();
    if(s != "+" && s != "-" && s != "*" && s != "/")
        return stoi(s);
    tokens.pop_back();
    int right = evalRPN(tokens);
    tokens.pop_back();
    int left = evalRPN(tokens);
    if(s == "+")
        return left+right;
    else if(s == "-")
        return left-right;
    else if(s == "*")
        return left*right;
    else return left/right;
}
};
