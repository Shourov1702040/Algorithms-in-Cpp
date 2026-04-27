#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cout << "Enter target value to search: ";
    cin >> target;

    int low = 0, high = n - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            ans = mid;
            break;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (ans != -1)
        cout << "Element found at index: " << ans << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
