#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
} *head;
node *st=NULL;
void reverse(node *x,node *p){
	if(x==NULL){
		// cout<<p->data;
		head=p;
		return;
	}
	// st=p;
	reverse(x->next,x);
	x->next=p;
}
void push(int n){
	node *tmp=new node;
	tmp->data=n;
	tmp->next=NULL;
	if(head==NULL){
		head=tmp;
	}else{
		node *x=head;
		while(x->next!=NULL){
			x=x->next;
		}
		x->next=tmp;
	}
}
int main(){
	int n;
	head=NULL;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		push(x);
	}
	reverse(head,NULL);

	// node *x=head,*p=NULL;
	// while(x!=NULL){
	// 	node *t=x;
	// 	x=x->next;
	// 	t->next=p;
	// 	p=t;
	// }
	// head=p;
	node *x=head;
	while(x!=NULL){
		cout<<x->data<<" ";
		x=x->next;
		}
}