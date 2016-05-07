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
	   printf("正序输出：");  
	TraverseDlink(head);
	   printf("\n");
	   printf("倒序输出：");
	TraversePostDlink(head);
	   printf("\n");
	   printf("反转链表并输出：");
	Reverse(head2);
	TraverseDlink(head2);
	   printf("\n"); 
   	   printf("当前链表长度为=%d\n",Length(head));
  	   printf("返回第一个元素的地址：%d\n",GetElement(head,2));
	Insert(head,2,8);
	   printf("显示插入后链表情况：");
	TraverseDlink(head);
	   printf("\n");
	Delete(head,3);
	   printf("显示删除第3个链表后的情况：");
	TraverseDlink(head);
	   printf("\n");
    newlink=Cutout(head,2,4);
	   printf("显示被截取后的原链表：");
    TraverseDlink(head);
       printf("\n");
      printf("显示截取的链表：");
	TraverseDlink(newlink);	
	   printf("\n");	
	Combine(head,newlink);
       printf("显示合并后的链表：");
    TraverseDlink(head);
       printf("\n");
       printf("重新排序合并后的链表 ：");
	head=Sort(head);
	TraverseDlink(head);
	   printf("\n");  
	   printf("判断链表是否为空(1为空，0为不空):%d\n",IsEmpty(head));
	   printf("销毁链表:\n");
    Destory(head);
	TraverseDlink(head);
	return 0;
}
 Dlink CreateDlink(){                       //第一个函数：构造一个具有头结点的双向循环空链表 
 	Dlink head=malloc(sizeof(struct Node));
 	head->Llink=head;
 	head->Rlink=head;
 	return head;
 }
 Dlink GetElement(Dlink head,int i){     //第二个函数：找到第i个元素，并返回它的地址   
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
int GetElementLast(Dlink head){            //第三个函数：找到最后一个元素，并返回它的地址   
 	Dlink p=head;
	int j;
 	  for(j=1;j<=Length(head);j++) 
		    p=p->Rlink;
		    return p;
 }
 void InsertFirst(int x,Dlink head){        //第四个函数：从头结点之后的第一个链表开始插入，进而往链表之中输入数 
 	Dlink p=malloc(sizeof(struct Node));
 	p->data=x;
 	p->Rlink=head->Rlink;
 	p->Llink=head;
 	head->Rlink->Llink=p;
 	head->Rlink=p;
 }
  int Insert(Dlink head,int i,int x){      //第五个函数：往链表当中第i个位置加入data为x的元素 
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
 int Delete(Dlink head,int i){            //第六个函数：删除位于链表当中第i个位置的链表 
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
 Dlink Cutout(Dlink head,int r,int t){     //第七个函数：从原链表之中截取一个新链表newlink 
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
 
 
 Dlink Combine(Dlink head,Dlink newlink){       //第八个函数：连接函数，将截取后的链表与newlink重新连接 
 	 Dlink p,q;                                  
       p=head->Llink;
       q=newlink->Llink;   
       p->Rlink=newlink->Rlink;
       newlink->Rlink->Llink=p;   
	   q->Rlink=head;
	   head->Llink=q;
	 return head;
 } 
 void TraverseDlink(Dlink head){              //第九个函数：按照正序输出整个链表 
 	Dlink p=head->Rlink;
 	    while(p!=head){
 	    	printf("%d",p->data);
 	        p=p->Rlink;
 	    }
 }
 void TraversePostDlink(Dlink head){         //第十个函数：按照逆序输出整个链表 
 	Dlink p=head->Llink;
 	while(p!=head)
	 {
 		printf("%d",p->data);
 		p=p->Llink;
     }
 }
 int IsEmpty(Dlink head){                  //第十一个函数：判断链表是否为空 
 	if(head->Llink==head&&head->Rlink==head)
 	return 1;
 	else
 	return 0;
 }
 int Length(Dlink head){                  //第十二个函数：判断链表的长度 
 	  int i=0;
	  Dlink p=head;
	  while(p->Rlink!=head){
	  	i++;
	  	p=p->Rlink;
	  } 
	  return i;
 }
 void Destory(Dlink head){               //第十三个函数：析构链表 
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

