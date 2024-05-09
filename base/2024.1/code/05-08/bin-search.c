int bin_search_rec(int* arr, int l, int r, int v) {
    if (l > r) return 0;

    int m = (l + r) / 2;

    if (arr[m] == v) return 1;
    else if (arr[m] < v) return bin_search_rec(arr, m + 1, r, v);
    else return bin_search_rec(arr, l, m - 1, v);

    return 0;
}

int binary_search(int* arr, int n, int v) {
    int l = 0, r = n;

    while (l <= r) {
        int m = (l + r) / 2;

        if (arr[m] == v) return 1;
        else if (arr[m] < v) l = m + 1;
        else r = m - 1;
    }

    return 0;
}