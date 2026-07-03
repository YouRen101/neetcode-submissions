class TimeMap {
private:
    unordered_map<string , vector<pair<string ,int>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value , timestamp});
    }
    
    string get(string key, int timestamp) {
        auto& a = mp[key];
        int l = 0,r = a.size()-1;
        string res = "";
        while(l <= r){
            int m =(l+r)/2;
            if(a[m].second <= timestamp){
                res = a[m].first;
                l = m+1;
            }
            else r = m-1;
        }

        return res;
    }
};