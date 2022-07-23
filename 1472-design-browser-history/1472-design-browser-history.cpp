class BrowserHistory {
    
public:
    
    vector<string> v;
    int curr,mx;
    
    BrowserHistory(string homepage) {
        v=vector<string>(5001);
        curr=0;
        mx=0;
        v[curr]=homepage;
    }
    
    void visit(string url) {
        curr++;
        v[curr]=url;
        mx=curr;
    }
    
    string back(int steps) {
        int temp=max(0,curr-steps);
        curr=temp;
        return v[curr];
    }
    
    string forward(int steps) {
        steps = min(curr+steps,mx);
        curr=steps;
        return v[steps];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */