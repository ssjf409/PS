#include <iostream>

using namespace std;

// ************
//  --------321 i
// 123++++++++  j
int bubble_sort(int arr[], int n) {
    int temp;
    for(int i = n - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}



// ************
// -321<-O---- i
// i 지점 정해놓고 끼워넣기
void insertion_sort(int data[], int n) {
    int remember;
    for(int j, i = 1; i < n; i++) {
        remember = data[(j = i)];
        while(--j >= 0 && remember < data[j]) {
            data[j + 1] = data[j];
            data[j] = remember;
        }
    }
}

//
void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    int temp;
    do {
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;
        if(i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        

    } while(i <= j);
    
    if(left < j) quickSort(arr, left, j);
    if(i < right) quickSort(arr, i, right);
}


void selectionSort(int *list, const int n)
{
    int i, j, indexMin, temp;

    for (i = 0; i < n - 1; i++)
    {
        indexMin = i;
        for (j = i + 1; j < n; j++)
        {
            if (list[j] < list[indexMin])
            {
                indexMin = j;
            }
        }
        temp = list[indexMin];
        list[indexMin] = list[i];
        list[i] = temp;
    }
}


int main() {
    return 0;
}