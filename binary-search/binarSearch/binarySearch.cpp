#include <bits/stdc++.h>

// time complexity: O(logn)
// remember that binary search only works on sorted array, if it is not sorted sort the array by
// sort(arr.begin(), arr.end())
// general case which doesn't have duplicate, it can find duplicates but if the requirement is about finding first, last or specific occrance then that needs be handled in the code.

using namespace std;

bool binary_search(const vector<int> &arr, int element)
{

  int start = 0;
  int end = arr.size() - 1;
  int mid = start + (end - start) / 2;

  while (start <= end)
  {

    if (arr[mid] == element)
    {
      return true;
    }
    else if (arr[mid] < element)
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
    mid = start + (end - start) /2;
  }

  return false;
}

int main(int argc, char *argv[])
{
  int n;
  if (!(cin >> n))
    return 0;

  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cout << "Test 2:  " << binary_search(arr, n, 2) << endl;
  cout << "Test 8:  " << binary_search(arr, n, 8) << endl;
  cout << "Test 11: " << binary_search(arr, n, 11) << endl;
  cout << "Test 6:  " << binary_search(arr, n, 6) << endl;

  return 0;
}
