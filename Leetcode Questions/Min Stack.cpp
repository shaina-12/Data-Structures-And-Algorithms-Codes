class MinStack {
    vector<int> stack;
    int size;
public:
    MinStack() {
        this->size=0;
    }
    
    void push(int val) {
        stack.push_back(val);
        size++;
    }
    
    void pop() {
        if(size==0){
            return;
        }
        stack.pop_back();
        size--;
    }
    
    int top() {
        if(size==0){
            return INT_MIN;
        }
        return stack[size-1];
    }
    
    int getMin() {
        if(size==0){
            return INT_MIN;
        }
        return *min_element(stack.begin(),stack.end());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
