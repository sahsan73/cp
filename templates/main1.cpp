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

string to_string(char c) {
    return string(1,c);
}
string to_string(bool b) {
    return b?"true":"false";
}
string to_string(const char *s) {
    return string(s);
}
string to_string(const string &s) {
    return s;
}
template<typename T> string to_string(const T &v) {
    bool f=1;
    string res;
    for(const auto &x: v) {
        if(!f) res+=' ';
        res+=to_string(x);
        f=0;
    }
    return res;
}
string to_string(const vt<bool> &v) {
    string res;
    for(const auto &x: v) res+=char(x+'0');
    return res;
}
template<size_t N> string to_string(const bitset<N> &bs) {
    string ans;
    for(int i=N-1; ~i; --i) res+=char(bs[i]+'0');
    return ans;
}

void write() {
    cout << '\n';
}
template<typename T, typename...H> void write(const T &t, const H&...h) {
    cout << to_string(t);
    if(sizeof...(h)) cout << ' ';
    
    write(h...)
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
