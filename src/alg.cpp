// Copyright 2021 NNTU-CS
#include <algorithm>
#include <iostream>
#include <unordered_set>

int countPairs1(int *arr, int len, int value) {
    std::sort(arr, arr + len);
    int count = 0;
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            } else {
                int left_count = 1, right_count = 1;
                while (left + 1 < right && arr[left] == arr[left + 1]) {
                    left++;
                    left_count++;
                }
                while (right - 1 > left && arr[right] == arr[right - 1]) {
                    right--;
                    right_count++;
                }
                count += left_count * right_count;
                left++;
                right--;
            }
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
    int count = 0;

    for (int i = 0; i < len; i++) {
        int complement = value - arr[i];
        if (seen.find(complement) != seen.end()) {
            count++;
        }
        seen.insert(arr[i]);
    }
    return count;
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
