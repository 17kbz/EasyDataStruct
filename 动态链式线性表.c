#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*定义节点类型*/
typedef struct node{
    int data;
    struct node *next;
}node;
/*定义链表类型*/
typedef struct list{
    int size;
    node* head;
}list;
/*获取新节点*/
node* getNewNode(const int val){
    node* temp=(node*)malloc(sizeof(node));
    temp->data=val;
    temp->next=NULL;
    return temp;
}
/*初始化链表*/
list* init(){
    list* temp=(list*)malloc(sizeof(list));
    temp->size=0;
    temp->head=getNewNode(0);
    return temp;
}
/*判断链表是否为空*/
bool listIsEmpty(list* l){
    return l==NULL?true:false;
}
/*判断节点是否为空*/
bool nodeIsEmpty(node* n){
    return n==NULL?true:false;
}
/*清除所有节点*/
void clearAllNode(node* n){
    if(nodeIsEmpty(n)){
        free(n);
        return ;
    }
    //这里可以使用递归清除，也可以使用循环
    free(n->next);
    free(n);
}
/*清除链表方式1*/
void clearList(list* l){
    if(listIsEmpty(l)){
        free(l);
        return ;
    }
    clearAllNode(l->head);
    /**
    *或者使用循环清除
    无size记录时
    node* p=l->head;
    for(node* q=p->next;q;q=q->next){
        free(p);
        p=q;
    }
    free(p);
    有size记录
    node* p=l->head;
    for(int i=0;i<=l->size;i++){
        node* q=p->next;
        free(p);
        p=q;
    }
    */
}
/*头插入*/
void insertHead(list* l,const int val){
    if(listIsEmpty(l)){
        return ;
    }
    node* temp=getNewNode(val);
    temp->next=l->head->next;
    l->head->next=temp;
    l->size++;
    printf("插入成功\n");
}
/*尾插入*/
void insertTail(list* l,const int val){
    if(listIsEmpty(l)){
        return ;
    }
    node* temp=getNewNode(val);
    node* p=l->head;
    while(p->next){
        p=p->next;
    }
    p->next=temp;
    l->size++;
    printf("插入成功\n");
}
/*删除头*/
void deleteHead(list* l){
    if(listIsEmpty(l)){
        return;
    }
    if(l->size==0){
        return ;
    }
    node* temp=l->head->next;
    l->head->next=l->head->next->next;
    l->size--;
    free(temp);
    printf("删除成功\n");
}
/*删除尾*/
void deleteTail(list *l){
    if(listIsEmpty(l)){
        return ;
    }
    if(l->size==0){
        return ;
    }
    node *p=l->head;
    node* q=p->next;
    while(q->next){
        p=q;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    l->size--;
    printf("删除成功\n");
}
/*输出结构*/
void showList(list* l){
    if(listIsEmpty(l)){
        return;
    }
    if(l->size==0){
        return ;
    }
    printf("size:%d\n",l->size);
    node* temp=l->head->next;
    while (temp->next){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}
/*Test*/
int main(void){
    list* l=init();
    printf("0退出   1头插入     2尾插入     3删除头     4删除尾     5展示\n");
    int a,val;
    while(scanf("%d",&a)){
        switch(a){
            case 0:{
                clearList(l);
                exit(0);
            }break;
            case 1:{
                printf("请输入要插入的数据:");
                scanf("%d",&val);
                insertHead(l,val);
            }break;
            case 2:{
                printf("请输入要插入的数据:");
                scanf("%d",&val);
                insertTail(l,val);
            }break;
            case 3:{
                deleteHead(l);
            }break;
            case 4:{
                deleteTail(l);
            }break;
            case 5:{
                showList(l);
            }break;
        }
        printf("0退出   1头插入     2尾插入     3删除头     4删除尾     5展示\n");
    }
    return 0;
}