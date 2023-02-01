#include<iostream>

struct NODE {
	int x;
	NODE* next;

	
};
NODE* list;
NODE* last;
void addNode(int v) {

	if (list == NULL)
	{
		list = new NODE();
		list->x = v;
		last = list;
	}
	else
	{
		last->next = new NODE();
		last->next->x = v;
		last = last->next;
	}
}
int main() {
	time_t start = clock();
	addNode(3);
	addNode(5);

	addNode(7);
	addNode(9);

	printf("%d ms", clock() - start);
	return 0;
}