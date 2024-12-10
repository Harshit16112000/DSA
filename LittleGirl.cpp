#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;


int main() {

    #ifndef ONLINE_JUDGE
    freopen("input1.txt","r", stdin);
    freopen("output1.txt","w",stdout);
    #endif
 
    int n;
    int q;
    cin >> n;
    cin >> q;
    vector<int> v(n,0);

    for(int i=0;i<n;i++)
    {
        cin >> v[i];     
    }

    
    vector<int> diffarray(n,0);
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        diffarray[a]++;
        if(b + 1 < n)
            diffarray[b+1]--;
    }

    for(int i=1;i<n;i++)
    {
        diffarray[i] += diffarray[i-1];
    } 

    sort(diffarray.begin(), diffarray.end());
    sort(v.begin(), v.end());

    ll ans = 0;
    int ind = 0;
    for(auto &it: v)
    {
        ans += (1ll * it * diffarray[ind]);
        ind++;
    }
    cout << ans << endl;
return 0;
}



