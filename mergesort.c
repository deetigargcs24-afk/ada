#include<stdio.h>

int a[100];

void merge(int low, int mid, int high){
    int i=low, j=mid+1, k=low;
    int temp[100];

    while(i<=mid && j<=high){
        if(a[i] <= a[j]){
            temp[k]=a[i];
            i++;
        }
        else{
            temp[k]=a[j];
            j++;
        }
        k++;
    }

    while(i<=mid){
        temp[k]=a[i];
        i++;
        k++;
    }

    while(j<=high){
        temp[k]=a[j];
        j++;
        k++;
    }

    for(i=low;i<=high;i++){
        a[i]=temp[i];
    }
}

void mergesort(int low,int high){
    int mid;

    if(low<high){
        mid=(low+high)/2;

        mergesort(low,mid);
        mergesort(mid+1,high);

        merge(low,mid,high);
    }
}

int main(){
    int n,i;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    mergesort(0,n-1);

    printf("Sorted elements:\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    return 0;
}
