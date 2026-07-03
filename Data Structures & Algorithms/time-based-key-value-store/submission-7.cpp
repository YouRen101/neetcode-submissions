
class TimeMap {
private:
    unordered_map<string,vector<pair<string , int>>> mp;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value , timestamp});
    }
    
    string get(string key, int timestamp) {
        int l = 0, r = mp[key].size()-1;
        string res = "";
        while(l <= r){
            int m = (l+r)/2;
            if(mp[key][m].second <= timestamp){
                res = mp[key][m].first;
                l= m+1;
            }
            else r = m-1;
        }
        return res;
    }
};
