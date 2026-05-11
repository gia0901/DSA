#include <iostream>
#include <string>
using namespace std;

/*
    Các con chó được đánh số thứ tự 0,1,2... với tiếng sủa theo quy luật sau:
    D[k] = D[k-1] + g o o... + D[k-1], với cụm g o o.. sẽ gồm 1 chữ 'g' và k+2 chữ o.

    Ex: D[0] = g o o
        D[1] = g o o g o o o g o o
        D[3] = g o o g o o o g o o + g o o o o o + g o o g o o o g o o
    
    Xác định tại vị trí K bất kỳ (không biết là chó nào), ký tự là 'g' hay 'o'
*/
long long D[60] = {0};

char Find(int n, long long k) {
    // xem xét tại con chó thứ n thì k đang nằm ở vùng nào,
    // sau đó chia và đệ quy đến vùng nhỏ hơn
    if (n == 0) {
        if (k == 0) return 'g';
        else return 'o';
    }

    if (k <= D[n-1]) {
        return Find(n-1, k);
    }
    else if (k < D[n-1] + n + 3) {
        if (k == D[n-1] + 1) return 'g';
        return 'o';
    }
    else {
        return Find( n-1, k - D[n-1] - (n + 3) );
    }
}

int main() {
    int K; cin >> K;
    D[0] = 3;
    for (int i = 1; i <= 60; i++) {
        D[i] = 2 * D[i-1] + K + 3;
    }

    cout << Find(60, K);
}