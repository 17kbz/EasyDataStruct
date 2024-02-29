#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct vector{
    int* data;
    int size,cap;
}vector;
vector* init(int cap){
    vector* temp=(vector*)malloc(sizeof(vector));
    temp->size=0;
    temp->cap=cap;
    temp->data=(int*)malloc(sizeof(int)*cap);
    return temp;
}
bool isEmpty(vector *v){
    return v==NULL?true:false;
}
void clear(vector *p){
    if(isEmpty(p)){
        free(p->data);
    }
    free(p);
}
void expend_vector(vector *v){
    if(isEmpty(v)){
        return ;
    }
    v->cap *=2;
    v->data=(int*)realloc(v->data,sizeof(int)* v->cap);
}
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
void just_insert(vector *v,int val){
    insert(v,v->size,val);
}
void delete_(vector* v,int pos){
    if(isEmpty(v)){
        return ;
    }
    if(pos<0||pos>=v->size){
        printf("delete pos error");
        return ;
    }
    for(int i=pos;i<v->size-1;i++){
        v->data[i]=v->data[i+1];
    }
    v->size--;
}
void just_delete(vector* v){
    if(isEmpty(v)){
        return ;
    }
    if(v->size>0){
    	v->size--;    
    }
}
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