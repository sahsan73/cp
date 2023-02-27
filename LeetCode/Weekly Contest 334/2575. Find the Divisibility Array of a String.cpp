typedef long long ll;

class Solution {
public:
    vector<int> divisibilityArray(string word, ll m) {
        vector<int> ans;
        ll t = 0;
        for(int c: word) {
            t = t*10 + (ll)(c - '0');
            ans.push_back(t%m==0);
            
            t %= m;
        }
        return ans;
    }
};
