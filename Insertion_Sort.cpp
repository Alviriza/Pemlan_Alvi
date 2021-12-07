#include <stdio.h>
int j, i, tmp, n;
int arr[] = {22, 10, 15, 3, 8, 2};

int asc(){ 
    for (i = 0; i < 6; i++){
        j = i;
        while(j > 0 && arr[j-1] > arr[j]){
            tmp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = tmp;
            j--;
        }
    }
    for (i=0; i<6; i++){
        printf("%d ", arr[i]);
    }
    return arr[j];
}

int desc(){ 
    for (i = 0; i < 6; i++){
        j = i;
        while(j > 0 && arr[j-1] < arr[j]){
            tmp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = tmp;
            j--;
        }
    }
    for (i=0; i<6; i++){
        printf("%d ", arr[i]);
    }
    return arr[j];
}

void print(){
    for(i=0; i<6; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    printf("Data sebelum diurutkan: \n");
    print(); printf("\n");
    printf("SOrting berdasarkan ascending: \n");
    asc(); printf("\n");
    printf("SOrting berdasarkan descending: \n");
    desc();
}
