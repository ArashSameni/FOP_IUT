void selectionSort(int* arr, int count){
    for (int i = 0; i < count; i++)
        for (int j = i+1; j < count; j++)
            if(*(arr + j) < *(arr + i))
                swap(arr+i, arr+j);
}

void bubbleSort(int* arr, int count){
    int check = 1;
    while (check)
    {
        check = 0;
        for (int i = 0; i < count-1; i++)
            if(*(arr + i + 1) < *(arr + i))
            {
                swap(arr+i, arr+i+1);
                check = 1;
            }
    }
}
