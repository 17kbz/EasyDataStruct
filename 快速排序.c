#include"ezdata.h"
/*从小到大排序*/
void upSort(int* array,const int begin,const int end){
    if(begin>=end)return ;
    int i=begin,j=end;
    //没有优化则默认中间值为第一个元素
    int cur=array[begin];
    while(i<j){
        while(i<j&&cur<=array[j])j--;
        if(i<j){
            array[i]=array[j];
        }
        while(i<j&&cur>=array[i])i++;
        if(i<j){
            array[j]=array[i];
        }
    }
    array[i]=cur;
    upSort(array,begin,i-1);
    upSort(array, i+1, end);
}
/*从大到小排序*/
void downSort(int* array,const int begin,const int end){
    if(begin>=end)return;
    int i=begin,j=end;
    int cur=array[begin];
    while(i<j){
        while(i<j&&cur>=array[j])j--;
        if(i<j){
            array[i]=array[j];
        }
        while(i<j&&cur<=array[i])i++;
        if(i<j){
            array[j]=array[i];
        }
    }
    array[i]=cur;
    downSort(array, begin, i-1);
    downSort(array, i+1, end);
}
/*快速排序*/
void fastSort(int* array,const int size){
    if(witchModel()){
        upSort(array,0,size-1);
    }else{
        downSort(array,0,size-1);
    }
}
/*Test*/
int main(void){
    plant();
    printf("0退出   1快速排序——数组\n");
    int a;
    while(scanf("%d",&a)){
        switch (a) {
            case 0:{
                exit(0);
            }break;
            case 1:{
                int size,range;
                printf("请输入排序数组的长度和每个元素的最大值:");
                scanf("%d %d",&size,&range);
                int* array=getArray(size, range);
                printf("排序前:\n");
                output(array, size);
                fastSort(array,size);
                printf("排序后:\n");
                output(array, size);
            }break;
        }
        printf("0退出   1快速排序——数组\n");
    }
    return 0;
}