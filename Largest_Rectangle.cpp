#include <bits/stdc++.h>
using namespace std;

/*
    * @class Solution
    *
    * @brief Computes the largest rectangular area possible in a histogram
    *        using brute-force and optimized stack-based approaches.
    *
    * The class provides two methods:
    *
    * 1. BruteForce():
    *      - Considers every possible subarray of bars.
    *      - Maintains the minimum height within the current range to
    *        calculate the area.
    *      - Time Complexity: O(n²)
    *      - Space Complexity: O(1)
    *
    * 2. OptimalApproach():
    *      - Uses a monotonic stack to find the nearest smaller bar
    *        to the left and right of each bar.
    *      - Precomputes:
    *          • left[i]  → index of the previous smaller element
    *          • right[i] → index of the next smaller element
    *      - The width for each bar is calculated as:
    *            right[i] - left[i] - 1
    *      - The area is then:
    *            heights[i] × width
    *      - Time Complexity: O(n)
    *      - Space Complexity: O(n)
    *
    * This optimized approach efficiently reduces the quadratic solution
    * to linear time and is widely used in stack-based problems such as
    * maximal rectangle, skyline problems, and histogram analysis.
*/

class Solution {
public:
    int BruteForce(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();

        for (int i=0; i<n; i++) {
            int minHeight = heights[i];
            for (int j=i; j<n; j++) {
                minHeight = min(minHeight, heights[j]);
                int width = j - i + 1;
                int area = minHeight * width;
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }

    int OptimalApproach(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n, 0);
        vector<int> left(n, 0);
        stack<int> stk;

        int maxArea = 0;

        // Calculate left limits
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i])
                stk.pop();

            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        // Clear the stack to reuse it for right limits
        while (!stk.empty()) stk.pop();

        // Calculate right limits
        for (int i = n-1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] >= heights[i])
                stk.pop();

            right[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }

        // Calculate max area
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

// main function
int main() {
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result = sol.BruteForce(heights);
    cout << "Largest Rectangle Area: " << result << endl;
    return 0;
}