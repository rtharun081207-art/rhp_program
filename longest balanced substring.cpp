#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {

        int z = 0, o = 0, l = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '0') {

                if (i > 0 && s[i - 1] == '1') {
                    z = 0;
                    o = 0;
                }

                z++;
            }
            else {

                o++;

                l = max(l, 2 * min(z, o));
            }
        }

        return l;
    }
};

int main() {

    string s;

    cout << "Enter binary string: ";
    cin >> s;

    Solution obj;

    int result = obj.findTheLongestBalancedSubstring(s);

    cout << "Length of Longest Balanced Substring: " << result << endl;

    return 0;
}