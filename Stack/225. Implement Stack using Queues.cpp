class MyStack {
private:
    queue<int> q;
    int topEle;
    
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        topEle=x;
    }
    
    int pop() {
        int size=q.size(),i,top;
        
        for(i=0;i<size-1;i++){
            topEle=q.front();
            q.push(q.front());
            q.pop();
        }
        
        top=q.front();
        q.pop();
        
        return top;
    }
    
    int top() {
        return topEle;
    }
    
    bool empty() {
        return (q.size()==0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */