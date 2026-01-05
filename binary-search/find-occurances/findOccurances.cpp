#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int indexOfFirst(const vector<int> &arr, int element)
{
  int start = 0;
  int end = arr.size() - 1;
  int result = -1;

  while (start <= end)
  {
    int mid = start + (end - start) / 2;
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
      result = mid;
    }
  }
  return result;
}

int indexOfLast(const vector<int> &arr, int element)
{
  int start = 0;
  int end = arr.size() - 1;
  int mid = start + (end - start) / 2;
  int result = -1;

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
      result = mid;
    }
    mid = start + (end - start) / 2;
  }
  return result;
}

int getOccurances(const vector<int> &arr, int element)
{
  if (arr.empty())
  {
    cout << endl;
    cout << "Array is empty!" << endl;
    return 0;
  }

  int occurance = 0;
  int startIndex = indexOfFirst(arr, element);
  int lastIndex = indexOfLast(arr, element);

  cout << endl;
  cout << "First Index is " << startIndex << endl;
  cout << "Last Index is " << lastIndex << endl;

  if (startIndex == -1)
  {
    // cout << "No Element found!" << endl;
    return 0;
  }

  return lastIndex - startIndex + 1;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;

  while (t--)
  {
    int n;
    if (!(cin >> n))
    {
      cout << "n is garbage or empty!, therefore making it 0." << endl;
      n = 0;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
      cin >> arr[i];
    }

    int element = -1;
    cin >> element;

    cout << "The number of occurances for the given element " << element << " is: " << getOccurances(arr, element);
    cout << endl;
    cout << "-----------------------------------------------------------" << endl;
  }

  return 0;
}