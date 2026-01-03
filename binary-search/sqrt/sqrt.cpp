#include <iostream>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'

const int MOD = 1e9 + 7;
const ll INF = 1e18;

int sqrt(int element) {

	if (element == 0) 
	{
		return 0;
	}

	if (element == 1)
	{
		return 1;
	}

	int start = 1;
	int end = element/2;
	int mid = start + (end - start) /2;

	while (start <= end) {
		int check = element/mid;
		if (mid == check) {
			return mid;
		} else if(mid < check) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
		mid = start + (end - start) /2;
	}

	return end;
}

int main() {
    fastio;

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    // cin >> t;
    while (t--) {
    	int element;
    	cin >> element;
        int result = sqrt(element);
        cout << "SQRT of " << element << " is: " << result << endl;
    }
    
    return 0;
}