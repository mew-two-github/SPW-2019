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
  char* returntype()
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
  cout<<"\tName: ";
  cout<<name;
  cout<<"\nBrand: ";
  cout<<brand;
  cout<<"\nPrice: "<<price;
  cout<<"\tRating: "<<rating<<"/5.0";
}

//INITIALISER

void Item::initialise()
{
  cout<<"\nType:\n";
  cin>>type;  
  cout<<"\nName:";
  cin>>name;
  cout<<"\nBrand :";
  cin>>brand;
  cout<<"\nPrice : ";
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
  cout<<"\nDONE\n";
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
  rating=(a+rating*num_of_rates)/(++num_of_rates);
  cout<<"\nThanks for rating\n";
}

vector<Item> l;

//PRINTING SUGGESTIONS IN HEAP ORDER
struct compprice{
  bool operator()(Item a,Item b)
  {
    if(a.rprice()>b.rprice())
      return 1;
    else 
     return 0;
  }
};
struct comprating{
  bool operator()(Item a,Item b)
  {
    if(a.rrating()<b.rrating())
      return 1;
    else 
     return 0;
  }
};
struct compop{
  bool operator()(Item a,Item b)
  {
    if(float(a.rprice()/a.rrating())>float(b.rprice()/b.rrating()))
      return 1;
    else 
     return 0;
  }
};

//displays 2 items at a time
void sug(vector<Item> v,int opt=3)
{
  
  system("clear");
  if(opt==1)
  {
    priority_queue<Item,vector<Item>,compprice> Q;
      for(int i=0;i<v.size();i++) 
    Q.push(v[i]);
    int lol=v.size();
    int i=0,k=0;
    while(opt)
    {
      for( i=0;i<2&&k<lol;i++)
      {     
         Item j=Q.top();
         j.display();
         cout<<"\n\n";
         Q.pop();
         ++k;
     }
      if (k>=lol)
      {
        cout<<"\nAll items displayed\n";
        opt=0;
      }
      else
      {
        cout<<"\nEnter 0 to quit and 1 to continue\n" ;
        cin>>opt;
        system("clear");
      }
    }
      
  }
    else if(opt==2)
  {
    priority_queue<Item,vector<Item>,comprating> Q;
  
  for(int i=0;i<v.size();i++) 
  Q.push(v[i]);
  int lol=v.size();
  int i=0,k=0;
  while(opt)
    {
      for( i=0;i<2&&k<lol;i++)
      {     
	       Item j=Q.top();
         j.display();
         Q.pop();
         ++k;
	   }
      if (k>=lol)
      {
        cout<<"\nAll items displayed\n";
        opt=0;
      }
      else
      {
        cout<<"\nEnter 0 to quit and 1 to continue\n" ;
        cin>>opt;
        system("clear");
      }
    }
   }
   else if(opt==3) 
   {
     priority_queue<Item,vector<Item>,compop> Q;
  
  for(int i=0;i<v.size();i++) 
  Q.push(v[i]);
  int lol=v.size();
  int i=0,k=0;
  while(opt)
    {
      for( i=0;i<2&&k<lol;i++)
      {     
         Item j=Q.top();
         j.display();
         Q.pop();
         ++k;
     }
      if (k>=lol)
      {
        cout<<"\nAll items displayed\n";
        opt=0;
      }
      else
      {
        cout<<"\nEnter 0 to quit and 1 to continue\n" ;
        cin>>opt;
        system("clear");
      }
    } 
   } 
}



//RETURNS POSSIBLE GOODS

vector<Item> poss(char a[])
{
  long long i=0,n=l.size(),j=0;
  vector<Item> good;
  /*while(s!="\r")
    {
      cin>>s;
      if(s!="\r")
	{
          givid.push_back(s);
	}
	}*/
 if(strcasecmp(a,"all")==0)
    good=l;
  else
  {
   for(i=0;i<n;i++)
    {
         char *ids=l[i].returntype();
  
           if(strcasecmp(ids,a)==0)
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
  char a[]="lol";   
  while(strcasecmp(a,("exit"))!=0)
 {
  cout<<"\n What type of item would you like to buy?\n(type exit to exit)\t(type all for all items)\n";
  cin>>a;
  if(strcasecmp(a,"exit")==0)
    break;
  vector<Item> positems=poss(a);
  if(positems.empty())
  {
    cout<<"\nNo item found\n";
    continue;
  }
  opt=1;
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
 return;
}







//MAIN

int main()
{ 
  ifstream f("mem.dat",ios::binary|ios::in);
  //f.open("mem.dat",ios::binary|ios::in);
  Item r;
  while(f.read((char*)&r,sizeof(r)))
    {
        l.push_back(r);
    }  
  menu();
  return 0;
}
