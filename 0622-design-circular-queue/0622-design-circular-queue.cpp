class MyCircularQueue {
private:
    vector<int> queue;
    int front;
    int rear;
    int size;
    int capacity;
public:
    MyCircularQueue(int k) {
        capacity = k;
        size = 0;
        front = -1;
        rear = -1;
        queue.resize(capacity);
    }
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }
        if(front==-1) {
            front=0;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;
        return true;
    }
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        size--;
        return true;
    }
    int Front() {
        if(isEmpty()) {
            return -1;
        }
        return queue[front];
    }
    int Rear() {
        if(isEmpty()) {
            return -1;
        }
        return queue[rear];
    }
    bool isEmpty() {
        return size == 0;
    }
    bool isFull() {
        return size == capacity;
    }
};
