#include<Stdio.h>
#define MAXSIZE 100
typedef int elemtype;
/* 定义线性表 */
typedef struct
{

elemtype list[MAXSIZE];
int last;

} Seqlist;
/* 初始化线性表 */
void Initlist(Seqlist*L)
{
    L->last=-1;
}
/* 输入递增有序的线性表 */
void Inputlist(Seqlist*L,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&(L->list[i]));
    }
    L->last=L->last+n;
}
/* 求表长 */
int Listlength(Seqlist*L)
{
     int len;
     len=L->last+1;
     return len;
}
/* 判断插入位置*/
int Locate(Seqlist*L,int x)
{
    int j;
    for(j=0;j<=L->last;j++)
        if(x<=L->list[j])
          return j+1;
 return(L->last+2);
}
/* 插入元素 */
int insert(Seqlist*L,int i,int p)
{
int k;
if(i<1||i>L->last+2)
{
    printf("输入位置不合理");
    return (0);
}
if (L->last>=MAXSIZE-1)
{
    printf("线性表满");
    return 0;
}
for (k=L->last;k>i-1;k--)
L->list[k+1]=L->list[k];
L->list[i]=p;
L->last++;
return (1);


}
/* 输出元素 */
void Outputlist(Seqlist*L)
{
    int i;
    printf("输出结果为：");
    for(i=0;i<=L->last;i++)
    printf("%d ",L->list[i]);
    return (L->list[i]);
}
int main (){
int s,c;
Seqlist L;
Initlist(&L);
printf("请输入循序表的长度：");
scanf("%d",&s);
printf("请输入递增顺序表:");
Inputlist(&L,s);
Listlength(&L);
printf("表长为%d\n",Listlength(&L));
printf("请输入要插入的元素：");
scanf("%d",&c);
insert(&L,Locate(&L,c),c);
Outputlist(&L);
printf("\n");

}
