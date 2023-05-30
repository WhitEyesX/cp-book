#include <iostream>
#include <vector>
using namespace std;

char nextSymb(char chr) {
    if (chr == 'Z')
        return 'a';
    return ++chr;
}

string repeat(string s, int n) {
    string repeated;
    while (n > 0) {
        repeated += s;
        n--;
    }
    return repeated;
}

bool isPasted(string s, int i, vector<int> z) {
    int s_len = s.length();
    if (z[i] == 0 || z[i] == 1) return i < s_len;
    return i + z[i] <= s_len;
}

bool isPastedCorrectly(string s, int i, vector<int> z) {
    if (z[i] == 0 && s[0] == s[i]) return false;
    if (s.substr(0, z[i]) != s.substr(i, z[i])) return false;
    return true;
}

//TODO
string solve(vector<int> z) {
    if (z[0] != 0) return "!";

    string s = "A";
    char currentSymb = 'B';

    for (int i = 1; i < z.size(); i++) {
        if (i + z[i] > z.size()) return "!";

        if (!isPasted(s, i, z)) {
            if (z[i] == 0) {
                if (z[i - 1] != 0) {
                    currentSymb = nextSymb(currentSymb);
                }
                if (currentSymb > 'z') return "!";
                s += currentSymb;
            }
            else {
                int pastedAlready = s.length() - i;

                int copyCount = z[i] / s.length();
                int sliceLen = z[i] % s.length();

                s += repeat(s, copyCount) + s.substr(pastedAlready, sliceLen - pastedAlready);
            }
        }
        else {
            if (!isPastedCorrectly(s, i, z))
                return "!";
        }
    }

    return s;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> z(n);
        for (int i = 0; i < n; i++) {
            cin >> z[i];
        }

        cout << solve(z) << endl;
    }

    return 0;
}
