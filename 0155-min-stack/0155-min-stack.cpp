class MinStack {
public:
    stack<long long> s;
    long long minEle;

    MinStack() {
        minEle = LLONG_MAX;
    }

    void push(int x) {
        if (s.empty()) {
            s.push(x);
            minEle = x;
        }
        else {
            if (x < minEle) {
                s.push(2LL * x - minEle);
                minEle = x;
            }
            else {
                s.push(x);
            }
        }
    }

    void pop() {
        if (s.top() < minEle) {
            minEle = 2LL * minEle - s.top();
        }

        s.pop();
    }

    int top() {
        if (s.top() < minEle) {
            return (int)minEle;
        }
        else {
            return (int)s.top();
        }
    }

    int getMin() {
        return (int)minEle;
    }
};