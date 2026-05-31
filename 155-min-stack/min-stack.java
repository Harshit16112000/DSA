class MinStack {
    Stack s;
    long minelement;
    public MinStack() {
        s = new Stack<>();
    }
    
    public void push(int val) {
        if(s.isEmpty()){
            s.push((long)val);
            minelement = (long)val;
        }
        else{
            if((long)val >= minelement)
                s.push((long)val);
            else{
                s.push(2*(long)(val)-minelement);
                minelement = (long)val;
            }
        }
    }
    
    public void pop() {
        if(s.isEmpty())
            return;
        if((long)s.peek() >= minelement)
            s.pop();
        else{
            minelement = 2*minelement - (long)s.peek();
            s.pop();
        }
    }
    
    public int top() {
        if(s.isEmpty())
            return -1;
        else{
            long top = (long)s.peek();
            if((long)s.peek() >= minelement)
                return (int)top;
            else{
                return (int)minelement;
            }
        }

    }
    
    public int getMin() {
        if(s.isEmpty())
            return -1;
        return (int)minelement;
    }
}