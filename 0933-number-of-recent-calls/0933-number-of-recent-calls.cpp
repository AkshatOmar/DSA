class RecentCounter {
public:
    int i;
    vector<int>arr;
    RecentCounter() {
        i = 0;
    
    }
    
    int ping(int t) {
        arr.push_back(t);
        while(arr[i] < t-3000) {
            i++;
        }
        return arr.size()-i;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */