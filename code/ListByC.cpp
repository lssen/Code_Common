
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
	//�����½�� ͬʱʹp1 p2ָ��ý��
	p1 = p2 = (ListNode *)malloc(sizeof(ListNode));
	printf("Input the value! ");
	scanf("%d", &p1->val);
	//��ʱhead��ָ��ΪNULL
	head = nullptr;
	while (p1->val != 0) {
		//n��������
		n = n + 1;
		if (n == 1) {
			//n=1 ˵���ý���ǵ�һ����� ʹheadָ��ý��
			head = p1;
		}
		else {
			//�������ͷ��� ��p1��ָ��Ľ��������p2��ָ����ĺ���
			p2->next = p1;
		}
		//ʹp2��ǰ�� 
		p2 = p1;
		//�����½�� ʹp1ָ����
		p1 = (ListNode *)malloc(sizeof(ListNode));
		printf("Input the value! ");
		scanf("%d", &p1->val);
	}
	//ѭ���˳�֮�� ʹp2ָ��NULL ��Ϊ�����β���ָ��nullptr
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
void InitHead(ListNode * *pHead)  //Ϊ��������ͷ��� ʹͷָ��ָ��ͷ���
{
	*pHead = (ListNode *)malloc(sizeof(ListNode));
	if (*pHead == nullptr)
	{
		printf("ͷ������ʧ�ܣ�������ֹ�� \n");
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
	ListNode * pNew = (ListNode *)malloc(sizeof(ListNode)); //�����½ڵ�
	if (pNew == nullptr)
	{
		printf("�½ڵ����ʧ�ܣ�������ֹ�� \n");
		exit(-1);
	}
	pNew->val = data;
	pNew->next = nullptr;

	while (r->next != nullptr) //��βָ��ѭ��ֱ�����һ���ڵ�
	{
		r = r->next;
	}

	r->next = pNew;
	r = pNew;

}

void printList(ListNode * pHead)
{
	pHead = pHead->next; //����ͷ������
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