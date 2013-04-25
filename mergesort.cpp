#include <conio.h>
#include <iostream>
#include <time.h>
 
using namespace std;

void merg(int n, int *mas, int l, int r) {    /// sort function
  if (r == l)
    return;
  if (r - l == 1) { 
    if (mas[r] < mas[l])
      swap(mas[r], mas[l]);
    return;
  }
  int m = (r + l) / 2;
  merg(n, mas, l, m);
  merg(n, mas, m + 1, r);
  int *buf = new int[n], cur = 0, xl = l, xr = m + 1;
  while (r - l + 1 != cur) {
    if (xl > m)
      buf[cur++] = mas[xr++];
    else if (xr > r)
      buf[cur++] = mas[xl++];
    else if (mas[xl] > mas[xr])
      buf[cur++] = mas[xr++];
    else buf[cur++] = mas[xl++];
  }
  for (int i = 0; i < cur; i++)
    mas[i + l] = buf[i];
}
 
int main() {  
  int n;
  srand(time(0));
  cout<<"Enter N: ";     /// size of an array
  cin>>n;
  int *mas = new int[n];
  for (int i = 0; i < n; i++)    /// fill array with random numbers
    mas[i] = rand() % 100 + 1;
  cout<<"Array before sort: ";
  for (int i = 0; i < n; i++)    /// print array before sort
    cout << mas[i] << "  ";
  merg(n, mas, 0, n - 1);    /// sorting
  cout<<"\nArray after sort: ";
  for (int i = 0; i < n; i++)    /// print array after sort
    cout << mas[i] << "  ";
  _getch();
  return 0;
}