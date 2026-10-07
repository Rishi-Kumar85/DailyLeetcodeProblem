class MyQueue {
    stack<int> s1, s2;
    public:
    MyQueue() {
    }

    void push(int x) {
        s1.push(x);
    }

    int pop() { // TC: O(n), SC: O(n)
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }

    int peek() { // TC: O(n), SC: O(n)
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }

    bool empty() { // TC: O(1), SC: O(1)
        return s1.empty();
    }
};