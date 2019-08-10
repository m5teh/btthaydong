#include<bits/stdc++.h>
using namespace std;
int n, k, d, w[30], c[30], res, ans, u[30], sum, f[201][27][27][27], g[201][1024], e[1024], v[27];
string s;
void bt (int i) {
    if (i > n - 1) {
        if (u[s[i] - 'a' + 1]) {
            ++ res;
        }
        ans = max (ans, res);
        if (u[s[i] - 'a' + 1]) {
            -- res;
        }
        return;
    }
    if (u[s[i] - 'a' + 1]) {
            //cout << i << "\n";
        ++ res;
        bt (i + 1);
        u[s[i] - 'a' + 1] = 0;
        sum -= w[s[i] - 'a' + 1];
        bt (i + 1);
        u[s[i] - 'a' + 1] = 1;
        sum += w[s[i] - 'a' + 1];
        -- res;
    }
    else {
        bt (i + 1);
        if (sum + w[s[i] - 'a' + 1] <= k) {
            u[s[i] - 'a' + 1] = 1;
            sum += w[s[i] - 'a' + 1];
            bt (i + 1);
            u[s[i] - 'a' + 1] = 0;
            sum -= w[s[i] - 'a' + 1];
        }
    }
}
void sub1 () {
    for (int i = 1; i <= d; ++ i) {
        u[i] = 0;
    }
    bt (1);
    cout << ans;
}
void sub2 () {
    for (int i = 0; i <= n; ++ i) {
    for (int x = 0; x <= 26; ++ x) {
        for (int y = 0; y <= 26; ++ y) {
            for (int z = 0; z <= 26; ++ z) {
                f[i][x][y][z] = -1;
            }
        }
    }}
    f[0][0][0][0] = 0;
    for (int i = 0; i < n; ++ i) {
        for (int x = 0; x <= 26; ++ x) {
            for (int y = 0; y <= 26; ++ y) {
                for (int z = 0; z <= 26; ++ z) if (f[i][x][y][z] >= 0) {
                    if (x == s[i + 1] - 'a' + 1) {
                        f[i + 1][0][y][z] = max (f[i + 1][0][y][z], f[i][x][y][z] + 1);
                        f[i + 1][x][y][z] = max (f[i + 1][x][y][z], f[i][x][y][z] + 1);
                    }
                    if (y == s[i + 1] - 'a' + 1) {
                        f[i + 1][x][0][z] = max (f[i + 1][x][0][z], f[i][x][y][z] + 1);
                        f[i + 1][x][y][z] = max (f[i + 1][x][y][z], f[i][x][y][z] + 1);
                    }
                    if (z == s[i + 1] - 'a' + 1) {
                        f[i + 1][x][y][0] = max (f[i + 1][x][y][0], f[i][x][y][z] + 1);
                        f[i + 1][x][y][z] = max (f[i + 1][x][y][z], f[i][x][y][z] + 1);
                    }
                    if (w[x] + w[y] + w[z] + w[s[i + 1] - 'a' + 1] <= k) {
                        if (x == 0) {
                            f[i + 1][s[i + 1] - 'a' + 1][y][z] = max (f[i + 1][s[i + 1] - 'a' + 1][y][z], f[i][x][y][z]);
                        }
                        if (y == 0) {
                            f[i + 1][x][s[i + 1] - 'a' + 1][z] = max (f[i + 1][x][s[i + 1] - 'a' + 1][z], f[i][x][y][z]);
                        }
                         if (z == 0) {
                            f[i + 1][x][y][s[i + 1] - 'a' + 1] = max (f[i + 1][x][y][s[i + 1] - 'a' + 1], f[i][x][y][z]);
                        }

                    }
                    f[i + 1][x][y][z] = max (f[i + 1][x][y][z], f[i][x][y][z]);
                    res = max (res, f[i][x][y][z]);
                }
            }
        }
    }

    for (int x = 0; x <= 26; ++ x) {
        for (int y = 0; y <= 26; ++ y) {
            for (int z = 0; z <= 26; ++ z) {
                res = max (res, f[n][x][y][z]);
            }
        }
    }
    cout << res;
}
void sub3() {
    for (int s = 0; s < (1 << d); ++ s) {
        for (int j = 0; j < d; ++ j) {
            int tmp = (s >> j) & 1;
            //cout << tmp;
            if (tmp > 0) {
                e[s] += w[j + 1];
            }
        }//
        //cout << "\n";
        //cout << e[s] << " ";
    }
    for (int i = 0; i <= n; ++ i) {
        for (int j = 0; j < (1 << d); ++ j) {
            g[i][j] = -1;
        }
    }
    g[0][0] = 0;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < (1 << d); ++ j) if (g[i][j] >= 0) {
            int c = (s[i + 1] - 'a');
            if ((j >> c) & 1) {
                g[i + 1][j] = max (g[i + 1][j], g[i][j] + 1);
                g[i + 1][j ^ (1 << c)] = max (g[i][j] + 1, g[i + 1][j ^ (1 << c)]);
            }
            else if (e[j] + w[c + 1] <= k){
                g[i + 1][j] = max (g[i + 1][j], g[i][j]);
                g[i + 1][j | (1 << c)] = max (g[i + 1][j | (1 << c)], g[i][j]);
            }
            g[i + 1][j] = max (g[i + 1][j], g[i][j]);
        }
    }
    for (int i = 0; i < (1 << d); ++ i) {
        res = max (res, g[n][i]);
    }
    cout << res;
}
void sub4() {
    k /= w[1];//cout << k;
    int c = 0;
    for (int i = 1; i <= n; ++ i) {
        //cout << u[s[i] - 'a'] << "\n";
        if (u[s[i] - 'a']) ++ sum;
        else {
            if (c < k) {
                ++ c;
                u[s[i] - 'a'] = 1;
            }
            else {
                u[s[i] - 'a'] = 1;
                for (int j = 0; j < 26; ++ j) {
                    v[j] = 1e9;
                }
                int ma = 0, pj = -1;
                for (int j = i + 1; j <= n; ++ j) {
                    if (v[s[j] - 'a'] == 1e9) {
                        v[s[j] - 'a'] = j;
                    }
                }
                for (int j = 0; j < 26; ++ j) {
                    if (u[j] == 1 && v[j] > ma) {
                        ma = v[j];
                        pj = j;
                    }
                }
                //cout << v[pj] << "\n";
                u[pj] = 0;
            }
        }
    }
    cout << sum;
}
int main () {
    freopen ("CWBROBOT.inp", "r", stdin);
    freopen ("CWBROBOT.out", "w", stdout);
    ios_base :: sync_with_stdio (0);
    cin.tie (nullptr);
    cout.tie (nullptr);
    cin >> n >> k >> d;
    cin >> s;
    s = '@' + s;
    for (int i = 1; i <= d; ++ i) {
        cin >> w[i];
    }
        if (n <= 20) {
        sub1();
    }
    else if (n <= 200 && k <= 3) {
        sub2();
    }
    else if (n <= 200 && d <= 10) {
        sub3();
    }
    else {
        sub4();
    }
}
