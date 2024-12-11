#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define nline '\n'

bool is1100(const string &s, int idx) {
    if (idx < 0 || idx + 3 >= s.size()) return false;
    return s[idx] == '1' && s[idx + 1] == '1' && s[idx + 2] == '0' && s[idx + 3] == '0';
}

void solve() {
    string s;
    cin >> s;

    ll q;
    cin >> q;

    ll count = 0;
    for (int i = 0; i < s.size() - 3; i++) {
        if (is1100(s, i)) count++;
    }

    while (q--) {
        ll i, v;
        cin >> i >> v;
        i--; 

        for (int j = i - 3; j <= i; j++) {
            if (is1100(s, j)) count--;
        }

        s[i] = (v == 1 ? '1' : '0');

        for (int j = i - 3; j <= i; j++) {
            if (is1100(s, j)) count++;
        }

        cout << (count > 0 ? "YES" : "NO") << nline;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input1.txt","r", stdin);
    freopen("output1.txt","w",stdout);
    #endif


    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}