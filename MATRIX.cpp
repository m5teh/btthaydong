#include<bits/stdc++.h>
using namespace std;
int a[60], b[60], c[60][60], res[60][60], n, ans[60][60];
pair <int, int> x[360];
void check1() {
    /*for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            cout << c[i][j] << " ";
        }cout << "\n";
    }cout << "\n";*/
    int ok = 1;
    for (int i = 1; i <= n; ++ i) {
        int sum = 0;
        for (int j = i - 1; j >= 1; -- j) {
            if (c[j][i]) {
                ++ sum;
            }
        }
        for (int j = i + 1; j <= n; ++ j) {
            if (c[i][j] == 1) {
                ++ sum;
            }
        }
        if (sum != a[i]) {
            ok = 0;
            break;
        }
    }
    if (ok) {
        for (int i = 1; i <= n; ++ i) {
            for (int j = i; j <= n; ++ j) {
                res[i][j] = c[i][j];
            }
        }
    }
}
void bt1 (int i, int j) {
    //cout << i << " " << j << "\n";
    if (i > n) {
        check1();
        return;
    }
    if (i == j) {
        c[i][j] = 0;
        if (j == n) {
            bt1(i + 1, i + 1);
        }
        else {
            bt1(i, j + 1);
        }
    }
    else {
        for (int k = 0; k <= 1; ++ k) {
            c[i][j] = k;
            if (j == n) {
                bt1(i + 1, i + 1);
            }
            else {
                bt1(i, j + 1);
            }
        }
    }
}
void check2() {
    int ok = 1;
    for (int i = 1; i <= n; ++ i) {
        int sum = 0;
        for (int j = i + 1; j <= n; ++ j) {
            if (c[j][i]) {
                ++ sum;
            }
        }
        for (int j = i - 1; j >= 1; -- j) {
            if (c[i][j] == 1) {
                ++ sum;
            }
        }
        if (sum != b[i]) {
            ok = 0;
            break;
        }
    }
    if (ok) {
        for (int i = 1; i <= n; ++ i) {
            for (int j = i; j >= 1; -- j) {
                res[i][j] = c[i][j];
            }
        }
    }
}
void bt2(int i, int j) {
    if (i > n) {
        check2();
        return;
    }
    if (i == j) {
        c[i][j] = 0;
        bt2 (i + 1, 1);
    }
    else {
        for (int k = 0; k <= 1; ++ k) {
            c[i][j] = k;
            if (j == i) {
                bt2(i + 1, 1);
            }
            else {
                bt2(i, j + 1);
            }
        }
    }
}
bool cmp (pair <int, int> a, pair <int, int> b) {
    return a.second > b.second;
}
void sub3() {
    for (int i = 1; i <= n; ++ i) {
        x[i].first = i;
        x[i].second = a[i];
    }
    while (1) {
        sort (x + 1, x + n + 1, cmp );
        /*for (int i = 1; i <= n; ++ i) {
            cout << x[i].first << " " << x[i].second << "\n";
        }cout << "\n";*/
        if (x[1].second == 0) break;
        for (int i = 2; i <= n; ++ i) {
            if (x[i].second == 0 || x[1].second == 0) {
                break;
            }
             -- x[i].second;
             -- x[1].second;
             res[x[i].first][x[1].first] = 1;
             res[x[1].first][x[i].first] = 1;
        }
        if (x[1].second > 0) {
            cout << "NO";
            return;
        }
    }
    for (int i = 1; i <= n;  ++ i) {
        for (int j = i; j <= n; ++ j) {
            ans[i][j] = res[i][j];
        }
    }
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            res[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++ i) {
        x[i].first = i;
        x[i].second = b[i];
    }
    while (1) {
        sort (x + 1, x + n + 1, cmp );
        /*for (int i = 1; i <= n; ++ i) {
            cout << x[i].first << " " << x[i].second << "\n";
        }cout << "\n";*/
        if (x[1].second == 0) break;
        for (int i = 2; i <= n; ++ i) {
            if (x[i].second == 0 || x[1].second == 0) {
                break;
            }
             -- x[i].second;
             -- x[1].second;
             res[x[i].first][x[1].first] = 1;
             res[x[1].first][x[i].first] = 1;
        }
        if (x[1].second > 0) {
            cout << "NO";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n;  ++ i) {
        for (int j = 1; j <= i; ++ j) {
            ans[i][j] = res[i][j];
        }
    }
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            cout << ans[i][j] << " ";
        }cout << "\n";
    }
}
int main () {
    freopen ("MATRIX.inp", "r", stdin);
    freopen ("MATRIX.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++ i) {
        cin >> b[i];
    }
    if (n > 7) {
        sub3();
        return 0;
    }
    res[1][n] = -1;
    bt1(1, 1);
    res[n][1] = -1;
    bt2(1, 1);
    if(res[1][n] == -1 || res[n][1] == -1){
        cout << "NO";
    }
    else {
        cout << "YES\n";
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= n;  ++ j) {
                cout << res[i][j] << " ";
            }
            cout << "\n";
        }
    }

}
