#include <conio.h>
#include <iostream>
#include <time.h>

using namespace std;

struct stack {      /// stack
  int number;
  stack *next, *head;
};

void push(int nember, stack **st) {      /// add new element
  stack *temp = new stack;
  temp->number = nember;
  temp->next = (*st)->head;
  (*st)->head = temp;
}

void show(stack *st) {      /// function for printing stack
  stack *temp = new stack;
  temp = st->head;
  while (temp != NULL) {
    cout<<temp->number<<"  ";
    temp = temp->next;
  }
}

void pop(stack *st) {       /// delete element
  while (st->head != NULL) {   
    stack *temp=st->head->next;
    delete st->head;
    st->head = temp;
  }
}

void main() {
  stack *st = new stack;
  st->head = NULL;
  stack *first = 0, *P;
	int i, j;
  srand(time(0));
	cout<<"Size of stack: ";        /// size of stack
  cin>>i;
  cout<<endl<<"Before: ";        /// fill stack with random elements               
	for(int n = 0; n < i; n++) {
		j = rand() % 100 + 1;          /// print elements in order of add
		cout<<j<<"  ";
		push(j, &st);
	}
	cout<<endl<<"\nStack: ";       /// print stack
	show(st);
	pop(st);
	cout<<endl;
  _getch();
}