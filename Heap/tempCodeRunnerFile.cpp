#include <iostream>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    if (k == 1)
    {
        if (n == 0 || n % 4 == 0)
        {
            cout << "On" << endl;
        }
        else
        {
            cout << "Ambiguous" << endl;
        }
    }
    else
    {
        if (n == 0 || n % 4 == 0)
        {
            cout << "off" << endl;
        }
        else
        {
            cout << "On" << endl;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}