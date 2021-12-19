class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        this->k = k;
        this->start = 0;
        this->end = -1;
    }
    bool enQueue(int value) {
        if (isFull())
            return false;
        end = (end + 1) % k;
        this->nums[end] = value;
        return true;
    }
    bool deQueue() {
        if (isEmpty())
            return false;
        if (start == end)
        {
            start = 0;
            end = -1;
        }
        else
            start = (start + 1) % k;
        return true;
    }
    int Front() {
        if (isEmpty())
            return -1;
        return nums[start];
    }
    int Rear() {
        if (isEmpty())
            return -1;
        return nums[end];
    }
    bool isEmpty() {
        return end == -1;
    }
    bool isFull() {
        return (end + 1) % k == start && end!=-1;
    }
private:
    int nums[1000];
    int k;
    int start;
    int end;
};
