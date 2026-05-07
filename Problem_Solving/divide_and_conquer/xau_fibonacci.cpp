#include <iostream>
#include <string>
using namespace std;

/**
 * @brief   Xâu fibonacci có F[1] = "A", F[2] = "B"
 *           F[3] = F[1] + F[2] = "AB"
 *           F[4] = F[2] + F[3] = "BAB"
 *           F[5] = F[3] + F[4] = "AB" + "BAB"
 *           F[6] = F[4] + F[5] = "BAB" + "ABBAB"
 *          ...
 *          Hãy cho biết tại F[n], vị trí thứ k trong xâu là ký tự gì?
 * 
 * @details - Ta xác định được quy luật: tại n, xâu chắc chắn có F[n] ký tự. (F[6] = 8 ký tự)
 *            Vậy k sẽ nằm trong index [1,n]
 *          - Mà F[n] = F[n-2] + F[n-1] => k sẽ nằm ở 1 trong 2 phần
 *            => Sử dụng divide & conquer nhằm chia nhỏ vùng tìm kiếm cho đến khi chia nhỏ nhất thành F[1], F[2]
 */


long long fibo[100];

char Find(long long n, long long k) {
    if (n == 1) return 'A';
    if (n == 2) return 'B';

    if (k <= fibo[n-2]) {
        return Find(n-2, k); // xét F[n-2], vì F[n-2] đứng trước nên ký tự thứ k vẫn giữ nguyên
    }
    else {
        return Find(n-1, k - fibo[n-2]); // xét F[n-1], bỏ qua số ký tự của F[n-2] để bắt đầu tính từ F[n-1]
    }
}

int main() {
    // xây dựng các số fibonacci
    fibo[1] = 1;
    fibo[2] = 1;
    for (int i = 2; i <= 100; i++) {
        fibo[i] = fibo[i-2] + fibo[i-1];
    }

    cout << Find(6, 5) << endl;
}