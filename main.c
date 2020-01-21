#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//print unsorted and the sorted AFTER EVERY SINGLE SORTING ALGORITHM!!!!

#define LENGTH 30

int arrayOfNums[LENGTH];

void arrayGenerator();

int *quickComp(const void *firstElement, const void *secondElement);

void *mergeSort(int array[], int start, int end);

void *merge(int *array, int start, int end);

void *bubble(int *array);

void printArray();

int main() {
    clock_t start_quick, end_quick, start_merge, end_merge, start_bubble, end_bubble;

    /*srand((unsigned int) time(NULL));
    for (int i = 0; i < LENGTH; i++) {
        arrayOfNums[i] = rand() % 32768;//
    }*/
    //makeing srand here so the numbers in every array are different every time i generate an array
    srand((unsigned int) time(NULL));

    arrayGenerator();
    //1st printing of the array while it is unsorted
    printArray();

    start_quick = clock();
    qsort(arrayOfNums, LENGTH, sizeof(int), (int (*)(const void *, const void *)) quickComp);
    end_quick = clock();
    float quick_Time = (float) (end_quick - start_quick) / CLOCKS_PER_SEC;
    printArray();

    arrayGenerator();
    printArray();
    start_merge = clock();
    mergeSort(arrayOfNums, 0, LENGTH - 1);
    end_merge = clock();
    float merge_Time = (float) (end_merge - start_merge) / CLOCKS_PER_SEC;
    printArray();

    arrayGenerator();
    printArray();
    start_bubble = clock();
    bubble(arrayOfNums);
    end_bubble = clock();
    float bubble_Time = (float) (end_bubble - start_bubble) / CLOCKS_PER_SEC;

    //2nd printing of the sorted array with the additional data about runtime
    printArray();
    printf("\n\nThe Quicksort alogrithm took: %-5f seconds for %-2d elements.\n", quick_Time, LENGTH);
    printf("\nThe Merge algorithm took: %-5f seconds for: %-2d elements.\n", merge_Time, LENGTH);
    printf("\nThe Bubblesort algorithm took: %-5f seconds for: %-2d elements.\n", bubble_Time, LENGTH);

    return 0;
}

/* explanation for the sorting function (how it works)
 * if firstElement - secondElement = 1 => firstElement > secondElement
 * if firstElement - secondElement = 0 => firstElement = secondElement
 * if firstElement - secondElement = -1 => firstElement < secondElement
*/
int *quickComp(const void *firstElement, const void *secondElement) {
    return (int *) (*(int *) firstElement - *(int *) secondElement);
}

void *mergeSort(int array[], int start, int end) {
    //if there are 1 or 0 elements left, no more dividing
    if (start >= end) {
        return NULL;
    }
    // creating the mid point for the function
    int midPoint = (start + end) / 2;
    //calling the function to divide the left side again
    mergeSort(array, start, midPoint);
    //calling the function to divide the right side again
    mergeSort(array, midPoint + 1, end);

    //calling the merging function to merge all divided and sorted arrays together
    merge(array, start, end);
    //dunno why but clion insist on this return!
    return NULL;
}

void *merge(int *array, int start, int end) {
    int midPoint = (start + end) / 2;
    int firstPart = start;
    int secondPart = midPoint + 1;
    int thirdPart = start;

    int temp[LENGTH];

    while (firstPart <= midPoint && secondPart <= end) {
        if (array[firstPart] < array[secondPart]) {
            temp[thirdPart++] = array[firstPart++];
        } else {
            temp[thirdPart++] = array[secondPart++];
        }
    }
    while (firstPart <= midPoint) {
        temp[thirdPart++] = array[firstPart++];
    }
    while (secondPart <= end) {
        temp[thirdPart++] = array[secondPart++];
    }
    for (firstPart = start; firstPart <= end; firstPart++) {
        array[firstPart] = temp[firstPart];
    }
    return NULL;
} //reder363@gmail.com Danke sehr

void *bubble(int *array) {
    for (int i = 1; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH - i; j++) {
            // smaller elements are not moved!
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
    return NULL;
}

void printArray() {
    printf("The array is:\n");
    for (int num = 0; num <= LENGTH; num++) {
        const int stop = 15; //index 0 is not printed bcs 0 % 15 = no rest
        if (num % stop == 0 && (void *) num != NULL) {
            printf("\n");
        } else {
            printf("%7d", arrayOfNums[num]);
        }
    }
    printf("\n");
}

void arrayGenerator(){
    for (int i = 0; i <= LENGTH; i++) {
        arrayOfNums[i] = rand() % 32768;//
    }
}