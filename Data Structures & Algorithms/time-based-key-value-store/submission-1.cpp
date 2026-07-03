class TimeMap {
private:
    unordered_map<string , vector<pair<string , int>>> tm;
public:
    TimeMap() {

    }
    void set(string key, string value, int timestamp) {
        tm[key].push_back({value , timestamp});
    }
    string get(string key, int timestamp) {
        int l = 0, r = tm[key].size()-1;
        string res = "";
        while(l <= r){
            int m = (l+r)/2;
            if(tm[key][m].second <= timestamp){
                res = tm[key][m].first;
                l = m+1;
            }
            else r = m-1;
        }
        return res;
    }
};
