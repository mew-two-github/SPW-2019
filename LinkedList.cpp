#include<iostream>
using namespace std;

typedef struct LLNode {
	int val;
	struct LLNode* next;
} node;

class LinkedList {
	node* first;

public:
	LinkedList(){
	  first = NULL;
	}

	void append(int i){
		node* lol=first;
                node* lol2=new node;
                lol2->val=i;
		lol2->next=NULL;
        	if(lol==NULL)   
	        first=lol2;
                else                  
	    {
                 while(lol->next!=NULL)
                {
                  lol=lol->next;
                } 
              
		lol->next=lol2;   
	    } 
	            
	}

	int get(int n){
	  node* lol=first;
	  while((n--)&&(lol->next!=NULL))
             {
                  lol=lol->next;
              }
           int num= lol->val;
	   return num;
           
          
	}

	void insert(int n, int i){
            node* lol=first;
            if(n)
            while(--n)
             {
                  lol=lol->next;
              }
	   node* lol2= new node;
           lol2->val=i;
           lol2->next=lol->next;
           lol->next=lol2;
            
            
		
	}

	int del(int n){
		  node* lol=first;
		  if(n==0)
		    {first=first->next;
		      delete lol;
		      return 0;
		    }
              while(--n)
             {
                  lol=lol->next;
              }
		  node* lol2=lol->next;
                  lol->next=lol2->next;
		  delete lol2;
		  return 0; 

	}

	int search(int i){
	 node* lol=first;
	 int num=-1;
	 while((lol->next!=NULL))
	   {
	     ++num; 
            if(lol->val==i)
	       return num;	     
             lol=lol->next;

	   }	
	 return -1;
          
	}

};

int main(){
  LinkedList l;
  l.append(25);
  l.append(30);
  l.append(50);
    for(int i=0;i<3;i++)  
      cout<<l.get(i)<<'\n';
   int junk= l.del(1) ;
    cout<<'\n';
 for(int i=0;i<2;i++)  
      cout<<l.get(i)<<'\n';
 l.insert(1,30);
 cout<<'\n';
for(int i=0;i<3;i++)  
      cout<<l.get(i)<<'\n';
 cout<<'\n'<<l.search(30)<<' '<<l.search(100)<<'\n';
 return 0;
} 
