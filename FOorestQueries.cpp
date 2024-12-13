#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("input1.txt","r", stdin);
    freopen("output1.txt","w",stdout);
    #endif
    
    int n, q;
    cin >> n >> q;

    vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        string row;
        cin >> row;
        for (int j = 1; j <= n; j++) {
            mat[i][j] = (row[j-1] == '*') ? 1 : 0;
        }
    }

    // Compute the 2D prefix sum
    vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = mat[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }

    // Process each query
    while (q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        
        // Calculate the number of trees in the rectangle using the prefix sum array
        int trees = prefix[y2][x2] - prefix[y1-1][x2] - prefix[y2][x1-1] + prefix[y1-1][x1-1];
        cout << trees << endl;
    }

    return 0;
}
