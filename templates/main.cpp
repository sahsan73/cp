#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin()

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define F first
#define S second
#define mp make_pair

const int MOD = 1e9 + 7;
const double EPS = 1e-9;

template<typename T> void read(T &x) {
    cin >> x;
}
void read(double &d) {
    string s; read(s);
    d = stod(s);
}
void read(ld &d) {
    string s; read(s);
    d = stold(s);
}
template<typename T, typename...H> void read(T &t, H&... h) {
    read(t);
    read(h...);
}
template<typename T> void read(vt<T> &v) {
    for(auto &x: v) read(x);
}




void solve() {
    ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
