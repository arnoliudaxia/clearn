// add into the linked-list
Node *p = (Node*)malloc(sizeof(Node));
p->value = number;
p->next = NULL;
// find the last
			Node *last = head;
			if (last) {
				while (last->next) {
					last = last->next;
				}
				// link
				last->next = p;
			}
			else {
				head = p;
			}

// print the link-list
	Node *p1 = NULL;
	int i = 0;
	for (p1 = head ; p1; p1 = p1->next){
		printf("link-%p-%p: value[%d] = %d...\n", p1, p1->next,i++, p1->value);
	}
Node* add(Node* head, int number)
{
	// add into the linked-list
	Node *p = (Node*)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;

	// find the last
	Node *last = head;
	if (last) {
		while (last->next) {
			last = last->next;
		}
		// link
		last->next = p;
	}
	else {
		head = p;
	}

	return head;
}

void add(Node** phead, int number) {

	Node *p = (Node*)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;

	// find the last
	Node *last = *phead;
	if (last) {
		while (last->next) { 
			last = last->next;
		}
		// link
		last->next = p;
	}
	else {
		*phead = p;
	}
}