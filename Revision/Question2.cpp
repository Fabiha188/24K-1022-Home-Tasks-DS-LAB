// Shell Sort is chosen because it reduces the number of comparisons and swaps by comparing elements far apart first,
// making it faster than Bubble Sort, especially for medium or large lists like luggage weights.


int main() {
    int arr[] = {32, 25, 40, 12, 18, 50, 28};
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
