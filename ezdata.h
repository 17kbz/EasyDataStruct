#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
/*判断*/
bool intPNotNull(int *temp){
    return temp?true:false;
}
/*交换*/
void swap(int* a,int* b){
    if(intPNotNull(a)&&intPNotNull(b)){
        int temp=*a;
        *a=*b;
        *b=temp;
    }
}
/*随机种子*/
void plant(){
    srand((unsigned int)time(0));
}
/*
--------------------------------
获取随机数据
*/
/*获取指定长度的乱序数组*/
int* getArray(const int size,const int range){
    if(size<=0||range<=0){
        printf("args error\n");
        return NULL;
    }
    int* array=(int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        array[i]=rand()%range;
    }
    return array;
}
/*
---------------------------------------
输出
*/
/*输出整形数组*/
void output(const int* array,const int size){
    printf("array(%d):  ",size);
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}
/*选择模式*/
bool witchModel(){
    printf("选择模式: 0从小到大     1从大到小\n");
    int a;
    scanf("%d",&a);
    return a==0?true:false;
}