class Solution {
public:
    int maximumLength(string s) {
        int n = (int)s.size(), answer = -1;
        for(int i = 0; i < n; ++i) {
            string t;
            for(int j = i; j < n; ++j) {
                if(t.empty() || (!t.empty() && t.back()==s[j]))
                    t.push_back(s[j]);
                else
                    break;
                
                int cnt = 0; // count substring t in s
                for(int k = i; k < n-t.size()+1; ++k)
                    if(s.substr(k, t.size()) == t)
                        ++cnt;
                if(cnt >= 3)
                    answer = max(answer, (int)t.size());
                else
                    break;
            }
        }
        return answer;
    }
};
