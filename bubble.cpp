#include <iostream>
using namespace std;
void bubble_sort (int arr[], int n)
 {
     int c=0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n - i - 1; ++j)
      if (arr[j] > arr[j + 1])
     {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        c++;
      }
      cout<<c;
  }
int main()
{
  int input_ar[] = {1,3,2};
  cout << "Unsorted Array :  ";
  for(int i=0;i<3;i++)
  {
       cout <<input_ar[i]<<"  ";
  }
  cout << endl;
  ///int n = sizeof (input_ar) / sizeof (input_ar[0]);
  int n =3;
  bubble_sort (input_ar, n);
  cout << "Sorted Array : " << endl;
  for (int i = 0; i < n; ++i)
    cout << input_ar[i] << " ";
  return 0;
}
