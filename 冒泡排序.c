#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define MAX 1000
/*初始化乱序数组*/
int* initArray(int size){
    if(size<=0){
        printf("array's size error\n");
        return NULL;
    }
    int* array=(int *)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        array[i]=rand()%MAX;
    }
    return array;
}
/*模式选择*/
bool witchModel(){
    printf("选择模式: 0从小到大     1从大到小\n");
    int a;
    scanf("%d",&a);
    return a==0?true:false;
}
/*交换两个数*/
void swap(int* a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
/*冒泡排序--数组*/
void sortPorp(int* array,const int size){
    if(witchModel()){
        for(int i=1;i<size;i++){
            //优化方案
            bool sign=true;
            for(int j=0;j<size-i;j++){
                if(array[j]>array[j+1]){
                    swap(&array[j], &array[j+1]);
                    sign=false;
                }
                if(sign){
                    return;
                }
            }
        }
    }else{
        for(int i=1;i<size;i++){
            bool sign=true;
            for(int j=0;j<size-i;j++){
                if(array[j]<array[j+1]){
                    swap(&array[j], &array[j+1]);
                    sign=false;
                }
            }
            if(sign){
                return;
            }
        }
    }
}
/*结构输出*/
void arrayOutput(int* array,const int size){
    printf("array(%d):  ",size);
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}
/*测试*/
int main(void){
    srand((unsigned int)time(NULL));
    printf("0退出   1冒泡排序-数组\n");
    int a;
    while(scanf("%d",&a)){
        switch (a) {
            case 0:{
                exit(0);
            }break;
            case 1:{
                int size;
                printf("请输入数组长度:");
                scanf("%d",&size);
                int* array=initArray(size);
                printf("排序前:\n");
                arrayOutput(array, size);
                printf("排序后:\n");
                sortPorp(array, size);
                arrayOutput(array, size);
            }break;
        }
        printf("0退出   1冒泡排序-数组\n");
    }
    return 0;
}