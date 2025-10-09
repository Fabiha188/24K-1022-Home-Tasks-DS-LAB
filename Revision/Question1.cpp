/*
Q1.
- Why Shell Sort is more efficient than Insertion Sort for this case:
  Insertion Sort moves elements one position at a time, so when an element belongs far from
  its current position (like 90 at the end), many single-step shifts are required (O(n^2)
  behavior). Shell Sort uses gaps (here 3 then 1) to move distant elements closer quickly,
  reducing the number of shifts needed before the final insertion pass. For this small list
  with elements far from their final positions, Shell's first gap pass greatly reduces disorder,
  so the final pass (gap = 1) does much less work than a full insertion sort would.
*/

#include <iostream>
using namespace std;

int main() {
    int arr[] = {205, 102, 310, 450, 120, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Initial: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << (i+1<n ? ", " : "\n");

    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        cout << "After gap=" << gap << ": ";
        for (int k = 0; k < n; ++k) cout << arr[k] << (k+1<n ? ", " : "\n");
    }

    cout << "Sorted: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << (i+1<n ? ", " : "\n");
    return 0;
}
