// Copyright 2021 NNTU-CS
// Copyright 2021 NNTU-CS
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

int countPairs1(int *arr, int len, int value) {
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

int countPairs2(int *arr, int len, int value) {
    std::sort(arr, arr + len);
    int count = 0;
    int left = 0, right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            } else {
                int left_val = arr[left], right_val = arr[right];
                int left_count = 0, right_count = 0;
                while (left <= right && arr[left] == left_val) {
                    left_count++;
                    left++;
                }
                while (right >= left && arr[right] == right_val) {
                    right_count++;
                    right--;
                }
                count += left_count * right_count;
            }
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    std::unordered_map<int, int> freq;
    for (int i = 0; i < len; i++) {
        freq[arr[i]]++;
    }
    int count = 0;
    for (auto& pair : freq) {
        int num = pair.first;
        int complement = value - num;
        if (num == complement) {
            count += pair.second * (pair.second - 1) / 2;
        } else if (num < complement && freq.find(complement) != freq.end()) {
            count += pair.second * freq[complement];
        }
    }
    return count;
}
