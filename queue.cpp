#include <conio.h>
#include <iostream>
#include <time.h>

using namespace std;

struct queue {                 /// queue
	int number;
	queue *next;
} *head, *last;

void add(int nb, queue **st) {        /// add element
	queue *temp = new queue;
	temp->number = nb;
	temp->next = NULL;
	if(head == NULL) {
		head = temp;
		last = head;
  }
  else {
    last->next = temp;
    last = temp;
  }
}

void show(queue *st) {         /// print elements
  queue *temp;
	temp = head;
	while (temp != NULL) {
    cout<<temp->number<<"  ";
    temp = temp->next;
  }
}

void pop(queue *st) {           /// delete element
	while(head != NULL) {
    queue *temp = head->next;
		delete head;
    head = temp;
  }
}

void main() {
	queue *q = new queue;
	int i, j;
  srand(time(0));
	cout<<"Size of queue: ";          /// size of queue
	cin>>i;
	cout<<endl<<"Push: ";
	for(int n = 0; n < i; n++) {      /// fill queue with random numbers
		j = rand() % 100 + 1;
		cout<<j<<"  ";               /// and print it in order of add
		add(j, &q);
	}
	cout<<endl<<"\nPop: ";
	show(q);                      /// print queue
	pop(q);                        /// delete queue
	cout<<endl;
  _getch();
}