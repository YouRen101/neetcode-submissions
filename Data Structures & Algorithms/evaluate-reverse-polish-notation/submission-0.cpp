class Solution {
public:
    bool op(string s){
        return (s == "+" || s == "-" || s == "*" || s == "/");
    }

    int res(int a,int b,string ope){
        if(ope == "+") return a+b;
        if(ope == "-") return b-a;
        if(ope == "*") return a*b;
        if(ope == "/") return b/a;
        return 0;
    }

    int evalRPN(vector<string>& tokens){
        stack<int> RPN;
        for(auto& s : tokens){
            if(op(s)){
                int num1,num2;
                if(!RPN.empty()){
                    num1 = RPN.top();
                }
                if(!RPN.empty()){
                    RPN.pop();
                    num2 = RPN.top();
                    RPN.pop();
                    RPN.push(res(num1, num2,s));
                }
            }
            else{
                int n = stoi(s);
                RPN.push(n);
            }
        }
        return RPN.top();
    }
};
