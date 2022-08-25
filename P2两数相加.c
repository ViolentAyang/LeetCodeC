#include<stdio.h>
#include<stdlib.h>

struct ListNode{
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1,struct ListNode* l2){ //本质就是大数相加
	
	struct ListNode* pre = (struct ListNode*)malloc(sizeof(struct ListNode));
	pre->val = 0;
	pre->next = NULL;
	
	struct ListNode* cur = pre;
	int carry = 0;//进位
	int sum = 0;
	
	while(l1!=NULL||l2!=NULL){
		int x = (l1 == NULL) ? 0:l1->val; //两个链表有谁到了尾巴就取另一条的数+0
		int y = (l2 == NULL) ? 0:l2->val;
		
		sum = x + y + carry;
		carry = sum/10; //需要进位的值
		
		struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
		p->val = sum%10;
		p->next = NULL;
		
		cur->next = p;
		cur = cur->next;
		
		if(l1!=NULL){
			l1 = l1->next;
		}
		if(l2!=NULL){
			l2 = l2->next;
		}
	}
		
	if(carry==1){ //如果有进位，把进位单独链入链表尾部
		struct ListNode* ca = (struct ListNode*)malloc(sizeof(struct ListNode));
		ca->val = carry;
		ca->next = NULL;
		cur->next = ca;
	}
	return pre->next;
}

struct ListNode *create(){ //尾插法建立单链表
	int n;
	printf("请输入节点个数，例如(3):");
	scanf("%d",&n);
	struct ListNode *p,*pre;
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
	int headval;
	scanf("%d",&headval);
	head->val = headval;
	head->next = NULL;
    pre = head;
	for(int i=1;i<n;i++){
		p = (struct ListNode*)malloc(sizeof(struct ListNode));
		int val;
		scanf("%d",&val);
		p->val = val;
		pre->next = p;
		pre = p;
	}
	pre->next = NULL;
	return head;
}

void print(struct ListNode* L){
	if(L == NULL){
		return;
	}
	while(L != NULL){
		printf("%d ",L->val);
		L = L->next;
	}
}


int main()
{
	
	struct ListNode *l1;  //地址
	struct ListNode *l2;
	struct ListNode *result;
	//创建尾插法创建无头节点单链表
	l1=create();
	l2=create();
	
	
	//调用输出链表的函数
	print(l1);
	printf("\n");
	print(l2);
	printf("\n");
	
	result=addTwoNumbers( l1,  l2);
	print(result);
	return 0;
}

/*
	LeetCode提交的代码
struct ListNode* addTwoNumbers(struct ListNode* l1,struct ListNode* l2){ //本质就是大数相加
	
	 	struct ListNode* pre = (struct ListNode*)malloc(sizeof(struct ListNode));
	pre->val = 0;
	pre->next = NULL;
	
	struct ListNode* cur = pre;
	int carry = 0;//进位
	int sum = 0;
	
	while(l1!=NULL||l2!=NULL){
		int x = (l1 == NULL) ? 0:l1->val; //两个链表有谁到了尾巴就取另一条的数+0
		int y = (l2 == NULL) ? 0:l2->val;
		
		sum = x + y + carry;
		carry = sum/10; //需要进位的值
		
		struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
		p->val = sum%10;
		p->next = NULL;
		
		cur->next = p;
		cur = cur->next;
		
		if(l1!=NULL){
			l1 = l1->next;
		}
		if(l2!=NULL){
			l2 = l2->next;
		}
	}
		
	if(carry==1){ //如果有进位，把进位单独链入链表尾部
		struct ListNode* ca = (struct ListNode*)malloc(sizeof(struct ListNode));
		ca->val = carry;
		ca->next = NULL;
		cur->next = ca;
	}
	return pre->next;

}
*/
