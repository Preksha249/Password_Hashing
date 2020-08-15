#include<iostream>
#include<string.h>
#include<iomanip>
#include"hash.h"
using namespace std;

class user
{ 
protected:
	  char email_id[30],password[20],name[20],stipend[10],yearofjoining[10],working[30];
public:
	void sdata(char id[30],char pass[20],char n[20],char st[10],char yr[10],char wrk[30])
	{
		strcpy(email_id,id);
		strcpy(password,pass);
		strcpy(name,n);
                strcpy(stipend,st);
                strcpy(yearofjoining,yr);
                strcpy(working,wrk);
	
        }	

  void sdata()
	{     
              cout<<"\n\t\t|______DETAILS OF YOUR ACCOUNT______\n";
              cout<<"\t\t|_________________________________\n";
		cout<<"\t\t|   NAME: "<<name<<endl;
           	cout<<"\t\t|   EMAIL ID: "<<email_id<<endl;
		cout<<"\t\t|   PASSWORD: "<<password<<endl;
		//hashing(password);
                cout<<"\t\t|   STIPEND: "<<stipend<<endl;
                cout<<"\t\t|   YEAR OF JOINING: "<<yearofjoining<<endl;
                cout<<"\t\t|   WORKING ON: "<<working<<endl;
	}
	
};

       

class admin: public user
{   
 public:
      friend void display(admin obj); 
};

void display(admin obj)
 {      
      //hashing(obj.password);
 	cout<<"\t"<<left<<setw(28)<<obj.email_id<<left<<setw(28)<<obj.password<<left<<setw(28)<<obj.working<<endl;
 }

int main()
{
	char na[20],eid[30],ps[20],st[10],yr[10],wrk[30];
	int count=0,key,i,j=0,ch,flag=0;
	char password_admin[]={"admin123"},password_check[20];
	admin ob1[30];
        system("clear");
        cout<<"\n--------------------------------------------------------------------------\n";
	cout<<"\n\t\t\t~~~~~~~~____WELCOME____~~~~~~~";
        for(i=0;i<=30;i++)
	{
        cout<<"\n\n\txxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n";
	cout<<"\n\n\t---------------------------------------------------------\n\n";
	cout<<"\t1.Sign up  |  2.Find account  |  3.Admin LogIn  |  4.Quit\n\n";
	cout<<"\t-----------------------SELECT OPTION---------------------\n\n";
	cin>>ch;
	
       switch(ch)
	{
		case 1:count++;
			   cout<<"\tEnter your name: ";
			   cin>>na;
                           cout<<"\n\tEnter valid email id: ";
			   cin>>eid;
			   cout<<"\n\tEnter password of MAX 20 characters: ";
			   cin>>ps;
      			  hashing(ps);
                            cout<<"\n\tEnter your stipend: ";
                           cin>>st;
                            cout<<"\n\tEnter your year of joining: ";
                            cin>>yr;
                            cout<<"\n\tEnter the project you're working on: ";
                            cin>>wrk;
			   cout<<"\n__###__Your unique number to find your account is: 1770100"<<count<<endl;
			   ob1[j].sdata(eid,ps,na,st,yr,wrk);
			   j++;
			   break;
		
                case 2:cout<<"enter the unique number to find your: 1770100";
			  /* cin>>key;
			   ob1[key-1].sdata();
			   break;*/
                           cin>>key;
                           for(j=0;j<count;j++)
                              { if(key-1==j)
                                  {ob1[key-1].sdata();
                                    break;
                                   }
                               // else
                                 //  {cout<<"\n\t\t!!!!NO EMPLOYEE WITH SUCH ID FOUND!!!!\n";
                                   //   cout<<"\t\t    ~~~~~SO PLEASE TRY AGAIN~~~~~";
                                    //}
                              
                  
                    else
                      {cout<<"\n\t\t!!!!NO EMPLOYEE WITH SUCH ID FOUND!!!!\n";
                        cout<<"\t\t    ~~~~~SO PLEASE TRY AGAIN~~~~~";
                      }
			      }	       
		              break;
                 case 3:cout<<"ENTER ADMIN PASSWORD: ";
			   cin>>password_check;
			   if((strcmp(password_admin,password_check)==0))
			   {
			   		cout<<"\n\n\t^^^CORRECT PASSWORD^^^\n\n";
			   }
			   else
                          {
               		      cout<<"\n\n\t---TRY AGAIN---\n\n";
               		      break;
                          }
                           cout<<"\t----------------------------------------------------------------\n";
                           cout<<"\t"<<left<<setw(28)<<"ID NUMBER"<<left<<setw(28)<<"EMAIL ID"<<left<<setw(28)<<"PASSWORD";
                           cout<<"\n\t---------------------------------------------------------------\n\n";
			   for(i=0;i<count;i++)
                              { cout<<"\t1770100"<<i+1<<"\t";
		       		display(ob1[i]);
                              } 
		       break;
		
                 case 4:cout<<"\t\t____*******QUITTING*******____\n\n";
		       exit(0);	   
		
                default:cout<<"\t\t\t_______ENTER VALID CHOICE______\n";
				
	}
	}
return 0;
}
