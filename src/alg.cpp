// Copyright 2021 NNTU-CS
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

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
                while (right - 1 > left
