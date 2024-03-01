#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define NUM 1000
/*选择模式*/
bool witchModel(){
    int a;
    printf("选择模式:0从小到大   1从大到小\n");
    scanf("%d",&a);
    return a==0?true:false;
}
/*交换两个数*/
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
/*初始化一个乱序数组*/
int* initRandomArray(const int size){
    if(size<=0){
        printf("array's size wrong\n");
        return NULL;
    }
    int* array=(int *)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        array[i]=rand()%NUM;
    }
    return array;
}
/*输出数组*/
void arrayOutput(int* array, int size){
    if(array==NULL){
        return;
    }
    printf("array(%d):  ",size);
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}
/*数组——插入排序*/
void arraySort(int* array,const int size){
    if(witchModel()){
        for(int i=1;i<size;i++){
            for(int j=i;j>=1;j--){
                if(array[j-1]<=array[j]){
                    break;
                }
                swap(&array[j], &array[j-1]);
            }
        }
    }else{
        for(int i=1;i<size;i++){
            for(int j=i;j>=1;j--){
                if(array[j-1]>=array[j]){
                    break;
                }
                swap(&array[j-1], &array[j]);
            }
        }
    }
}
/**/
int main(void){
    srand((unsigned int)time(NULL));
    int a;
    printf("0退出   1插入排序(数组)\n");
    while(scanf("%d",&a)){
        switch(a){
            case 0:{
                exit(0);
            }break;
            case 1:{
                printf("请输入数组长度:");
                int size;
                scanf("%d",&size);
                int *array=initRandomArray(size);
                printf("排序前:\n");
                arrayOutput(array,size);
                printf("排序后:\n");
                arraySort(array,size);
                arrayOutput(array,size);
                free(array);
            }
        }
        printf("0退出   1插入排序(数组)\n");
    }
    return 0;
}