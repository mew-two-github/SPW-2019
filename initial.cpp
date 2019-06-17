#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<string>
#include<string.h>
#include<cstring>
#include<algorithm>
#include<fstream>
using namespace std;

class Item{
  string name,brand;
  string type;
  vector<string> ids;
  float rating;
  long num_of_rates;
  long price;
  public:
  Item();
  void rate(float a);
  void initialise();
};
  Item::Item()
  {   
    rating=0;
    num_of_rates=0;
    price=0;
  }
void Item::rate(float a)
{
  rating=(a+rating*num_of_rates)/(num_of_rates);
  num_of_rates++;
 cout<<"\nThanks for rating\n";
}
void Item::initialise()
{
  cout<<"\nType:\n";
  getline(cin,type);  
  cout<<"\nName:";
  getline(cin,name);
  ids.push_back(name);
  cout<<"\nBrand :";
  getline(cin,brand);
  ids.push_back(brand);
  string id;
  cout<<"\n Enter IDs (enter stop to stop)\n";
  getline(cin,id); 
  ids.push_back(type);
  while(id.compare("stop")!=0)
   {    
     ids.push_back(id);
     getline(cin,id);
   }
  // cout<<"\nDONE";
}

int main()
{
  long long n;  
  cout<<"\nNumber of Objects\n";
  cin>>n; 
  vector<Item> i(n);
  for(long long j=0;j<n;j++)
    {
      i[j].initialise();
    }
  ofstream a("mem.dat",ios::binary); 
  for(long long j=0;j<n;j++)
    {
      a.write((char*)&i[j],sizeof(i[j]));
    }
 return 0;
}
