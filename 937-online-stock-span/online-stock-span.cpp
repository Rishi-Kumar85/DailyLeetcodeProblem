class StockSpanner {
public:

    // {price, span}
    stack<pair<int, int>> st;

    StockSpanner() {
    }

    int next(int price) {

        int span = 1;

        // Merge all previous prices
        // that are <= today's price
        while (!st.empty() &&
               st.top().first <= price) {

            span += st.top().second;

            st.pop();
        }

        st.push({price, span});

        return span;
    }
};