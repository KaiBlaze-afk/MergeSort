#include <stdio.h>

#define MAX_SIZE 100
#define THRESHOLD 15

int a[MAX_SIZE];
int link[MAX_SIZE + 1];

void InsertionSort1(int a[], int n);
void MergeSort1(int low, int high);
int Merge1(int q, int r);

int main() {
    int n;
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    MergeSort1(0, n - 1);

    int index = link[0];
    while (index != 0) {
        printf("%d ", a[index]);
        index = link[index];
    }
    printf("\n");

    return 0;
}

void InsertionSort1(int a[], int n) {
    for (int j = 1; j < n; j++) {
        int item = a[j];
        int i = j - 1;
        while (i >= 0 && a[i] > item) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = item;
    }
}

int Merge1(int q, int r) {
    int i = q, j = r, k = 0;

    while (i != 0 && j != 0) {
        if (a[i] <= a[j]) {
            link[k] = i;
            k = i;
            i = link[i];
        } else {
            link[k] = j;
            k = j;
            j = link[j];
        }
    }

    link[k] = (i == 0) ? j : i;

    return link[0];
}

void MergeSort1(int low, int high) {
    if (high - low < THRESHOLD) {
        InsertionSort1(a + low, high - low + 1);
    } else {
        int mid = (low + high) / 2;

        MergeSort1(low, mid);
        MergeSort1(mid + 1, high);

        int q = low, r = mid + 1;

        for (int i = low; i <= mid; i++) link[i] = i + 1;
        link[mid] = 0;
        for (int i = mid + 1; i <= high; i++) link[i] = i + 1;
        link[high] = 0;

        link[0] = Merge1(q, r);
    }
}