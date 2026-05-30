class MinStack {
public:
    stack<int> stk;
    stack<int> min_stk;

    MinStack() {};
    
    void push(int val) {
        stk.push(val);
        if ( min_stk.empty() ) { min_stk.push(val); }
        else if (min_stk.top() >= val) { min_stk.push(val); }
    }
    
    void pop() {
        if ( stk.top() == min_stk.top() ) { min_stk.pop(); }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};



// 4 
// 4  

/*
-5
-1
-1
-1
-4
-4
4

*/
