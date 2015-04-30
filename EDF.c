#include<stdlib.h>

#ifndef VST_NV_NODE
#define VST_NV_NODE
struct node
{
int pn, arrive, deadline, exec;
struct node *next;

};
int prnum = 1, totalTime = 0;

inline void getdata(struct node *newobj, struct node *nextlink)
{
newobj->pn = prnum;
printf("\nEnter Arrival Time for Process %d:", prnum);
scanf("%d", &newobj->arrive);

printf("\nEnter Deadline for Process %d:", prnum);
scanf("%d", &newobj->deadline);

printf("\nEnter Execution Time for Process %d:", prnum);
scanf("%d", &newobj->exec);

newobj->next=nextlink;
prnum++;
totalTime += newobj->exec;
}
#endif

#ifndef VST_NV_LIST
#define VST_NV_LIST
struct node* insert(struct node *list, struct node *predefin)
{
struct node *curr = NULL;
if(predefin == NULL)
{
	if(list==NULL)
	{
		list=(struct node*)malloc(sizeof(struct node));
		prnum;
		getdata(list,NULL);
	}
	else
	{
		for(curr=list; curr -> next != NULL; curr = curr -> next);
		curr -> next = (struct node*)malloc(sizeof(struct node));
		curr = curr -> next;
		getdata(curr,NULL);
	}
}

else
{
	if(list==NULL)
	{
		list=(struct node*)malloc(sizeof(struct node));
		*list = *predefin;
		list -> next = NULL;
	}
	else
	{
		for(curr=list; curr -> next != NULL; curr = curr -> next);
		curr -> next = (struct node*)malloc(sizeof(struct node));
		curr = curr -> next;
		*curr = *predefin;
		curr -> next = NULL;
	}
}
return list;
}

int min_deadline_exec(struct node *start, int time)
{
int minValue = 0, pnum = 0;
struct node *list = start;
if(list == NULL)
	printf("\nList is empty!!!");

else
{
	for(; list -> arrive > time && list != NULL; list = list -> next);
	minValue = list -> deadline;
	pnum = list -> pn;
	list = list -> next;

	while(list)
	{
		if(list -> deadline < minValue && list -> arrive <= time)
		{
			minValue = list -> deadline;
			pnum = list -> pn;
		}
		list = list -> next;
	}
}

for(list = start; list -> pn != pnum; list = list -> next);
list -> exec -= 1;
if(list -> exec == 0)
{
	pnum *= -1;
}
return pnum;
}

int min_slack_exec(struct node *start, int time)
{
int minValue = 0, pnum = 0;
struct node *list = start;
if(list == NULL)
	printf("\nList is empty!!!");

else
{
	for(; list -> arrive > time && list != NULL; list = list -> next);
	minValue = time - list -> deadline - list -> exec;
	pnum = list -> pn;
	list = list -> next;

	while(list)
	{
		if(time - list -> deadline - list -> exec < minValue && list -> arrive <= time)
		{
			minValue = time - list -> deadline - list -> exec;
			pnum = list -> pn;
		}
		list = list -> next;
	}
}

for(list = start; list -> pn != pnum; list = list -> next);
list -> exec -= 1;
if(list -> exec == 0)
{
	pnum *= -1;
}
return pnum;
}

struct node* del(struct node *head, int iPrnum) 
{
int cnt, iPos;
struct node *prev = NULL; 
struct node *delnode = NULL;
struct node *curr = NULL;

if(head == NULL)
	printf("\n\nThe list is empty");
	
else
{
	curr = head;
	prev = curr;
	cnt = 1;
	while(curr->next != NULL && iPrnum != curr->pn)
	{
		prev = curr;
		curr = curr->next;
		cnt++;
	}

	if(cnt == 1 && iPrnum == curr->pn) //for deleting the first node
	{
		delnode = curr;
		head = curr->next;
		free(delnode);
	}
	else if(iPrnum == curr->pn) //for deleting any other node in between
	{
		delnode = curr;
		prev->next = curr->next;
		free(delnode);
	}
	
	return head;
}
}
#endif