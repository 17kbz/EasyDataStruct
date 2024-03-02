#include"ezdata.h"
#include <stdio.h>
/*从小到大排序*/
void upSort(int* array,const int begin,const int end){
    if(begin>=end){
        return ;
    }
    int mid=(begin+end)/2;
    upSort(array,begin,mid);
    upSort(array, mid+1, end);
    int* h=getHelper(end-begin+1);
    int i=begin,j=mid+1;
    int count=0;
    while(i<=mid&&j<=end){
        while(i<=mid&&j<=end&&array[i]<=array[j]){
                h[count++]=array[i++];
            }
        while(i<=mid&&j<=end&&array[i]>array[j]){
                h[count++]=array[j++];
            }
    }
    while(i<=mid)h[count++]=array[i++];
    while(j<=end)h[count++]=array[j++];
    for(i=begin,count=0;i<=end;i++){
        array[i]=h[count++];
    }
    free(h);
}
/*从大到小排序*/
void downSort(int* array,const int begin,const int end,int* h){
    if(begin>=end){
        return ;
    }
    int mid=(begin+end)/2;
    downSort(array, begin, mid, h);
    downSort(array, mid+1, end, h);
    int i=begin,j=mid+1,n=end-begin+1;
    for(int k=0;k<n;k++){
        if(j>end||(i<=mid&&array[i]>=array[j]))h[k]=array[i++];
        else h[k]=array[j++];
    }
    for(int i=0,j=begin;j<=end;i++,j++){
        array[j]=h[i];
    }
}
/*合并排序*/
void mergeSort(int* array,int size){
    if(witchModel()){
        upSort(array, 0, size-1);
    }else{
        int *help=getHelper(size);
        downSort(array, 0, size-1,help);
        free(help);
    }
}
/*Test*/
int main(void){
    plant();
    printf("0退出   1归并排序——数组\n");
    int a;
    while(scanf("%d",&a)){
        switch(a){
            case 0:{
                exit(0);
            }break;
            case 1:{
                printf("请输入数组到长度和元素的大小:");
                int size,range;
                scanf("%d %d",&size,&range);
                int *array=getArray(size, range);
                printf("前:\n");
                output(array, size);
                mergeSort(array, size);
                printf("后:\n");
                output(array, size);
            }break;
        }
        printf("0退出   1归并排序——数组\n");
    }
    return 0;
}