#include<Stdio.h>
#define MAXSIZE 100
typedef int elemtype;
/* �������Ա� */
typedef struct
{

elemtype list[MAXSIZE];
int last;

} Seqlist;
/* ��ʼ�����Ա� */
void Initlist(Seqlist*L)
{
    L->last=-1;
}
/* ���������������Ա� */
void Inputlist(Seqlist*L,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&(L->list[i]));
    }
    L->last=L->last+n;
}
/* ��� */
int Listlength(Seqlist*L)
{
     int len;
     len=L->last+1;
     return len;
}
/* �жϲ���λ��*/
int Locate(Seqlist*L,int x)
{
    int j;
    for(j=0;j<=L->last;j++)
        if(x<=L->list[j])
          return j+1;
 return(L->last+2);
}
/* ����Ԫ�� */
int insert(Seqlist*L,int i,int p)
{
int k;
if(i<1||i>L->last+2)
{
    printf("����λ�ò�����");
    return (0);
}
if (L->last>=MAXSIZE-1)
{
    printf("���Ա���");
    return 0;
}
for (k=L->last;k>i-1;k--)
L->list[k+1]=L->list[k];
L->list[i]=p;
L->last++;
return (1);


}
/* ���Ԫ�� */
void Outputlist(Seqlist*L)
{
    int i;
    printf("������Ϊ��");
    for(i=0;i<=L->last;i++)
    printf("%d ",L->list[i]);
    return (L->list[i]);
}
int main (){
int s,c;
Seqlist L;
Initlist(&L);
printf("������ѭ���ĳ��ȣ�");
scanf("%d",&s);
printf("���������˳���:");
Inputlist(&L,s);
Listlength(&L);
printf("��Ϊ%d\n",Listlength(&L));
printf("������Ҫ�����Ԫ�أ�");
scanf("%d",&c);
insert(&L,Locate(&L,c),c);
Outputlist(&L);
printf("\n");

}
