#include <bits/stdc++.h> 
int merge(long long *arr, long long low, long long mid, long long high) {
    vector<long long> temp; // temporary array
    long long left = low;      // starting index of left half of arr
    long long right = mid + 1;   // starting index of right half of arr

    //Modification 1: cnt variable to count the pairs:
    long long cnt = 0;

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); //Modification 2
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; // Modification 3
}

int mergeSort(long long *arr, long long low, long long high) {
    long long cnt = 0;
    if (low >= high) return cnt;
    long long mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}
long long getInversions(long long *a, int n){
    // Write your code here.
      return mergeSort(a, 0, n - 1);
}
