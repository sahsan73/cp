#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;

int main() {
    int t; cin >> t;
    while(t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        double d1 = sqrt(x1*x1 + y1*y1);
        double d2 = sqrt(x2*x2 + y2*y2);
        
        if(abs(d1-d2)<eps) {
            cout << "EQUAL" << endl;
        } else if(d1>d2) {
            cout << "ALEX" << endl;
        } else {
            cout << "BOB" << endl;
        }
    }
}
