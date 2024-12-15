#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef long long ll;


int main() {

    #ifndef ONLINE_JUDGE
    freopen("input1.txt","r", stdin);
    freopen("output1.txt","w",stdout);
    #endif
 
    int n;
    cin>>n;
    int cnt = 0;
    while(n>0)
    {
        if(n&1)  cnt++;
        n = n >> 1;
    }
    cout << cnt << endl;
    
}
