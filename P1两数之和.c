#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *twoSum(int *nums,int numsSize,int target,int *returnSize){
	int *a = (int*)malloc(sizeof(int));
	int i,j;
	for(i=0;i<numsSize;i++){
		for(j=i+1;j<numsSize;j++){
			if(nums[i]+nums[j]==target){
				a[0] = i;
				a[1] = j;
				printf("%d %d��������\n",nums[i],nums[j]);
				*returnSize = 2;
				return a;
			}
		}
	}
	*returnSize = 0;
	return a;
}

int main(){
	
	int target;
	int numsSize;
	int returnSize=2;
	
	printf("����������������Ŀ��ֵ����(4 9)��");
	scanf("%d %d",&numsSize,&target);
	printf("ʹ�������������%d��Ԫ�ص�����?Y/N\n",numsSize);
	getchar();
	char c;
	c=getchar();
	
	int i;
	int nums[numsSize];
	if(c=='n'||c=='N'){
		printf("���������飬��(2 7 56 4):");
		for(i=0;i<numsSize;i++){
			scanf("%d",&nums[i]);
		}
	}
	else if(c=='y'||c=='Y'){
		for(i=0;i<numsSize;i++){
			nums[i] = rand()%100;
		}
	}
	
	int *p = twoSum(nums,numsSize,target,&returnSize);
	
	if(returnSize==2){
		printf("������Ϊ��\n");
		for(int i=0;i<returnSize;i++){
			printf("%d ",*(p+i));
		}
	}
	else{
		printf("û�������\n");
		for(int i=0;i<numsSize;i++){
			printf("%d ",nums[i]); //û�����������������
		}
	}
	return 0;
}

/*
LeetCode�ύ����

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int *a = (int*)malloc(sizeof(int)*2);
	int i,j;
	for(i=0;i<numsSize;i++){
		for(j=i+1;j<numsSize;j++){
			if(nums[i]+nums[j]==target){
				a[0] = i;
				a[1] = j;
				*returnSize = 2;
				return a;
			}
		}
	}
	*returnSize = 0;
	return 0;
}

*/
