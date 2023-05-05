#include <iostream>
#include <vector>
#include <algorithm>
#include<math.h>
using namespace std;


/*int main()
{
 vector <int> count{10,12,7,6,5};
 int ind_max{0};
 for(size_t i{0}; i < count.size(); i++)
 {
  cout << i << "," << count.at(i) << "," << ind_max << endl;
 }
 for(size_t i{0}; i < count.size(); i++)
 {
  if(count.at(i) > count.at(ind_max))
  ind_max = i;
 }
 cout << ind_max;
 return 0;
}
*/

/*int main()
{
 vector<int> v{1,2,3,4,5,6,7};
 vector<int>::iterator it;
 it = find(v.begin(), v.end(),6);
 if(it != v.end())
 cout << "Element found in vector: " << it-v.begin() << '\n';
 else
 cout << "My fault\n"; 
 return 0;
}
*/

/*bool f(int n)
{
 return n > 10;
}
*/

/*int main()
{
 int n{12};
 cout << "Enter n: ";
 cin >> n;
 auto lamda = [&](int element)
 {
  return element > n; 
 };
 vector<int> v{1,6,7,4,10,15};
 vector<int>::iterator it = find_if(v.begin(), v.end(),lamda);
 cout << *it << endl;
 
 return 0;
}
*/

/*
int main()
{
 vector<int> v {1,6,7,4,10,15,20,4,4,4,16,17};
 auto lamda = [&](int element)
 {
  return element < 2;
 };
 int count =count_if(v.begin(),v.end(),lamda);
 cout << count << endl;
}
*/

/*
int main()
{
 int n{2};
 cout << "Geben n ein: ";
 cin >> n;
 vector<double> v {0,1,3,8,9,6,15};
 vector<int> v2;
 auto lamda = [&](int element)
 {
  return element % n == 0;
 };
 copy_if(v.begin(),v.end(),back_inserter(v2),lamda);
 
 for(int element: v2)
 cout << element << ' ';
 cout << '\n';
}
*/

/*
bool greater_than(int a, int b)
{
 return abs(a) < abs(b);
}

int main()
{
 vector<int> v{-1,2,-5,-6,-7,-8};
 vector<int>::iterator iterator1;
 vector<int> v2{1,10,19,20,30};
 iterator1 = max_element(v.begin(),v.end(),greater_than);
 cout << *iterator1 << endl;
}
*/



