class MedianFinder {
    private:
        priority_queue<int> lower_moon; //min heap
        priority_queue<int , vector<int> , greater<int>> upper_moon; //max heap

    public:
        MedianFinder() {

        }   

        void addNum(int num) {
            lower_moon.push(num);
            if(upper_moon.empty() == 0 && lower_moon.top() > upper_moon.top()){
                upper_moon.push(lower_moon.top());
                lower_moon.pop();
            }
            if(lower_moon.size() > upper_moon.size()+1){
                upper_moon.push(lower_moon.top());
                lower_moon.pop();
            }
            if(upper_moon.size() > lower_moon.size()+1){
                lower_moon.push(upper_moon.top());
                upper_moon.pop();
            }
        }

        double findMedian() {
            if(upper_moon.size() == lower_moon.size())
                return double(upper_moon.top() + lower_moon.top())/2;
            else if(upper_moon.size() > lower_moon.size())
                return upper_moon.top();
            else return lower_moon.top();
        }
};
