#include <conio.h>
#include <iostream>
#include <time.h>

using namespace std;

struct str {                /// list
	int number;
	str *next;
};

void main() {
	str *first = 0, *p;
	int i;
  srand(time(0));
	cout<<"Size of list: ";      /// size of list
	cin>>i;
	cout<<endl;
	for(int n = 0; n < i; n++) {       /// create list and fill it with random numbers
		p = new str;
		p->number = rand() % 100 + 1;
		p->next = first;
		first = p;
  }
	p = first;
	while(p) {                 /// print list
    cout<<p->number<<"  ";
		p = p->next;
	}
	while(first) {                /// delete list
		p = first;
		first = first->next;
		delete p;
	}
	cout<<endl;
  _getch();
}