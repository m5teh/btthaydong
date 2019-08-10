#include<bits/stdc++.h>
using namespace std;
///-m5teh-///
int n, x[889], d[889], q, m, k;
struct ds {
    double c, d;
};
ds a[889],f[889], g[889];
bool cmp1 (ds a, ds b) {
    return a.c < b.c;
}
bool cmp2 (ds a, ds b) {
    return a.d > b.d;
}
double wa, wb, wc, t[889], res = 1e9, m1 = 1e9, m2 = 0.0;
void check () {
    double sum1 = 0.0, sum2 = 0.0;
    for (int i = 1; i <= n; ++ i) {
        sum1 += a[x[i]].c;
        t[i] = max (sum1, sum2) + a[x[i]].d;
        sum2 = t[i];
    }

    //if (m1 < t[1] && m2  > t[n]) return;
    m1 = min (m1, t[1]);
    m2 = max (m2, t[n]);
    //for (int i = 1; i <= n; ++ i) {
        //cout << x[i] << " " << t[i] << "\n";
    //}cout << "\n";
    double ans;
    for (double s = 0.0; s <= t[n]; s += 0.1) {
        ans = 0.0;
        ans = max (ans, wa * (s - t[1]));
        ans = max (ans, wb * (t[n] - s));
        ans = max (ans, wc * s);
        res = min (res, ans);
    }
}
void bt (int i) {
    for (int j = 1; j <= n; ++ j) if (d[j] == 0) {
        d[j] = 1;
        x[i] = j;
        if (i == n) {
            check ();
        }
        else {
            bt (i + 1);
        }
        d[j] = 0;
    }
}
void sub1 () {
    res = 1e9;
    m1 = 1e9;
    m2 = 0.0;
    bt (1);
    cout << setprecision (1) << fixed << res;
}
void sub2 () {
    k = 0, m = 0;
    for (int i = 1; i <= n; ++ i) {
        if (a[i].c <= a[i].d) {
            ++ m;
            f[m].c = a[i].c;
            f[m].d = a[i].d;
        }
    }
    sort (f + 1, f + m + 1, cmp1);
    for (int i = 1; i <= n; ++ i) {
        if (a[i].c > a[i].d) {
            ++ k;
            g[k].c = a[i].c;
            g[k].d = a[i].d;
        }
    }
    sort (g + 1, g + k + 1, cmp2);
    double sum1 = 0.0, sum2 = 0.0;
    for (int i = 1; i <= m; ++ i) {
        sum1 += f[i].c;
        sum2 = max (sum1, sum2) + f[i].d;
    }
    for (int i = 1; i <= k; ++ i) {
        sum1 += g[i].c;
        sum2 = max (sum1, sum2) + g[i].d;
    }
    double s = (sum2 / 2.0);
    res = sum2 - s;
    cout << setprecision (1) << fixed << res;
}
void sub3 () {
    res = 1e9;
    for (int l = 1; l <= n; ++ l) {
        k = 0, m = 0;
    for (int i = 1; i <= n; ++ i) if (i != l) {
        if (a[i].c <= a[i].d) {
            ++ m;
            f[m].c = a[i].c;
            f[m].d = a[i].d;
        }
    }
    sort (f + 1, f + m + 1, cmp1);
    for (int i = 1; i <= n; ++ i) if (i != l) {
        if (a[i].c > a[i].d) {
            ++ k;
            g[k].c = a[i].c;
            g[k].d = a[i].d;
        }
    }
    sort (g + 1, g + k + 1, cmp2);
    double sum1 = 0.0, sum2 = 0.0, gg;
    sum1 += a[l].c;
    sum2 = max (sum1, sum2) + a[l].d;
    gg = sum2;
    for (int i = 1; i <= m; ++ i) {
        sum1 += f[i].c;
        sum2 = max (sum1, sum2) + f[i].d;
    }
    for (int i = 1; i <= k; ++ i) {
        sum1 += g[i].c;
        sum2 = max (sum1, sum2) + g[i].d;
    }
    double s = (sum2 + gg) / 2.0;//cout << sum2 << " " << gg << " " << s << "\n";
    res = min (res, max (sum2 - s, s - gg));
    }
    cout << setprecision(1) << fixed << res;
}
void sub4 () {
    res = 1e9;
    for (int l = 1; l <= n; ++ l) {
        k = 0, m = 0;
    for (int i = 1; i <= n; ++ i) if (i != l) {
        if (a[i].c <= a[i].d) {
            ++ m;
            f[m].c = a[i].c;
            f[m].d = a[i].d;
        }
    }
    sort (f + 1, f + m + 1, cmp1);
    for (int i = 1; i <= n; ++ i) if (i != l) {
        if (a[i].c > a[i].d) {
            ++ k;
            g[k].c = a[i].c;
            g[k].d = a[i].d;
        }
    }
    sort (g + 1, g + k + 1, cmp2);
    double sum1 = 0.0, sum2 = 0.0, gg;
    sum1 += a[l].c;
    sum2 = max (sum1, sum2) + a[l].d;
    gg = sum2;
    for (int i = 1; i <= m; ++ i) {
        sum1 += f[i].c;
        sum2 = max (sum1, sum2) + f[i].d;
    }
    for (int i = 1; i <= k; ++ i) {
        sum1 += g[i].c;
        sum2 = max (sum1, sum2) + g[i].d;
    }
    double s = (sum2 * wb + gg * wa) / (wa + wb);//cout << sum2 << " " << gg << " " << s << "\n";
    double tmp = (sum2 * wb) / (wb + wc);
    tmp = min (tmp, s);
    res = min (res, max ((tmp - gg) * wa, max ((sum2 - tmp) * wb, wc * tmp)));
        }
    cout << setprecision(1) << fixed << res;
}
int main () {
    //freopen ("ARTHUR.inp", "r", stdin);
    //freopen ("ARTHUR.out", "w", stdout);
    ios_base :: sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    cin >> q;
    while (q --) {
        cin >> n >> wa >> wb >> wc;
        for (int i = 1; i <= n; ++ i) {
            cin >> a[i].c >> a[i].d;
        }
        if (wa == 0 && wb == 1 && wc == 1) {
            sub2 ();
            cout << "\n";
            continue;
        }
        if (wa == 1 && wb == 1 && wc == 0) {
            sub3 ();
            cout << "\n";
            continue;
        }
        if (n <= 8) {
            sub1();
            cout << "\n";
            continue;
        }
        //sub4 ();
        //cout << "\n";
    }
}
