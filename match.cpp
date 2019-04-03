#include<iostream>
using namespace std;

class Cricket_Record{
       string player_name;
       int player_num;
       
       public:int oneday_status;
              int T20_status;
              int test_status;
              void getdata();
              void display();

};

class Oneday_Record : virtual public Cricket_Record {
        int o_match_num;
        int o_no_ball[50];
        int o_no_runs[50];
        float o_strick;
        float avg_runs;
        
   
     public:
       void get_o_data();
       void o_dispaly();
       Oneday_Record()
              {
                     o_match_num=1;                     
              }
};

class Test:virtual public Cricket_Record{
       int T_match;
       int T_run[10];
       int T_ball[10];
       int T_avg;

public:
       void get_t_data();
       void T_display();
       Test()
       {
              T_match = 1;
       }

};

class T20 :virtual public Cricket_Record{
       int T20_match;
       int T20_six[10];
       int T20_four[10];
       int T20_avg;

public:
       void get_t20_data();
       void T20_display();
       T20()
       {
              T20_match = 1;
       }

};

 class record :  public T20, public  Test, public Oneday_Record
{

}obj;

void T20::get_t20_data()
{
       if(T20_status==1)
       {
       cout<<"\n\t\tEnter the number of sixes : ";
       cin>>T20_six[T20_match];
       cout<<"\n\t\tEnter the number of fours : ";
       cin>>T20_four[T20_match];
       T20_avg=T20_avg+(T20_four[T20_match]*4+T20_six[T20_match]*6);
       T20_match++;       
       }
       else 
       {
              cout<<"\n\t**Player is not playing T20 Match*** \n";
       }
}

void T20 ::T20_display()
{
        cout<<"\n\tT20  match: ";
       if(T20_status==1&&T20_match!=1)
       {
       cout<<"\nMatch_NO    sixes\t\tfours"<<endl;
       cout<<"------------------------------------------"<<endl;
       
       int i;

       for( i = 1; i < T20_match; i++)
       {
       
       cout<<i<<"\t      "<<T20_six[i]<<"\t"<<T20_four[i]<<endl;
            
       }
       
       cout<<"\nThe Total Runs: "<<T20_avg<<endl;
       }
       else 
       {
              cout<<"\n\t***Either Player is not playing T20 or not filling any data *** \n";
       }
}

void Test:: get_t_data()
{
       if(test_status==1)
       {
       
       cout<<"\n\t\tEnter the number of balls : ";
       cin>>T_ball[T_match];
       cout<<"\n\t\tEnter the number of runs : ";
       cin>>T_run[T_match];
       T_avg=T_avg+T_run[T_match];
       T_match++;       
       }
       else 
       {
              cout<<"\n\t** Player is not playing Test match *** \n";
       }

}

void Test ::T_display()
{      
       cout<<"\n\ttest match: ";
       if(test_status==1&&T_match!=1)
       {
       cout<<"\nMatch_NO    Balls\truns"<<endl;
       cout<<"------------------------------------------"<<endl;
       
       int i;

       for( i = 1; i < T_match; i++)
       {
       
       cout<<i<<"\t      "<<T_ball[i]<<"\t"<<T_run[i]<<endl;
            
       }
       
       cout<<"\nThe Total Runs: "<<T_avg<<endl;
       }
       else 
       {
              cout<<"\n\t***Either Player is not playing Test or not filling any data *** \n";
       }
}
 
void Cricket_Record ::getdata()
{
       cout<<"\tEnter Player number :";
       cin>>player_num;
       cout<<"\tEnter the player name :";
       cin>>player_name;
       cout<<"\tIs player plays one day circket ?  \n(press 1=Yes or 2=No)  ";
       cin>>oneday_status;
       cout<<"\tIs player plays T20 circket ?  \n(press 1=Yes or 2=No)  ";
       cin>>T20_status;
       cout<<"\tIs player plays Test circket ? \n(press 1=Yes or 2=No)  ";
       cin>>test_status;
}

void Cricket_Record :: display()
{       
       cout<<"\n\tPlayer Name is :"<< player_name <<endl;
       cout<<"\tPlayer Number :"<< player_num <<endl;       
       cout<<"\tStatus of the player :";
       cout<<"\n\tOne_Day\t\tT20\t   Test match \n";
       if(oneday_status==1)
              cout<<"\tyes";
       else
       {
              cout<<"\tNO";

       }
       if(T20_status==1)
              cout<<"\t\tyes";
       else
       {
              cout<<"\t\tNO";
              
       }if(test_status==1)
              cout<<"\t\tyes";
       else
       {
              cout<<"\t\tNO";
              
       }
}

int main()
{      
       int c,ch;
       obj.getdata();
       obj.display();
       

while(ch!=3)
{
       cout<<"\n\n\t1.Fill data\n\t2.Display\n\t3.Exit"<<endl;
       cout<<"Enter The choise : ";
       cin>>ch;
       if(ch==1)
       {
       while(c!=4)
       {      
              cout<<"\n\t****MENU****";
              cout<<"\n\t1.One day match\n\t2.T20 match\n\t3.Test Match\n\t4.Exit";

              cout<<"\n\tEnter the choice: ";
              cin>>c;

              switch (c)
              {
                     case 1:obj.get_o_data();
                            break;
                     case 2:obj.get_t20_data();
                            break;
                     case 3:obj.get_t_data();
                            break;
                     case 4:break;

              
                     default:cout<<"\n\tEnter the correct choise";

                            break;
              }
       }
       }

       else if(ch==3)
       {
              break;
       }
       
       else
       {
              obj.o_dispaly();
              obj.T20_display();
              obj.T_display();
              
       }
       
}

       return 0;

}

void Oneday_Record::get_o_data()
{
       if(oneday_status==1)
       {
       
       cout<<"\n\t\tEnter the number of balls : ";
       cin>>o_no_ball[o_match_num];
       cout<<"\n\t\tEnter the number of runs : ";
       cin>>o_no_runs[o_match_num];
       avg_runs=avg_runs+o_no_runs[o_match_num];
       o_match_num++;
       }
       else 
       {
              cout<<"\n\t*** Player is not playing One Day match ***\n ";
       }

       
}


void Oneday_Record::o_dispaly()
{
       cout<<"\n\tOne-day match status: ";
       if(oneday_status==1&&o_match_num!=1)
       {
       cout<<"\nMatch_NO    Balls\truns"<<endl;
       cout<<"------------------------------------------"<<endl;
       
       int i;

       for( i = 1; i < o_match_num; i++)
       {
       
       cout<<i<<"\t      "<<o_no_ball[i]<<"\t"<<o_no_runs[i]<<endl;
            
       }
       
       
       cout<<"\n\tThe Total runs: "<<avg_runs<<endl;
       }
       else 
       {
              cout<<"\n\t***Either Player is not playing One Day or not filling any data *** \n";
       }
}


