#include<stdlib.h>
#include<stdio.h>
#define NULL 0
typedef struct Node{
	int data;
    struct Node *Rlink,*Llink;
}*Dlink;

Dlink CreateDlink();
void InsertFirst(int,Dlink);
void TraverseDlink(Dlink);
void TraversePostDlink(Dlink);
void Reverse(Dlink);
Dlink GetElement(Dlink,int);
int GetElementLast(Dlink);
int Insert(Dlink,int,int);
int Delete(Dlink,int);
int Length(Dlink);
int IsEmpty(Dlink);
Dlink Cutout(Dlink,int,int);
Dlink Combine(Dlink,Dlink);
Dlink Sort(Dlink);
void Destory(Dlink);


int main(){
	Dlink head=CreateDlink();
	Dlink head2=CreateDlink();
	Dlink newlink;   
	int i,n;
	for(i=1;i<10;i=i+2){
		InsertFirst(i,head);
	}	
	for(i=1;i<10;i=i+2){
		InsertFirst(i,head2);
	}	
	   printf("���������");  
	TraverseDlink(head);
	   printf("\n");
	   printf("���������");
	TraversePostDlink(head);
	   printf("\n");
	   printf("��ת���������");
	Reverse(head2);
	TraverseDlink(head2);
	   printf("\n"); 
   	   printf("��ǰ������Ϊ=%d\n",Length(head));
  	   printf("���ص�һ��Ԫ�صĵ�ַ��%d\n",GetElement(head,2));
	Insert(head,2,8);
	   printf("��ʾ��������������");
	TraverseDlink(head);
	   printf("\n");
	Delete(head,3);
	   printf("��ʾɾ����3�������������");
	TraverseDlink(head);
	   printf("\n");
    newlink=Cutout(head,2,4);
	   printf("��ʾ����ȡ���ԭ����");
    TraverseDlink(head);
       printf("\n");
      printf("��ʾ��ȡ������");
	TraverseDlink(newlink);	
	   printf("\n");	
	Combine(head,newlink);
       printf("��ʾ�ϲ��������");
    TraverseDlink(head);
       printf("\n");
       printf("��������ϲ�������� ��");
	head=Sort(head);
	TraverseDlink(head);
	   printf("\n");  
	   printf("�ж������Ƿ�Ϊ��(1Ϊ�գ�0Ϊ����):%d\n",IsEmpty(head));
	   printf("��������:\n");
    Destory(head);
	TraverseDlink(head);
	return 0;
}
 Dlink CreateDlink(){                       //��һ������������һ������ͷ����˫��ѭ�������� 
 	Dlink head=malloc(sizeof(struct Node));
 	head->Llink=head;
 	head->Rlink=head;
 	return head;
 }
 Dlink GetElement(Dlink head,int i){     //�ڶ����������ҵ���i��Ԫ�أ����������ĵ�ַ   
 	Dlink p=head;
	int j;
 	if(i<0||i>Length(head)+1)
	  {
  		return NULL;
  	  }
  	  for(j=1;j<=i;j++) 
		p=p->Rlink;
		return p;
 }
int GetElementLast(Dlink head){            //�������������ҵ����һ��Ԫ�أ����������ĵ�ַ   
 	Dlink p=head;
	int j;
 	  for(j=1;j<=Length(head);j++) 
		    p=p->Rlink;
		    return p;
 }
 void InsertFirst(int x,Dlink head){        //���ĸ���������ͷ���֮��ĵ�һ������ʼ���룬����������֮�������� 
 	Dlink p=malloc(sizeof(struct Node));
 	p->data=x;
 	p->Rlink=head->Rlink;
 	p->Llink=head;
 	head->Rlink->Llink=p;
 	head->Rlink=p;
 }
  int Insert(Dlink head,int i,int x){      //������������������е�i��λ�ü���dataΪx��Ԫ�� 
  	Dlink p;
  	if(i<1||i>Length(head)+1)
	  {
  		return -1;
  	  }
  	  p=GetElement(head,i-1);
  	  if(!p)
  	  return -1;
  	  Dlink q=malloc(sizeof(struct Node));
  	  q->data=x;
  	  q->Llink=p;
  	  q->Rlink=p->Rlink;
  	  p->Rlink->Llink=q;
  	  p->Rlink=q;
  	  return 1;
 }
 int Delete(Dlink head,int i){            //������������ɾ��λ�������е�i��λ�õ����� 
 	Dlink p;
 	if(i<1)
	 {
 		return -1;
 	 }
 	 p=GetElement(head,i);
 	 p->Llink->Rlink=p->Rlink;
 	 p->Rlink->Llink=p->Llink;
 	 free(p);
 	 return 1;
 }
void Reverse(Dlink head2){
 	Dlink p1,p2;
	p1=NULL;
	p2=head2;
      while(p2){
     Dlink p3=p2->Rlink;
     p2->Rlink=p1;
     p2->Llink=p3;
     p1=p2;
     p2=p3;
      }
      return head2;
 }
 Dlink Sort(Dlink head){
 	int temp; 
	Dlink l,b,p;
	if(head->Rlink==head||head->Rlink->Rlink==head)  
	      return head;
	else{
		for(b=head->Llink;b!=head;b=b->Llink){
         	for(p=head->Rlink;p!=b;p=p->Rlink){
	        	if(p->data>p->Rlink->data){
		            temp=p->data;
		             p->data=p->Rlink->data;
		             p->Rlink->data=temp;
		            }
	            }
	        }
	        return head;
	    } 
 }
 Dlink Cutout(Dlink head,int r,int t){     //���߸���������ԭ����֮�н�ȡһ��������newlink 
 	if(r>=t){
 		return -1;
 	}
 	Dlink p;
 	int i;
 	p=GetElement(head,r);
	Dlink newlink=CreateDlink();
	for(i=1;i<=(t-r)+1;i++){
		p->Llink->Rlink=p->Rlink;
 	    p->Rlink->Llink=p->Llink;
		InsertFirst(p->data,newlink);
		p=p->Rlink;
	}
	return newlink;
 }
 
 
 Dlink Combine(Dlink head,Dlink newlink){       //�ڰ˸����������Ӻ���������ȡ���������newlink�������� 
 	 Dlink p,q;                                  
       p=head->Llink;
       q=newlink->Llink;   
       p->Rlink=newlink->Rlink;
       newlink->Rlink->Llink=p;   
	   q->Rlink=head;
	   head->Llink=q;
	 return head;
 } 
 void TraverseDlink(Dlink head){              //�ھŸ�������������������������� 
 	Dlink p=head->Rlink;
 	    while(p!=head){
 	    	printf("%d",p->data);
 	        p=p->Rlink;
 	    }
 }
 void TraversePostDlink(Dlink head){         //��ʮ��������������������������� 
 	Dlink p=head->Llink;
 	while(p!=head)
	 {
 		printf("%d",p->data);
 		p=p->Llink;
     }
 }
 int IsEmpty(Dlink head){                  //��ʮһ���������ж������Ƿ�Ϊ�� 
 	if(head->Llink==head&&head->Rlink==head)
 	return 1;
 	else
 	return 0;
 }
 int Length(Dlink head){                  //��ʮ�����������ж�����ĳ��� 
 	  int i=0;
	  Dlink p=head;
	  while(p->Rlink!=head){
	  	i++;
	  	p=p->Rlink;
	  } 
	  return i;
 }
 void Destory(Dlink head){               //��ʮ������������������ 
 	Dlink s,p=head;
 	while(p->Rlink!=head)
	 {
 		s=head->Rlink;
 		free(p);
 		p=s;
 	 }
 	 free(head); 
 	 head=NULL;
 }

