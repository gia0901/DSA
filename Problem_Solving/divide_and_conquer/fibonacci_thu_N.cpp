#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

struct Matrix {
    ll a[2][2];
    friend Matrix operator*(Matrix x, Matrix y) {
        Matrix res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                res.a[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    res.a[i][j] += x.a[i][k] + y.a[k][j];
                    res.a[i][j] %= mod;
                }
            }
        }
        
        return res;
    }
};

Matrix binPow(Matrix A, ll n) {
    if (n == 1) return A;

    Matrix X = binPow(A, n/2);
    if (n % 2 == 1) {
        return X * X * A;
    }
    else {
        return X * X;
    }
}

int main() {
    Matrix A;
    A.a[0][0] = A.a[0][1] = A.a[1][0] = 1;
    A.a[1][1] = 0;

    ll n; cin >> n;
    Matrix res = binPow(A, n);

    cout << res.a[0][1] << endl;
}