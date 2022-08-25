#include<stdio.h>
#include<stdlib.h>

struct ListNode{
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1,struct ListNode* l2){ //���ʾ��Ǵ������
	
	struct ListNode* pre = (struct ListNode*)malloc(sizeof(struct ListNode));
	pre->val = 0;
	pre->next = NULL;
	
	struct ListNode* cur = pre;
	int carry = 0;//��λ
	int sum = 0;
	
	while(l1!=NULL||l2!=NULL){
		int x = (l1 == NULL) ? 0:l1->val; //����������˭����β�;�ȡ��һ������+0
		int y = (l2 == NULL) ? 0:l2->val;
		
		sum = x + y + carry;
		carry = sum/10; //��Ҫ��λ��ֵ
		
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
		
	if(carry==1){ //����н�λ���ѽ�λ������������β��
		struct ListNode* ca = (struct ListNode*)malloc(sizeof(struct ListNode));
		ca->val = carry;
		ca->next = NULL;
		cur->next = ca;
	}
	return pre->next;
}

struct ListNode *create(){ //β�巨����������
	int n;
	printf("������ڵ����������(3):");
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
	
	struct ListNode *l1;  //��ַ
	struct ListNode *l2;
	struct ListNode *result;
	//����β�巨������ͷ�ڵ㵥����
	l1=create();
	l2=create();
	
	
	//�����������ĺ���
	print(l1);
	printf("\n");
	print(l2);
	printf("\n");
	
	result=addTwoNumbers( l1,  l2);
	print(result);
	return 0;
}

/*
	LeetCode�ύ�Ĵ���
struct ListNode* addTwoNumbers(struct ListNode* l1,struct ListNode* l2){ //���ʾ��Ǵ������
	
	 	struct ListNode* pre = (struct ListNode*)malloc(sizeof(struct ListNode));
	pre->val = 0;
	pre->next = NULL;
	
	struct ListNode* cur = pre;
	int carry = 0;//��λ
	int sum = 0;
	
	while(l1!=NULL||l2!=NULL){
		int x = (l1 == NULL) ? 0:l1->val; //����������˭����β�;�ȡ��һ������+0
		int y = (l2 == NULL) ? 0:l2->val;
		
		sum = x + y + carry;
		carry = sum/10; //��Ҫ��λ��ֵ
		
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
		
	if(carry==1){ //����н�λ���ѽ�λ������������β��
		struct ListNode* ca = (struct ListNode*)malloc(sizeof(struct ListNode));
		ca->val = carry;
		ca->next = NULL;
		cur->next = ca;
	}
	return pre->next;

}
*/
