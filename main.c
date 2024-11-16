#include <stdio.h>

void Merge(int L[], int start, int end, int mid);
void MergeSort(int L[], int start, int end);
void printList(int L[], int size);


int main(void) {
    int L[] = {5, 3, 8, 1, 6, 10, 7, 2, 4, 9};
    int L_size = sizeof(L) / sizeof(L[0]);

    printf("Given list \n");
    printList(L, L_size);

    MergeSort(L, 0, L_size - 1);

    printf("The sorted list \n");
    printList(L, L_size);
    return 0;
}

void Merge(int L[], int start, int end, int mid) {
    int L1_size = mid - start + 1;
    int L2_size = end - mid;
    int L1[L1_size], L2[L2_size];

    // create two lists from the given list
    for (int i = 0; i < L1_size ; i++)
        L1[i] = L[start + i];
    for (int j = 0; j < L2_size ; j++)
        L2[j] = L[mid + 1 + j];

    int i = 0; // Index variable for L1
    int j = 0; // Index variable for L2

    // Merging the two arrays into given array L
    while (i < L1_size && j < L2_size) {
        if (L1[i] <= L2[j]) {
            L[start + i + j] = L1[i]; // If L1's element is smaller, place it in L
            i++;
        } else {
            L[start + i + j] = L2[j]; // Otherwise, place L2's element in L
            j++;
        }
    }

    // If there are remaining elements in L2, copy them over to L
    if (i == L1_size) {
        for (int k = j; k < L2_size; k++)
            L[start + i + k] = L2[k];
    } else {
        // If there are remaining elements in L1, copy them over to L
        for (int k = i ; k < L1_size; k++) {
            L[start + j + k] = L1[k];
        }
    }
}

void MergeSort(int L[], int start, int end) {
    if (start < end) {
        int mid = (end + start) / 2;
        MergeSort(L, start, mid);
        MergeSort(L, mid + 1, end);
        Merge(L, start, end, mid);
    }
}

void printList(int L[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", L[i]);
    printf("\n");
}
