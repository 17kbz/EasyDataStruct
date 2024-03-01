#include"ezdata.h"
/*从小到大排序*/
void upSort(int* array,const int size){
    for(int i=0;i<size-1;i++){
        int cur=i;
        for(int j=i+1;j<size;j++){
            if(array[j]<array[cur]){
                cur=j;
            }
        }
        swap(&array[i], &array[cur]);
    }
}

/*从大到小排序*/
void downSort(int* array,const int size){

}
/*选择排序*/
void selectSort(int* array,const int size){
    if(witchModel()){
        upSort(array, size);
    }else{
        downSort(array, size);
    }
}
/*Test*/
int main(void){
    plant();
    printf("0退出   1选择排序——数组\n");
    int a;
    while(scanf("%d",&a)){
        switch(a){
            case 0:{
                exit(0);
            }break;
            case 1:{
                int size,range;
                printf("请输入数组的长度和每个元素的范围:\n");
                scanf("%d %d",&size,&range);
                int* array=getArray(size, range);
                output(array, size);
                selectSort(array, size);
                output(array, size);
            }break;
        }
        printf("0退出   1选择排序——数组\n");
    }
    return 0;
}