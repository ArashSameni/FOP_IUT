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

void reverse(char* str){
    char *p1, *p2;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        char p = *p1;
        *p1 = *p2;
        *p2 = p;
    }
}
