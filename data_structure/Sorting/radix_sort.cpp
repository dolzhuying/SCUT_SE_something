/*Capps特供*/
#include<bits/stdc++.h>
template <int B, class T>
void radixSort(std::vector<T> &a) {
    const int mask = (1 << B) - 1, n = a.size();

    std::vector<T> b(n);
    std::vector<int> cnt(1 << B);

    T maxV = *std::max_element(begin(a), end(a));

    for (int i = 0; maxV; i += B, maxV >>= B) {
        std::fill(begin(cnt), end(cnt), 0);
        for (int j = 0; j < n; j++)
            cnt[a[j] >> i & mask] += 1;
        for (int j = 1; j < (1 << B); j++)
            cnt[j] += cnt[j - 1];
        for (int j = n - 1; j >= 0; j--)
            b[--cnt[a[j] >> i & mask]] = a[j];
        std::swap(a, b);
    }
}