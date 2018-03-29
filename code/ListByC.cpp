
#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode  * create() {
	int n = 0;
	ListNode *head, *p1, *p2;
	//开辟新结点 同时使p1 p2指向该结点
	p1 = p2 = (ListNode *)malloc(sizeof(ListNode));
	printf("Input the value! ");
	scanf("%d", &p1->val);
	//此时head的指向为NULL
	head = nullptr;
	while (p1->val != 0) {
		//n代表结点数
		n = n + 1;
		if (n == 1) {
			//n=1 说明该结点是第一个结点 使head指向该结点
			head = p1;
		}
		else {
			//如果不是头结点 把p1所指向的结点链接在p2所指向结点的后面
			p2->next = p1;
		}
		//使p2向前移 
		p2 = p1;
		//开辟新结点 使p1指向它
		p1 = (ListNode *)malloc(sizeof(ListNode));
		printf("Input the value! ");
		scanf("%d", &p1->val);
	}
	//循环退出之后 使p2指向NULL 因为链表的尾结点指向nullptr
	p2->next = nullptr;
	return head;
}

ListNode reverse(ListNode x){
	ListNode t , y = x,r = nullptr;
	while(y!=nullptr){
		t = y->next;
		y->next = r;
		r = y;
		y = t;
	}
	return r;
}
void InitHead(ListNode * *pHead)  //为链表生成头结点 使头指针指向头结点
{
	*pHead = (ListNode *)malloc(sizeof(ListNode));
	if (*pHead == nullptr)
	{
		printf("头结点分配失败，程序终止！ \n");
		exit(-1);
	}
	(*pHead)->next = NULL;
}

void DestroyList(ListNode *pt) { // destroy the pointer
	ListNode *tempPointer;
	while (pt != nullptr) {
		tempPointer = pt;
		pt = pt->next;
		free(tempPointer);
		tempPointer = nullptr;
	}
}

void append(ListNode * pHead, int data)
{
	ListNode * r = pHead;
	ListNode * pNew = (ListNode *)malloc(sizeof(ListNode)); //生成新节点
	if (pNew == nullptr)
	{
		printf("新节点分配失败，程序终止！ \n");
		exit(-1);
	}
	pNew->val = data;
	pNew->next = nullptr;

	while (r->next != nullptr) //让尾指针循环直到最后一个节点
	{
		r = r->next;
	}

	r->next = pNew;
	r = pNew;

}

void printList(ListNode * pHead)
{
	pHead = pHead->next; //跳过头结点输出
	while (pHead != nullptr)
	{
		printf("%d ", pHead->val);
		pHead = pHead->next;
	}
}

int main(void)
{
	ListNode * L = nullptr;
	InitHead(&L);
	append(L, 1);
	append(L, 4);
	append(L, 7);
	append(L, 9);
	append(L, 332);
	append(L, 6);
	append(L, 235);
	printList(L);
	DestroyList(L);
	system("pause");
	L = nullptr;
	return 0;
}