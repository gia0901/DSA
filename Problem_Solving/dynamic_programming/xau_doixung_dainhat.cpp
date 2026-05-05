#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; cin >> s;

    int n = s.length();
    s = '@' + s;
    int F[n+1][n+1] = {0};

    for (int i = 1; i <= n; i++) {
        F[i][i] = 1;
    }

    int len = 0, max_len = 0;
    for (len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            if (len == 2) {
                F[i][j] = (s[i] == s[j]) ? 1 : 0;
            }
            else if (s[i] == s[j] && F[i+1][j-1] == 1) {
                F[i][j] = 1;
            }

            if (F[i][j] == 1) {
                max_len = max(max_len, len);
            }
        }
    }

    cout << max_len << endl;
} 