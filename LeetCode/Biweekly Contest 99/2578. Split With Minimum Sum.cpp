class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        
        int x1=0, x2=0;
        for(int i=0; i<s.size(); ++i) {
            if(i%2==0) {
                x1 = x1*10 + (s[i]-'0');
            } else {
                x2 = x2*10 + (s[i]-'0');
            }
        }
        return x1+x2;
    }
};
