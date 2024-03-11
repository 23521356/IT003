/// Author : Nguyễn Thái Sơn - K18 - KHMT - UIT
/// Training ICPC 2024

#include<bits/stdc++.h>

/// #pragma GCC optimize("O3,unroll-loops")
/// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define fi first
#define se second
#define TASK "test"
#define pb push_back
#define EL cout << endl
#define Ti20_ntson int main()
#define in(x) cout << x << endl
#define all(x) (x).begin(),(x).end()
#define getbit(x, i) (((x) >> (i)) & 1)
#define cntbit(x) __builtin_popcount(x)
#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FORD(i,l,r) for (int i = l; i >= r; i--)
#define Debug(a,n) for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl

using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> vii;
typedef unsigned long long ull;
typedef vector<vector<int>> vvi;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }

const int N = 2e6 + 5;
const int oo = INT_MAX;
const int mod = 1e9 + 7;
const int d4x[4] = {-1, 0, 1, 0} , d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, d8y[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int n, a[N];

void calc(int N, int i) {
    int best = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < N && a[l] > a[best]) {
        best = l;
    }
    if (r < N && a[r] > a[best]) {
        best = r;
    }
    if (best != i) {
        swap(a[i], a[best]);
        calc(N, best);
    }
}

Ti20_ntson {
//    freopen(TASK".INP","r",stdin);
//    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("test_case/heap_sort.out", "w", stdout);
    FOR(cnt, 1, 10) {
        string fname = "test_case/Test_" + to_string(cnt) + ".txt";
        ifstream inp(fname);
        inp >> n;
        FOR(i, 0, n - 1)
            inp >> a[i];
        FORD(i, n / 2 - 1, 0)
            calc(n, i);
        FORD(i, n - 1, 0) {
            swap(a[0], a[i]);
            calc(i, 0);
        }

        auto start = high_resolution_clock::now();
        auto End = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(End - start);
        cout << (long double)duration.count() / 1000 << endl;
        cout.flush();
    }
    return 0;
}


