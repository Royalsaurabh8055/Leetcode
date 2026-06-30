class MinStack {
public:
vector<pair<int,int>> v;

    MinStack() {
       
    }
    
    void push(int val) {
         if(v.empty())
        {
            v.push_back({val,val});
            return;
        }
        // non empty
        int min_till_now = min(val, v.back().second); // pair ka secomnd
        v.push_back({val, min_till_now});
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */