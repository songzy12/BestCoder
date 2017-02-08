#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 26;
pair<int, int> val[maxn+5];

// 错误是因为负权的也可能出现在答案中：放在最前面来使后面每个字母的贡献都增加。 
// 正确的做法是把字母从大往小从后往前放，如果加入该字母后答案变劣就停下来。
int main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        for (int i = 0; i < n; ++i){
            int t_val, t_cnt;
            cin>>t_val>>t_cnt;
            val[i] = make_pair(t_val, t_cnt);
        }
        sort(val, val+n);
        int ans = 0, sum = 0;
        while (n){
            sum += val[n-1].first;
            if (sum<0) 
                break;
            ans += sum;
            val[n-1].second--;
            if (!val[n-1].second) 
                n--;
        }
        cout<<ans<<endl;
    }
}
