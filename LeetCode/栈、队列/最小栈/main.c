struct node
{
    int val;
    int min;
    node(int a, int b) { val = a; min = b; };
};
class MinStack {
public:
    MinStack() {

    }
    void push(int val) {
        if (size != 0 && val > getMin())
            stack.push_back(node(val, getMin()));
        else
            stack.push_back(node(val, val));
        ++size;
    }
    void pop() {
        if (size > 0)
        {
            stack.pop_back();
            --size;
        }
    }
    int top() {
        if (size > 0)
            return stack.back().val;
        return -1;
    }
    int getMin() {
        if (size > 0)
            return stack.back().min;
        return -1;
    }
private:
    vector <node> stack;
    int size=0;
};
