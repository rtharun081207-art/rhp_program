#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = height[0];

        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        rightMax[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int w = 0;

        for (int i = 0; i < n; i++) {
            w += min(leftMax[i], rightMax[i]) - height[i];
        }

        return w;
    }
};

int main() {

    int n;

    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> height(n);

    cout << "Enter heights: ";

    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    Solution obj;

    int result = obj.trap(height);

    cout << "Total Trapped Rain Water: " << result << endl;

    return 0;
}