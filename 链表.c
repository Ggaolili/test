#include<stdio.h>
#include<malloc.h>

typedef struct Lnode
{
    int data;        ///数据域
    struct Lnode *next;///指针域
}LNODE,*Linklist;///自定义方式将结构定义为LNODE类型  在定义一个指向LNODE的指针类型变量

Linklist creat(Linklist L)
{
    int node;Linklist p;
    L=(Linklist)malloc(sizeof(LNODE));///为新建的结点L开辟内存空间
    L->next=NULL;///L指针域为空
    printf("\nplease input the node(end with 0):\n");
    scanf("%d",&node);
    while(node!=0)
    {
        p=(Linklist)malloc(sizeof(LNODE));///为新建的结点p开辟内存空间
        if(!p) break;///如果非p就跳出
        p->data=node; ///将p的数据域指向node
        p->next=L->next;///将p的指针域指向L的指针域
        L->next=p;///将L的指针域指向p
        scanf("%d",&node);  ///输出node的值
    }
    return L;///返回L
}

Linklist insert(Linklist L,int i,int x)      ///插入
{
    int j;
    Linklist p,s;
    p=L;j=0;
    while(p!=NULL&&j<i-1)///当p不等于空值同时满足j<i-1
    {
        p=p->next;///将p指向p的指针域
        ++j;    /// 先增加在执行
    }
    if(p==NULL||j>i-1)    ///如果p=空值或者j大于i-1
        printf("\nERROR position!\n");///输出ERROR position!
    else
    {
        s=(Linklist)malloc(sizeof(LNODE));///为新建的结点s开辟内存空间
        s->data=x;            ///将s的数据域指向x
        s->next=p->next;         ///将s的指针域指向p的指针域
        p->next=s;            ///将P的指针域指向s
    }
    return L;                  ///返回L
}
Linklist delete(Linklist L,int i)
{
    int j,x;
    Linklist p,q;
    p=L;j=0;                     ///p指向L,j=0
    while(p->next!=NULL&&j<i-1)         ///p的指针域不为空同时满足j小于i-1
    {
        p=p->next;          ///p指向p的指针域
        ++j;                 ///先增加在执行
    }
    if(p->next==NULL||j>i-1)            ///如果满足p的指针域不为空或j大于i-1
    printf("\nERROR position!\n");      ///输出ERROR position
    else                                ///否则执行
    {
        q=p->next;                      ///q指向p的指针域
        p->next=q->next;                ///p的指针域指向q的指针域
        x=q->data;                  ///x指向q的数据域
        printf("the delete data is:%d\n",x);           ///输出要删除的数据是：
        free(q);             ///释放该节点
    }
    return L;
}
int search(Linklist L,int i)           ///查找
{
    Linklist p;int j;
    p=L->next;                 ///p指向L的指针域
    j=1;                      ///使j=1
    while(p&&j<i)             ///当满足存在p或j<i时
    {
        p=p->next;              ///p指向p的指针域
        j++;                    ///j自增
    }
    if(!p&&j>i)                 ///如果满足非p或j<i时
        return 0;               ///返回0
    else                         ///否则
        return(p->data);         ///返回p的数据域
}
void display(Linklist L)        ///显示函数
{
    Linklist p;
    p=L->next;                ///p指向L的指针域
    while(p!=NULL)            ///当p不为空时
    {
        printf("%4d",p->data);   ///输出p数据域的数据
        p=p->next;               ///p指向p的指针域
    }
    printf("\n");
}
int main()
{
    Linklist L=NULL;int i,x;  ///单链表L为空，
    L=creat(L);
    printf("the Linklist is:\n");
    display(L);
    printf("please input the position you want to insert；");///输出你想要插入的位置
    scanf("%d",&i);
    printf("please input the node you want to insert；");  ///输出你想要插入的数据
    scanf("%d",&x);
    L=insert(L,i,x);
    printf("the Linklist after inserted is；");  ///表之后插入的是：
   display(L);
    printf("please input the position you want to delete；");///输出你想要删除的位置
    scanf("%d",&i);
    L=delete(L,i);
    printf("the Linklist after delete is；");
   display(L);
    printf("please input the position you want to search；");///输出你想要查找的位置
    scanf("%d",&i);
    x=search(L,i);
    if(x)
        printf("\nthe %dth elem is %d\n",i,x);
    else
     printf("\nthe %dth elem is not sxsit\n",i);
    return 0;
}
