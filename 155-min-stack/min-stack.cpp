class MinStack {
     stack<int>minstack;
      stack<int>mainstack; 
public:
    MinStack() { 
    }
    
    void push(int val) {
       mainstack.push(val);
      if(minstack.empty() || val<=minstack.top()){
        minstack.push(val);
      }  
    }
    
    void pop() {
        if(mainstack.top()==minstack.top()){
            minstack.pop();
        }
        mainstack.pop();
        
    }
    
    int top() {
      return mainstack.top();  
    }
    
    int getMin() {
       return minstack.top(); 
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