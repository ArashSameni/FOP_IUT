#include <stdio.h>
#define SIZE 100

void read(int *array, int size) {
    int i;
    for (i = 0; i < size; i++)
        scanf("%d", array + i); //بجا مقدار از خود پوینتر استفاده کردم
}

void swap(int *a, int *b) {// beja pointera ke jabeja shode bood maghadiro swap kardam
    int temp = *a;
    *a = *b;
    *b = temp; 
}

void print(const int *array, int size) {  // [] ro hazfidam
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", *(array + i));  //ye * hazf kardam
}

void sort(int array[], const int size) {
    int* end = array + size, *i; // i ro pointer kardam
    for (int x = 0; x < size; x++) // ye halghe ezafe kardam ke kamel sort kone die:/
    {
        for (i = array; i != end - 1; i++)
            if (*i > *(i + 1))         // beja pointer az khod value estefade kardam
            {
                swap(i, i + 1);
            }
    }
}

int isSorted(const int array[], const int *size) {
    int i;
    for (i = 0; i < *size - 1; i++)
        if (*(array + i) > *(array + i + 1))
            return 0;
    return 1;
}

int main() {
    int arr[SIZE], len;
    scanf("%d", &len);
    read(arr, len);
    sort(arr, len); // address len ro kardam value len
    printf("%s\n", isSorted(arr, &len) ? "All is good!" : "This isn't going as it's supposed to...");
    print(arr, len);
    return 0;
}
