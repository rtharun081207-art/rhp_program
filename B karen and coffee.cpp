#include <iostream>
#include <vector>
using namespace std;

void solve() 
{

    int n, k, q;
    cin >> n >> k >> q;

    int MAX = 200000;

    vector<int> temp(MAX + 2, 0);

    for (int i = 0; i < n; i++)
   {

        int l, r;
        cin >> l >> r;

        temp[l]++;
        temp[r + 1]--;
    }

    for (int i = 1; i <= MAX; i++) 
    {
        temp[i] += temp[i - 1];
    }

    vector<int> pref(MAX + 1, 0);

    for (int i = 1; i <= MAX; i++) 
    {

        pref[i] = pref[i - 1];

        if (temp[i] >= k) {
            pref[i]++;
        }
    }

    while (q--)
  {

        int a, b;
        cin >> a >> b;

        cout << pref[b] - pref[a - 1] << endl;
    }
}

int main() {

    solve();

    return 0;
}