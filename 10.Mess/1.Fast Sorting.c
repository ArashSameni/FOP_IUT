#include <stdio.h>
#define MAX 600000

void Sort(long long int* arr, int count){
    for (int i = 0; i < count; i++)
    {
        int min = arr[i];
        int id = i;
        for (int j = i+1; j < count; j++)
        {
            if(arr[j] < min){
                min = arr[j];
                id = j;
            }
        }
        arr[id] = arr[i];
        arr[i] = min;
    }
}

int main(){
    int count = 0;
    long long int inputs[MAX] = {};
    long long int inp = 0;
    while(scanf("%lli", &inp) != EOF){
        inputs[count] = inp;
        count++;
    }
    Sort(inputs, count);
    for (int i = 0; i < count; i++)
        printf("%lld ", inputs[i]);

    return 0;
}
