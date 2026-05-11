#include <iostream>
#include <cmath>
using namespace std;

/*
    Một dãy số bắt đầu từ 1 và được thực hiện N-1 phép nhân đôi, được định nghĩa như sau:
    - Giả sử dãy là A thì dãy tiếp theo sẽ là A K A, trong đó K là số nguyên nhỏ nhất chưa
      xuất hiện trong dãy số của A
    - VD: N = 4
        [1] -> [1,2,1] -> [1,2,1,3,1,2,1] -> [1,2,1,3,1,2,1,4,1,2,1,3,1,2,1]

    Cho N và K, hãy tìm số ở vị trí K, trong dãy số cuối cùng sau N-1 lần nhân đôi
*/

int Find(int n, int k) {
    if (n == 0) {
        return 1;
    }
    if (k % 2 == 1) {
        return 1;
    }

    if (k < pow(2, n-1)) {
        return Find(n-1, k);
    }
    else if (k == pow(2, n-1)) {
        return n;
    }
    else {
        return Find(n-1, k - pow(2, n-1));
    }
}


int main() {
    int N, K; cin >> N >> K;

    cout << Find(5,10) << endl;
}