#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    int n = str.size();

    for(int mask = 1; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i))
                cout << str[i];
        }
        cout << endl;
    }

    return 0;
}

