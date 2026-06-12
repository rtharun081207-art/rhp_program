#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = n - 1;
    int j = m - 1;

    int count = 0;

    while (i >= 0 && j >= 0)
      {

        if (b[j] <= 2 * a[i])
        {
            count++;
            i--;
            j--;
        }
        else
        {
            j--;
        }
    }

    cout << count;
}

int main() 
{

    solve();

    return 0;
}