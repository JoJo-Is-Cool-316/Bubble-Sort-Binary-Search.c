#include <stdio.h>

void bubbleSort(int array[], int size);
int binarySearch(int array[], int size, int target);
void printArray(int array[], int size);

int main() {
    int group[] = {12, 87, 45, 3, 68, 22, 90, 56, 31, 74, 19, 5, 63, 41, 77, 28, 95, 36, 10, 59, 84, 7, 48, 66, 2, 80, 14, 93, 51, 33, 72, 6, 39, 24, 88, 17, 64, 49, 11, 78, 29, 54, 97, 35, 81};
    int length = sizeof(group)/sizeof(group[0]); //Size Of Group
    
    printf("Before Sorted: ");
    printArray(group, length);
    bubbleSort(group, length);
    printf("After Sorted: ");
    printArray(group, length);
    
    int target;
    printf("What is the number you seek?: ");
    scanf("%d", &target);

    int index = binarySearch(group, length, target);

    if(index != -1) {
        printf("Founded at index: %d\n", index);
    } else {
        printf("Notfounded\n");
    }
}
void bubbleSort(int array[], int size) {
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int binarySearch(int array[], int size, int target) {
    int low = 0;
    int high = size;

    int middle;
    int value;
    while (low <= high) {
        middle = low + (high - low) / 2;
        value = array[middle];

        printf("Low: %d\nMiddle: %d\nHigh: %d\n\n", low, middle, high);

        if(value < target) {
            low = middle + 1;
        } else if(value > target){
            high = middle - 1; 
        } else { 
            return middle; //FOUNDED!!! 
        }
    }
    return -1; // NOT FOUNDED 
}

void printArray(int array[], int size) {
    printf("[ ");
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n\n");

}
