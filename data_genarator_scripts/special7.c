#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *array, int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n = 2000000; // number of random numbers
    int k = 4000000; // maximum value of random numbers
    int*arr = (int*)malloc(sizeof(int)*k);

    for (int i = 0; i < k; i++) {
        arr[i] = i;
    }
    shuffle(arr, k);
    quickSort(arr, 0, n - 1);
    int*arr2 = (int*)malloc(sizeof(int)*k);
    for(int i=0;i<k;i++) arr2[i] = -1;
  

    int num = 1;
    for(int i=0;i<n;i++) {arr2[arr[i]] = num++;}
    num=1;
    for(int i=0;i<k;i++){ if(arr2[i]==-1){arr2[i] = k-num++;}}


    for(int i=0;i<k;i++) printf("%d\n",arr2[i]);

    return 0;
}

