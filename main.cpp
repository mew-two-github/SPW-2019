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
  void display();
  vector<string> returnid()
  {
    return ids;
  }
};


//DISPLAY THE ITEM
void Item::display()
{
  cout<<"\nType: ";
  cout<<type;  
  cout<<"\nName: ";
  cout<<name;
  cout<<"\nBrand: ";
  cout<<brand;
  cout<<"\nRating: "<<rating;
}

//INITIALISER

void Item::initialise()
{
  cout<<"\nType:\n";
  cin>>type;  
  cout<<"\nName:";
  cin>>name;
  ids.push_back(name);
  cout<<"\nBrand :";
  cin>>brand;
  ids.push_back(brand);
  char id[25];
  cout<<"\n Enter IDs (enter stop to stop)\n";
  cin>>id; 
  ids.push_back(type);
  while(strcmp(id,"stop")!=0)
   {    
     ids.push_back(id);
     cin>>id;
   }
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
  rating=(a+rating*num_of_rates)/(num_of_rates);
  num_of_rates++;
  cout<<"\nThanks for rating";
}

vector<Item> l;

//PRINTING SUGGESTIONS IN HEAP ORDER

void sug(vector<Item> positems,int opt=3)
{
 
}



//RETURNS POSSIBLE GOODS

vector<Item> poss(string a)
{
  long long i=0,n=l.size(),j=0;
  vector<Item> good;
  vector<string> givid;
  string s;
  cout<<"\nWhat would you like to search for(Press Enter to search)";
  cin>>s;  
while(s!="\r")
    {
      cin>>s;
      if(s!="\r")
	{
          givid.push_back(s);
	}
    }
  for(i=0;i<n;i++)
    {
        vector<string> ids=l[i].returnid();
        for(long long k=0;k<givid.size();k++)
        for(j=0;ids[j].compare(NULL)!=0;j++)
	{
	  
           if(ids[j].compare(givid[k])==0)
	    {
	      good.push_back(l[i]);
	    }
	}
    }
  return good;
}



//MAIN MENU
void menu()
{
  int opt;
  string a;   
  cout<<"\n What type of item would you like to buy?\n";
  getline (cin,a);
  vector<Item> positems=poss(a);
  while(opt!=4)
 {
  cout<<"\nEnter your preference\n";
  puts("Option 1:price order");
  puts("Option 2:rating");
  puts("Option 3:Suggested items");
  puts("Option 4:Exit");  
  cin>>opt;
  switch(opt)
    {
     case 1:
     {
       sug(positems,1);
      break;
     }
     case 2:
     {
       sug(positems,2); 
      break;
     }
     case 3:
     {
       sug(positems);
      break;
     }
    case 4:
      {
	break;
      }
    default:
      {
	puts("Wrong option");
      }
    }
  }
}







//MAIN

int main()
{
  fstream f("mem.dat",ios::binary|ios::in);
  //f.open("mem.dat",ios::binary|ios::in);
  Item r;
  /* while(!f.eof())
    {
        f.read((char*)&r,sizeof(r));
        l.push_back(r);
    } 
  int i;
  cin>>i;*/
  long long n=l.size();  
 menu();
  return 0;
}
