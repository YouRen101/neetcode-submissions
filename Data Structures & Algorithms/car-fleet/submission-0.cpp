class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed){
    vector<double> stack;
    vector<pair<int,int>> car;
    for(int i =0; i < position.size(); ++i)
        car.push_back({position[i] , speed[i]});
    sort(car.rbegin() , car.rend());
    for(auto& x : car){
        stack.push_back(1.00*(target-x.first)/x.second);
        if(stack.size() > 1 &&  stack.back() <= stack[stack.size()-2])
        stack.pop_back();
    }
    return stack.size();
}
};
