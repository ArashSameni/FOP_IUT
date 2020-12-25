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

char* strlwr(char* str){
    char* ptr = str;
    while(*ptr){
        if(*ptr >= 'A' && *ptr <= 'Z')
            *ptr += 32;
        ptr++;
    }
    return str;
}

char* strupr(char* str){
    char* ptr = str;
    while(*ptr){
        if(*ptr >= 'a' && *ptr <= 'z')
            *ptr -= 32;
        ptr++;
    }
    return str;
}

double power(double number, int pow){
    double ans = 1;
    for (int i = 0; i < pow;ans *= number,i++);
}

int xToDec(long int mabnaNum, int mabna){
    int res = 0;
    int tavan = 0;
    while(mabnaNum > 0){
        res += (mabnaNum%10) * (int)power(mabna, tavan);
        mabnaNum /= 10;
        tavan++;
    }
    return res;
}
