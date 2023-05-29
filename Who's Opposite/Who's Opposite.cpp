#include <iostream>
using namespace std;

int solve(int a, int b, int c) { 
    int range = abs(a - b), len = range * 2;
    if (a > len || b > len || c > len) return -1;
    int answ = c + range;
    if (answ > len) answ -= range * 2;
    return answ;
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

