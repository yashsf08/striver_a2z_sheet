#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    int n;
    cin >> n;
    vector<int> arr = new vector<int>[n];
    
    for (int i = 0; i < n; ++i) }{
      cin >> arr[i];
    }

    while (t--) {
      int element = -1;
      cin >> element;

      vector<int> result = searchRange(arr, element);

      if (result[0] == -1) {
        cout << "Element missing." << endl;
      } else {
        cout << "Starting Index: " << result[0] << endl;
        cout << "Ending Index: " << result[1] << endl;
      }
    }
    
    return 0;
}