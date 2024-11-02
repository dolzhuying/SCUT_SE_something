#include<bits/stdc++.h>
void Merge(std::vector<int>& sourceArr, std::vector<int>& tempArr, int startIndex, int midIndex, int endIndex) {
    int i = startIndex, j = midIndex + 1, k = startIndex;
    while (i != midIndex + 1 && j != endIndex + 1) {
        if (sourceArr[i] > sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }
    while (i != midIndex + 1)
        tempArr[k++] = sourceArr[i++];
    while (j != endIndex + 1)
        tempArr[k++] = sourceArr[j++];
    for (i = startIndex; i <= endIndex; i++)
        sourceArr[i] = tempArr[i];
}

void MergeSort(std::vector<int>& sourceArr, std::vector<int>& tempArr, int startIndex, int endIndex) {
    if (startIndex < endIndex) {
        int midIndex = startIndex + (endIndex - startIndex) / 2;
        MergeSort(sourceArr, tempArr, startIndex, midIndex);
        MergeSort(sourceArr, tempArr, midIndex + 1, endIndex);
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}

void MergeSort(std::vector<int>& arr) {
    if (arr.empty()) return;
    std::vector<int> tempArr(arr.size());
    MergeSort(arr, tempArr, 0, arr.size() - 1);
}
