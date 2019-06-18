#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<string>
#include<string.h>
#include<cstring>
#include<fstream>
#include<algorithm>
#include<queue>
using namespace std;

class Item{
  char name[100],brand[150];
  char type[100];
  //vector<string> ids;
  float rating;
  long num_of_rates,price;
  public:
  Item();
  void rate(float a);
  void initialise();
  void display();
  long rprice()
  {
    return price;
  }
  float rrating()
  {
    return rating;
  }
  string returntype()
  {
    return type;
  }
 /* vector<string> returnid()
  {
    return ids;
  }*/
};



//DISPLAY THE ITEM
void Item::display()
{
  //system("clear");
  cout<<"\nType: ";
  cout<<type;  
  cout<<"\nName: ";
  cout<<name;
  cout<<"\nBrand: ";
  cout<<brand;
  cout<<"\nPrice: "<<price;
  cout<<"\nRating: "<<rating;
}

//INITIALISER

void Item::initialise()
{
  cout<<"\nType:\n";
  cin>>type;  
  cout<<"\nName:\n";
  cin>>name;
  cout<<"\nBrand:\n";
  cin>>brand;
  cout<<"\nPrice:\n";
  cin>>price;
  //ids.push_back(name);
  //ids.push_back(brand);
  /*char id[25];
  cout<<"\n Enter IDs (enter stop to stop)\n";
  cin>>id; 
  ids.push_back(type);
  while(strcmp(id,"stop")!=0)
   {    
     ids.push_back(id);
     cin>>id;
   }*/
  float r;
  cout<<"\nEnter rating : ";  
  cin>>r;  
  rate(r);
  // cout<<"\nDONE";
}


//CONSTRUCTOR

  Item::Item()
  {
    rating=5;
    num_of_rates=0;
    price=0;
  }

//RATING THE ITEM
void Item::rate(float a)
{
  //Checking if rating exceeds 5
  if(a>5)
  {
    cout<<"\nEnter value less than 5\n";
    cin>>a;
    rate(a);
    return;
  }
  rating=(a+rating*num_of_rates)/(++num_of_rates);
  cout<<"\nThanks for rating\n";
}

vector<Item> l;



//MAIN

int main()
{
  long long n;  
  cout<<"\nNumber of Objects\n";
  cin>>n; 
  Item r;
  for(long long j=0;j<n;j++)
    {
      system("clear");
      cout<<"Object number:"<<j+1<<'\n';
      r.initialise();
      l.push_back(r);
    }
  ofstream a("mem.dat",ios::binary); 
  for(long long j=0;j<n;j++)
    {
      a.write((char*)&l[j],sizeof(l[j]));
    }
  n=l.size();  
  //menu();
  return 0;
}