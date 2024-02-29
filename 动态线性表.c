#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
定义一个数据结构vector，这个结构是一个线性表，本质就是变长顺序数组
*/
typedef struct vector{
    int* data;
    int size,cap;
}vector;
/*初始化*/
vector* init(int cap){
    vector* temp=(vector*)malloc(sizeof(vector));
    temp->size=0;
    temp->cap=cap;
    temp->data=(int*)malloc(sizeof(int)*cap);
    return temp;
}
/*判空*/
bool isEmpty(vector *v){
    return v==NULL?true:false;
}
/*
清除
*/
void clear(vector *p){
    if(isEmpty(p)){
        free(p->data);
    }
    free(p);
}
/*
数组长度不足时，进行扩张，扩张长度为原来的一倍
*/
void expend_vector(vector *v){
    if(isEmpty(v)){
        return ;
    }
    v->cap *=2;
    v->data=(int*)realloc(v->data,sizeof(int)* v->cap);
}
/*
打印vector
*/
void show_vector(vector *v){
    if(isEmpty(v)){
        printf("null Error\n");
        return;
    }
    printf("vector :size=%d cap=%d\n",v->size,v->cap);
    for(int i=0;i<v->size;i++){
        printf("%d ",v->data[i]);
    }
    printf("\n");
}

/*在指定位置插元素*/
void insert(vector *v,int pos,int val){
    if(isEmpty(v)){
        printf("null error\n");
        return ;
    }
    if(pos<0||pos>v->cap){
        printf("insert pos error\n");
        return;
    }
    if(pos>v->size){
        printf("insert pos error\n");
        return ;
    }
    if(v->size==v->cap){
        expend_vector(v);
    }
    for(int i=v->size;i>pos;i--){
        v->data[i]=v->data[i-1];
    }
    v->data[pos]=val;
    v->size++;
}
/*在默认末尾插入元素*/
void just_insert(vector *v,int val){
    insert(v,v->size,val);
}
/*从指定位置删除元素*/
void delete_(vector* v,int pos){
    if(isEmpty(v)){
        return ;
    }
    if(pos<0||pos>=v->size){
        printf("delete pos error\n");
        return ;
    }
    for(int i=pos;i<v->size-1;i++){
        v->data[i]=v->data[i+1];
    }
    v->size--;
}
/*从默认数组尾部删除元素*/
void just_delete(vector* v){
    if(isEmpty(v)){
        return ;
    }
    if(v->size>0){
    	v->size--;    
    }
}
/**/
int main(void){
    int a,pos,val;
    vector* v=init(1);
    while(scanf("%d",&a)){
        switch(a){
            case 0:exit(0);break;
            case 1:{
                scanf("%d",&val);
                just_insert(v,val);
            };break;
            case 2:{
                scanf("%d %d",&pos,&val);
                insert(v,pos,val);
            };break;
            case 3:{
                just_delete(v);
            };break;
            case 4:{
                scanf("%d",&pos);
                delete_(v,pos);
            };break;
            case 5:{
                show_vector(v);
            };break;
        }
    }
    return 0;
}
