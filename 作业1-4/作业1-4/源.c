#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Int
{
	int a;
	struct Int* next;
};
typedef struct Int Int;

void display(Int* head) {
	int i;
	Int* p = head->next, * pre = head;
	if (p->next != NULL) printf("%d", p->a);
	while (p->next != NULL) {
		p = p->next;
		if (p->a != 0) {
			printf("->%d", p->a);
		}

	}

}
void Free(Int* head) {
	Int* p = head, * prev = head;
	while (p) {
		p = p->next;
		free(prev);
		prev = p;
	}
	free(prev);
}


Int* createChain() {
	Int* pre = NULL, * tmp = NULL, * head = NULL, * end = NULL;
	int i;
	head = (Int*)malloc(sizeof(Int));
	end = (Int*)malloc(sizeof(Int));
	head->a = 0;
	head->next = end;

	end->a = 0;
	end->next = NULL;
	return head;
}


//Int* delete(Int* head, int a) {
//	Int* pre=head, * tmp=head->next;
//	while (tmp->next != NULL) {
//		if (tmp->a == a) {
//			pre->next = tmp->next;
//			free(tmp);
//			tmp = pre->next;
//			break;
//		}
//	
//	}
//
//
//	return tmp;
//}
Int* insertChain(Int* head, int a) {
	Int* now = NULL, * pre = NULL, * tmp = NULL;
	now = head->next;
	pre = head;
	while (now->next != NULL)
	{
		if (now->a >= a) {
			tmp = (Int*)malloc(sizeof(Int));
			pre->next = tmp;
			tmp->a = a;
			tmp->next = now;
			break;
		}
		else {
			pre = now;
			now = now->next;
		}

	}
	if (now->next == NULL) {
		tmp = (Int*)malloc(sizeof(Int));
		pre->next = tmp;
		tmp->a = a;
		tmp->next = now;
	}


	return head;
}

Int* spilt(Int* head,Int* head2) {
	Int *tmp=head->next,*pre=head;
	while (tmp->next != NULL) {
		if (tmp->a % 2 == 0)
		{
			head2 = insertChain(head2, tmp->a);
			pre->next = tmp->next;
			free(tmp);
			tmp = pre->next;
		}
		else {
			pre = tmp;
			tmp = tmp->next;
		}
	}


	return head2;
}

int main()
{
		int a[1000];
		char c;
		int i = 0;
		int n = 0;
		int j = 0;
		Int* head1 = NULL;
		Int* head2 = NULL;
		while ((c = getchar()) != '\n')
		{
			if (c != ' ')
			{
				ungetc(c, stdin);//��c�ͻ�������
				scanf_s("%d", &a[n++]);
			}
		}
	head1 = createChain();
	head2 = createChain();
	for (i = 0; i < n; i++) {
		head1 = insertChain(head1, a[i]);
	}
	display(head1);
	printf("\n");
	head2 = spilt(head1, head2);
	display(head1);
	printf("\n");
	display(head2);

	Free(head1);
	Free(head2);

	return 0;
}
//100 2 3  50 2 1 5 8 5 5 6 31 5  14 8
