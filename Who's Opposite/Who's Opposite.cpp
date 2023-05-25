#include <iostream>
using namespace std;

int solve(int a, int b, int c) {
    if (a > b) swap(a, b);
    int preA = a - 1, range = b - a, len = range * 2;
    if (preA > range - 1 || c > len) return -1;
    return (c + range) / len + (c + range) % len; 
}

int main()
{
    int n;
    cin >> n;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << "Ans: " << solve(a, b, c) << "\n";
    }
}

