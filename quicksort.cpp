#include <conio.h>
#include <iostream>
#include <time.h>

using namespace std;

void sort(int *mas, int low, int high) {  /// sort function
  int i = low, j = high, mid = mas[(low + high)/2];
  do {
    while(mas[i] < mid)
      i++;
    while(mas[j] > mid)
      j--;
    if(i <= j)  {
      int temp = mas[i];
      mas[i] = mas[j];
      mas[j] = temp;
      i++;
      j--;
    }
  } while(i < j);
  if(low < j)
    sort(mas, low, j);
  if(i < high)
    sort(mas, i, high);
}

int main() {
  int *mas, n;
  srand(time(0));
  cout<<"Enter N: ";
	cin>>n;
  mas = new int[n];
  for(int i = 0; i < n; i++) {   /// fill array with random numbers
    mas[i] = rand() % 100 + 1;
	}
  cout<<"Array before sort: "<<endl;   /// print array before sort
  for(int i = 0; i < n; i++) {
    cout<<mas[i]<< "  ";
  }
  int x = n - 1;   /// sorting
	sort(mas, 0, x);
	cout<<"\nArray after sort: "<<endl;
  for(int i = 0; i < n; i++) {   /// print array after sort
    cout<<mas[i]<< "  ";
	}
  _getch();
  return 0;
}