from array import array

# O(n)
# doesn't handle duplicates

def binary_search(arr, element) -> bool:
    start = 0
    end = len(arr) - 1
    mid = start + (end - start) // 2

    while start <= end:
        if arr[mid] == element:
            return True
        elif arr[mid] < element:
            start = mid + 1
        else:
            end = mid - 1

        mid = (start + end) // 2
        print(mid)

    return False


if __name__ == "__main__":
    n: int = int(input())
    arr: list = list(map(int, input().split(" ")))

    print("TEST 2: ", binary_search(arr, 2))
    print("TEST 8: ", binary_search(arr, 8))
    print("TEST 6: ", binary_search(arr, 6))
    print("TEST 10: ", binary_search(arr, 10))
    print("TEST 13: ", binary_search(arr, 13))