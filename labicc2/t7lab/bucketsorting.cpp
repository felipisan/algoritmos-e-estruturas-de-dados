#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

void bucketSort(float *arr, int n, int m, int b) {
    vector<float> buck[n];

    float div = (float) m / b;
    for (int i = 0; i < n; i++) {
        int bi;
        if (arr[i] != m){
            bi = arr[i] / div;
            buck[bi].push_back(arr[i]);
        }
        else  
            buck[b - 1].push_back(arr[i]);
    }

    for (int i = 0; i < b; i++)
        sort(buck[i].begin(), buck[i].end());

    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < (int) buck[i].size(); j++)
            arr[index++] = buck[i][j];

}

int main() {
    int n, m, b;

    cin >> n;
    cin >> m;
    cin >> b;

    float ar[n];
    for (int i = 0; i < n; i++) 
        cin >> ar[i];

    bucketSort(ar, n, m, b);
    for (int i = 0; i < n; i++)
        printf("%.2f ", ar[i]);
    return 0;
}