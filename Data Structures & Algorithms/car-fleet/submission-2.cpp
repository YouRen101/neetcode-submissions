class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed){
	vector<pair<int,int>> car;
	for(int i = 0 ;i < position.size(); ++i)
		car.push_back({position[i] , speed[i]});
	sort(car.rbegin() , car.rend());

	vector<float> st;
	for(auto& x : car){
		st.push_back(1.00*(target - x.first)/x.second);
		while(st.size() > 1 && st.back() <= st[st.size() - 2])
			st.pop_back();
	}
	return st.size();
}
};
