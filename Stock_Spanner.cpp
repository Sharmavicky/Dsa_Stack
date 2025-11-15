#include <bits/stdc++.h>
#include <stack>
using namespace std;

/*
    * @class StockSpanner
    * @brief A data structure that computes the stock span for each incoming price.
    *
    * The StockSpanner class processes stock prices in an online manner and
    * returns the span of each price — the count of consecutive previous days
    * where the stock price was less than or equal to the current price.
    *
    * It maintains a monotonic decreasing stack of {price, span} pairs.
    * For each new price:
    *   - Pop all entries with prices <= the current price.
    *   - Accumulate their spans.
    *   - Push the current price with its computed span.
    *
    * This achieves amortized O(1) time per operation.
*/

class StockSpanner {
private:
    stack<pair<int, int>> st;

public:
    StockSpanner() {
        while (!st.empty()) {
            st.pop();
        }
    }

    int next(int price) {
        int span = 1;

        // Merge spans of all previous prices <= current
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};