#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	node* pre;
};

void pushfront(node* &phead)
{
	int x; cin >> x;
	node* newnode = new node;
	newnode->data = x;
	phead->pre = newnode;
	newnode->next = phead;
	phead=newnode;
	phead->pre = NULL;
}
node* tail = new node;
void pushback(node* phead)
{
	int x; cin >> x;
	node* p = phead;
	node* newnode = new node;
	newnode->data = x;
	newnode->next = NULL;
	newnode->pre = tail;
	tail->next = newnode;
	tail = newnode;
}

node* findnode(node* phead, int x)
{
	node* p = new node;
	p = phead;
	if (p->data == x)return p;
	while (p->data != x)
	{
		p = p->next;
		if (p->data == x)return p;
	}
	return NULL;
}

void insertnodeback(node*phead,int x)
{
	
	int cur = 1;
	while (cur != x)
	{
		cur++;
		phead = phead->next;
	}
	node* newnode = new node;
	int y; cin >> y;
	newnode->data = y;
	newnode->next = phead->next;
	phead->next->pre = newnode;
	newnode->pre = phead;
	phead->next = newnode;
}


node* findnode1(node* phead, int x)
{
	int cur = 1;
	node* p = phead;
	if (x == 1)
	{
		return phead;
	}
	while (cur != x)
	{
		cur++;
		p = p->next;
		if (cur == x)
		{
			return p;
		}
		else if (p->next == NULL)
		{
			cout << "not exist";
			return NULL;
		};
	}
}
void erasenode(node* &head,int x)
{
	int cur = 1;
	if (x == 1)
	{
		head = head->next;
		return;
	}
	node* p = head;
	while (cur != x - 1)
	{
		cur++;
		p = p->next;
		if (cur == x - 1)
		{
			
			p->next->next->pre = p;
			p->next = p->next->next;
			
			return;
		}
		else if (p->next == NULL)
		{
			cout << "not exist";
			return;
		}
	}
	
}

void insertionsort(node*& head)
{
	if (!head || !(head->next))
	{
		return;
	}
	node* dum = new node;
	dum->next = NULL;
	while (head)
	{
		node* cur = dum->next;
		node* pre = dum;
		while (cur && head->data > cur->data)
		{
			pre = cur;
			cur = cur->next;
		}
		pre->next = head; head = head->next;
		pre->next->next = cur;
	}
	head = dum->next;
	delete dum;
}

void print(node* phead)
{
	while (phead != NULL)
	{
		cout << phead->data<<' ';
		phead = phead->next;
	}
	cout << '\n';
}

int main()
{
	node* head=new node;
	head->data = 1;
	head->next = NULL;
	head->pre = NULL;
	tail = head;
	
	
}