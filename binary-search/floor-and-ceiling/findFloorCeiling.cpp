#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define endl '\n'

const int MOD = 1e9 + 7;
const ll INF = 1e18;

int leftIndex(const vector<int> &arr, int element)
{
	int start = 0;
	int end = arr.size() - 1;
	int mid = start + (end - start) / 2;

	int leftMostIndex = -1;

	while (start <= end)
	{
		if (arr[mid] < element)
		{
			start = mid + 1;
		}
		else if (arr[mid] > element)
		{
			end = mid - 1;
		}
		else
		{
			end = mid - 1;
			leftMostIndex = mid;
		}
		mid = start + (end - start) / 2;
	}
	return leftMostIndex;
}

int rightIndex(const vector<int> &arr, int element)
{
	int start = 0;
	int end = arr.size() - 1;
	int mid = start + (end - start) / 2;

	int rightMostIndex = -1;

	while (start <= end)
	{
		if (arr[mid] < element)
		{
			start = mid + 1;
		}
		else if (arr[mid] > element)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
			rightMostIndex = mid;
		}
		mid = start + (end - start) / 2;
	}
	return rightMostIndex;
}

vector<int> searchRange(vector<int> &arr, int element)
{

	if (arr.size() == 0)
		return {-1, -1};

	// if (nums.empty())
	int f = leftIndex(arr, element);
	// cout << "Finished with Floor " << f << endl;

	if (f == -1)
	{
		return {-1, -1};
	}

	int c = rightIndex(arr, element);
	// cout << "Finished with Ceiling " << c << endl;

	return vector<int>{f, c};
}

void printArray(const vector<int> &arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
	return;
}

int main()
{
	// fastio;

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		vector<int> arr(n, 0);

		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		int element;
		cin >> element;

		vector<int> result = searchRange(arr, element);

		printArray(result);
	}

	return 0;
}
