class MinStack {
private:
    stack<int> st;
    stack<int> ms;
public:
    MinStack() {

    }

    void push(int val) {
        st.push(val);
        val = min(val , ms.empty() ? val : ms.top());
        ms.push(val);
    }

    void pop() {
        st.pop();
        ms.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return ms.top();
    }
};