// Copyright 2021 NNTU-CS
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>

int countPairs1(int *arr, int len, int value) {
    std::sort(arr, arr + len);
    int count = 0;
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            count++;
            left++;
            right--;
            while (left < right && arr[left] == arr[left - 1])
                left++;
            while (left < right && arr[right] == arr[right + 1])
                right--;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    std::unordered_set<int> seen;
    std::set<std::pair<int, int>> uniquePairs;

    for (int i = 0; i < len; i++) {
        int complement = value - arr[i];
        if (seen.find(complement) != seen.end()) {
            uniquePairs.insert({std::min(arr[i], complement),
                              std::max(arr[i], complement)});
        }
        seen.insert(arr[i]);
    }
    return uniquePairs.size();
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
