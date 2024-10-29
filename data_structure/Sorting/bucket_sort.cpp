#include<bits/stdc++.h>

void bucketSort(std::vector<int>&nums){
    int n=nums.size();
    int mn = nums[0], mx = nums[0];
        for (int i = 1; i < n; i++) {
            mn = std::min(mn, nums[i]);
            mx = std::max(mx, nums[i]);
        }
        int size = (mx - mn) / n + 1;   // size 至少要为1
        int cnt = (mx - mn) / size + 1; // 桶的个数至少要为1
        std::vector<std::vector<int>> buckets(cnt);
        for (int i = 0; i < n; i++) {
            int idx = (nums[i] - mn) / size;
            buckets[idx].push_back(nums[i]);
        }
        for (int i = 0; i < cnt; i++) {
            sort(buckets[i].begin(), buckets[i].end());
        }
        int index = 0;
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < buckets[i].size(); j++) {
                nums[index++] = buckets[i][j];
            }
        }

}
