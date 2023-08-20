#include <iostream>
#include <cstring>
#include <cstdlib>

// 蛋糕切割 没ac 再看看吧！

using namespace std;

const int N = 1e3;

int row[N], col[N]; // 存储每行/列的和
int d[N]; //临时存储前缀和

int min_diff(int *arr, int n) {
    if (n == 1) { return 0x7fffffff; }
    else if (n == 2) { return abs(arr[0] - arr[1]); }
    for (int i = 0; i < n; i++) {
        if (i == 0) { d[i] = arr[0]; }
        else { d[i] += (arr[i] + d[i - 1]); }
//        cout << d[i] <<"-";
    };
    int back = 0, ret = 0x7fffffff;
    for (int i = n - 1; i >= 1; i--) {
        back += arr[i];
//        cout << back <<".";
        ret = min(ret, abs(back - d[i - 1]));
    };
    return ret;
}

int main() {
    int n, m, num; // 行列
    while (cin >> n >> m) {
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << "(i,j)=" << i<<" "<<j<<endl;
                cin >> num;
                row[i] += num;
                col[j] += num;
            }
        }
//        cout <<"ok";
//        cout << min_diff(row,n)<<endl;
//        cout << min_diff(col,m)<<endl;
        if (n == 1 && m == 1) {
            cout << num;
        } else {
            cout << min(min_diff(row, n), min_diff(col, m));
        }
    }
}

// badcase : 669 821 2236 2086 2003 7822 9963 6867 4098 3667 6785 2057 6866 5984 8962 6020 860 9022 9036 1931 3043 7197 7994 481 7590 9648 9364 1043 7445 6566 8272 3042 5053 104 790 7898 327 3678 9400 3197 9218 3533 9419 54 3328 345 8512 3625 1185 7849 8491 1354 5432 8768 980 5216 7119 4109 2825 6423 5987 5117 9457 7005 8712 9721 2647 2623 9694 8512 2787 7715 2426 8404 8284 4282 5028 1761 5687 298 432 638 1047 7922 7915 3414 9554 2335 7135 4560 8354 655 9507 5450 4981 1939 240 2963 2309 5070 2802 8367 4354 4287 4015 9050 6365 3741 280 1055 1233 5330 2497 3995 223 1711 5404 4034 4654 238 8242 5786 6683 7271 3555 5771 2079 4171 9320 9512 4698 9522 8603 7938 9654 2855 2783 4061 6364 4780 614 9888 6433 9739 393 7753 1353 8238 3748 5207 6156 4962 5193 1987 3772 6599 7220 7121 2092 4117 4411 9894 8057 3097 4875 7038 8385 2230 8690 147 144 4626 7992 6250 9791 7284 8312 514 1648 3338 222 533 325 385 6982 9910 7185 8892 2781 849 886 6366 2335 7267 4843 4268 5299 2563 9412 6924 5461 8827 2371 4442 7920 604 4031 8100 2330 3172 5893 7108 9679 1800 5080 5667 6321 1288 9480 7300 4604 106 5538 587 1865 3357 8349 5577 8541 3784 8111 4497 3320 4130 6275 3224 3821 4377 4802 8113 7417 3741 9973 5961 1991 4279 631 5716 8294 8233 1508 5449 5907 3804 5071 9911 3653 7683 7176 1016 4489 4657 4295 8356 1218 1452 9899 3498 1229 9225 7492 2423 7946 5825 8924 9167 9730 8902 8306 9263 3436 5231 715 2712 2470 998 7927 3175 5282 397 9693 7549 938 4746 3989 1811 4502 6769 363 5484 3561 2483 3253 360 3873 4751 3684 5328 1289 4950 7210 7459 487 9675 6488 4571 406 9278 4935 5994 1025 2025 9515 8623 2200 3247 4389 5880 335 4741 8211 4032 9732 3568 4357 8947 531 6105 774 1760 6711 2866 2850 8580 600 1193 1353 1848 9024 4438 5037 719 2277 2582 3831 3973 4485 6964 9245 7650 1471 3547 8259 369 5883 3252 4796 900 1554 3562 990 6693 6514 5288 2755 8626 3698 7436 8272 7311 6282 8931 6032 1762 2405 6923 4072 124 7257 73 371 9269 4461 5283 5092 3219 2186 9089 1139 132 7090 1395 4588 1631 8460 71 8562 557 5839 5852 4730 929