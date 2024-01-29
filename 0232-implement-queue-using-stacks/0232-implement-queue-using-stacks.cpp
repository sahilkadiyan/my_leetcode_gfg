class MyQueue {
public:
    std::stack<int> stackOrder;
    std::stack<int> queueOrder;
    
    MyQueue() {
    }

    void push(int x){
        stackOrder.emplace(x);
    }

    int pop() {
        
        queueOrder = {};

        while(stackOrder.empty() == false)
        {
            queueOrder.emplace(stackOrder.top());
            stackOrder.pop();
        }

        int returnVal = queueOrder.top();
        queueOrder.pop();

        while(queueOrder.empty() == false)
        {
            stackOrder.emplace(queueOrder.top());
            queueOrder.pop();
        }

        return returnVal;
    }

    int peek() {
       
       queueOrder = {};

       while(stackOrder.empty() == false)
       {
           queueOrder.emplace(stackOrder.top());
           stackOrder.pop();
       }

       int returnVal = queueOrder.top();

       while(queueOrder.empty() == false)
       {
           stackOrder.emplace(queueOrder.top());
           queueOrder.pop();
       }

       return returnVal;
    }

    bool empty() {
        return stackOrder.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */