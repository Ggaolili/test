#include<stdio.h>
#include<malloc.h>

typedef struct Lnode
{
    int data;        ///������
    struct Lnode *next;///ָ����
}LNODE,*Linklist;///�Զ��巽ʽ���ṹ����ΪLNODE����  �ڶ���һ��ָ��LNODE��ָ�����ͱ���

Linklist creat(Linklist L)
{
    int node;Linklist p;
    L=(Linklist)malloc(sizeof(LNODE));///Ϊ�½��Ľ��L�����ڴ�ռ�
    L->next=NULL;///Lָ����Ϊ��
    printf("\nplease input the node(end with 0):\n");
    scanf("%d",&node);
    while(node!=0)
    {
        p=(Linklist)malloc(sizeof(LNODE));///Ϊ�½��Ľ��p�����ڴ�ռ�
        if(!p) break;///�����p������
        p->data=node; ///��p��������ָ��node
        p->next=L->next;///��p��ָ����ָ��L��ָ����
        L->next=p;///��L��ָ����ָ��p
        scanf("%d",&node);  ///���node��ֵ
    }
    return L;///����L
}

Linklist insert(Linklist L,int i,int x)      ///����
{
    int j;
    Linklist p,s;
    p=L;j=0;
    while(p!=NULL&&j<i-1)///��p�����ڿ�ֵͬʱ����j<i-1
    {
        p=p->next;///��pָ��p��ָ����
        ++j;    /// ��������ִ��
    }
    if(p==NULL||j>i-1)    ///���p=��ֵ����j����i-1
        printf("\nERROR position!\n");///���ERROR position!
    else
    {
        s=(Linklist)malloc(sizeof(LNODE));///Ϊ�½��Ľ��s�����ڴ�ռ�
        s->data=x;            ///��s��������ָ��x
        s->next=p->next;         ///��s��ָ����ָ��p��ָ����
        p->next=s;            ///��P��ָ����ָ��s
    }
    return L;                  ///����L
}
Linklist delete(Linklist L,int i)
{
    int j,x;
    Linklist p,q;
    p=L;j=0;                     ///pָ��L,j=0
    while(p->next!=NULL&&j<i-1)         ///p��ָ����Ϊ��ͬʱ����jС��i-1
    {
        p=p->next;          ///pָ��p��ָ����
        ++j;                 ///��������ִ��
    }
    if(p->next==NULL||j>i-1)            ///�������p��ָ����Ϊ�ջ�j����i-1
    printf("\nERROR position!\n");      ///���ERROR position
    else                                ///����ִ��
    {
        q=p->next;                      ///qָ��p��ָ����
        p->next=q->next;                ///p��ָ����ָ��q��ָ����
        x=q->data;                  ///xָ��q��������
        printf("the delete data is:%d\n",x);           ///���Ҫɾ���������ǣ�
        free(q);             ///�ͷŸýڵ�
    }
    return L;
}
int search(Linklist L,int i)           ///����
{
    Linklist p;int j;
    p=L->next;                 ///pָ��L��ָ����
    j=1;                      ///ʹj=1
    while(p&&j<i)             ///���������p��j<iʱ
    {
        p=p->next;              ///pָ��p��ָ����
        j++;                    ///j����
    }
    if(!p&&j>i)                 ///��������p��j<iʱ
        return 0;               ///����0
    else                         ///����
        return(p->data);         ///����p��������
}
void display(Linklist L)        ///��ʾ����
{
    Linklist p;
    p=L->next;                ///pָ��L��ָ����
    while(p!=NULL)            ///��p��Ϊ��ʱ
    {
        printf("%4d",p->data);   ///���p�����������
        p=p->next;               ///pָ��p��ָ����
    }
    printf("\n");
}
int main()
{
    Linklist L=NULL;int i,x;  ///������LΪ�գ�
    L=creat(L);
    printf("the Linklist is:\n");
    display(L);
    printf("please input the position you want to insert��");///�������Ҫ�����λ��
    scanf("%d",&i);
    printf("please input the node you want to insert��");  ///�������Ҫ���������
    scanf("%d",&x);
    L=insert(L,i,x);
    printf("the Linklist after inserted is��");  ///��֮�������ǣ�
   display(L);
    printf("please input the position you want to delete��");///�������Ҫɾ����λ��
    scanf("%d",&i);
    L=delete(L,i);
    printf("the Linklist after delete is��");
   display(L);
    printf("please input the position you want to search��");///�������Ҫ���ҵ�λ��
    scanf("%d",&i);
    x=search(L,i);
    if(x)
        printf("\nthe %dth elem is %d\n",i,x);
    else
     printf("\nthe %dth elem is not sxsit\n",i);
    return 0;
}
