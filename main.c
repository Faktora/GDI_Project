#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//print unsorted and the sorted AFTER EVERY SINGLE SORTING ALGORITHM!!!!

#define LENGTH 1000


struct bin_search{
    int number;
    char *string;
};

int *quickComp(const void *firstElement, const void *secondElement);

void arrayGenerator(int *array);

void *mergeSort(int *array, int start, int end);

void *merge(int *array, int start, int end);

void *bubble(int *array);

void printArray(int *array);

void bin_search_array_fill(struct bin_search *array, int num_elements);

void bin_search_print_array(struct bin_search *array, int num_elements);

int compare_bin_search(const void *first_value, const void *second_value);

int main() {
    clock_t start_quick, end_quick, start_merge, end_merge, start_bubble, end_bubble;
    int arrayOfNums[LENGTH];

    struct bin_search array[500];

    //makeing srand here so the numbers in every array are different every time i generate an array
    srand((unsigned int) time(NULL));

    arrayGenerator(arrayOfNums);
    //1st printing of the array while it is unsorted
    printArray(arrayOfNums);

    //quick sort
    start_quick = clock();
    qsort(arrayOfNums, LENGTH, sizeof(int), (int (*)(const void *, const void *)) quickComp);
    end_quick = clock();
    float quick_Time = (float) (end_quick - start_quick) / CLOCKS_PER_SEC;
    printArray(arrayOfNums);

    //merge sort
    arrayGenerator(arrayOfNums);
    printArray(arrayOfNums);
    start_merge = clock();
    mergeSort(arrayOfNums, 0, LENGTH - 1);
    end_merge = clock();
    float merge_Time = (float) (end_merge - start_merge) / CLOCKS_PER_SEC;
    printArray(arrayOfNums);

    //bubble sort
    arrayGenerator(arrayOfNums);
    printArray(arrayOfNums);
    start_bubble = clock();
    bubble(arrayOfNums);
    end_bubble = clock();
    float bubble_Time = (float) (end_bubble - start_bubble) / CLOCKS_PER_SEC;
    printArray(arrayOfNums);

    bin_search_array_fill(array, 500);
    bin_search_print_array(array, 500);
    qsort(array, 500, sizeof(struct bin_search), compare_bin_search);
    bin_search_print_array(array, 500);

    int unique_id = 0;
    printf("\nEnter ID of element to search for:\n");
    scanf("%d", &unique_id);
    struct bin_search *search_id = bsearch((const void *)&unique_id, array, 500, \
			sizeof(struct bin_search), compare_bin_search);
    if(search_id != NULL){
        printf("\nKey %d found string %s\n", unique_id, search_id->string);
    }

    for(int i = 0; i < 500; i++){
        free(array[i].string);
    }

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

void arrayGenerator(int *array){
    for (int i = 0; i <= LENGTH; i++) {
        array[i] = rand() % 32768;//
    }
}

void *mergeSort(int *array, int start, int end) {
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

void printArray(int *array) {
    printf("\nThe array is:\n");
    for (int i = 0; i < LENGTH; i++) {
        //const int stop = 15; //index 0 is not printed bcs 0 % 15 = no rest
        if(i % 15 == 0 && i != 0){
            putchar('\n');
        }
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bin_search_array_fill(struct bin_search *array, int num_elements){
    for(int i = 0; i < num_elements; i++){
        array[i].number = rand() % 32768;
        array[i].string = malloc(11 * sizeof(char));
        for (int j = 0; j < 10; j++) {
            array[i].string[j] = rand() % 26 + 97;
        }
        array[i].string[10] = '\0';
    }
}

void bin_search_print_array(struct bin_search *array, int num_elements){
    for (int i = 0; i < num_elements; i++) {
        printf("%-10d %5s\n", array[i].number, array[i].string);
    }
}

int compare_bin_search(const void *first_value, const void *second_value){
    return (*((struct bin_search*)first_value)).number - (*((
    struct bin_search*)second_value)).number;
}