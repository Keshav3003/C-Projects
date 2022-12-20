//                   	   VEHICLE SHOWROOM MANAGEMENT
#include<stdlib.h>
#include<dos.h>
#include<ctype.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
class vehicle                            //Definition of class
{
	char type[30],model[45];
	float price;
	float cc;

	public :

		void Getdata();
		void Putdata()           //Function to output data to console.
		{
			 cout<<"\n\t\t\tTYPE      :  ";
			 cout<<type;
			 cout<<"\n\t\t\tMODEL     :  ";
			 cout<<model;
			 cout<<"\n\t\t\tCC        :  ";
			 cout<<cc;
		}


		void Showdata()           //Function to output data to console.
		{

			 cout<<"\n\t"<<type<<"\t\t"<<model<<"\t\t"<<cc<<"\t"<<price;

		}

		char* Access()            //Function to return model.
		{
			 return model;
		}
		char* Access1()            //Function to return type.
		{
			 return type;
		}
		long int Access2()        //Function to return price.
		{
			 return price;
		}
}v;     //CLASS ENDS HERE

		//void main();
		void loading2();
		void Dis();

		void  vehicle ::Getdata()           //Function to get data from user
		{
		      clrscr();
		      Dis();
		      cout<<"\n\t\t********************************************";
		      cout<<"\n\t\t\t\tINSERTION";
		      cout<<"\n\t\t********************************************";
		      char ch='y';
		      while(ch=='y')
		      {
				cout<<"\n\t\tENTER TYPE(\"CAR\"\,\"BIKE\"\,\"SCOOTY\"\,\"SCOOTER\")      :  ";
				gets(type);
				if(strcmpi(type,"car")==0 || strcmpi(type,"bike")==0 || strcmpi(type,"bike")==0 || strcmpi(type,"scooter")==0 || strcmpi(type,"scooty")==0)
			 {
				ch='n';
			 }
			 else
			 {      cout<<"\n\t\tWRONG TYPE ENTERED"<<endl;
				getch();
				clrscr();
				Dis();
				cout<<"\n\t\t********************************************";
				cout<<"\n\t\t\t\tINSERTION";
				cout<<"\n\t\t********************************************";
			  }
			}
			 cout<<"\t\tENTER MODEL     :  ";
			 gets(model);
			 cout<<"\t\tENTER CC        :  ";
			 cin>>cc;
			 cout<<"\t\tENTER PRICE     :  ";
			 cin>>price;

		}

		void des()
		{
			 clrscr();
			 textcolor(LIGHTBLUE);
			 cout<<"\n\n\n\t\t********************************************";
			 cout<<"\n\t\t\t   SHARMA HONDA SHOWROOM ";
			 cout<<"\n\t\t********************************************";
			 cout<<"\n\n\t\t\t1.OWNER MODE";
			 cout<<"\n\n\t\t\t2.USER MODE";
			 cout<<"\n\n\t\t\t3.PURCHASE";
			 cout<<"\n\n\t\t\t4.EXIT";
			 cout<<"\n\t\t--------------------------------------------";

		}
		void Dis()
		{
			 textcolor(LIGHTBLUE);
			 cout<<"\n\n\n\t\t";
			 cprintf("********************************************");
			 cout<<"\n\t\t\t";
			 cprintf("   SHARMA HONDA SHOWROOM ");
			 textcolor(MAGENTA);
		}

		void Insertion()
		{
			vehicle v1;
			int n;
			char choice='y';
			ofstream f;
			f.open("vehicle.dat",ios::binary|ios::app);
			while(choice=='y'||choice=='Y')
			{
				v1.Getdata();
				f.write((char*)&v1,sizeof(v1));
				cout<<"\n\nDo you want to enter more(Y\\N)  ";
				cin>>choice;
				cout<<endl<<endl;
			}
			f.close();
		}

		void Display()
		{
			 ifstream f;
			 int flag=0;
			 cout<<"\n\n\tTYPE\t\tMODEL\t\tCC\tPRICE";
			 cout<<"\n\t------------------------------------------------------------";
			 f.open("vehicle.dat",ios::binary);
			 vehicle v1;
			 while(f.read((char*)&v1,sizeof(v1)))
			 {
				  flag=1;
				  v1.Showdata();
			 }
			 if(flag==0)
			 cout<<"\n\tNo Record Found"<<endl;
			 f.close();
			 getch();
			 }
		void Search()
		{
			 char mn[15];
			 ifstream f;
			 int flag=0;
			 cout<<"\n\t\tENTER MODEL NAME  :  ";
			 cin>>mn;
			 f.open("vehicle.dat",ios::binary);
			 vehicle v1;
			 while(!f.eof())
			 {
				   f.read((char*)&v1,sizeof(v));
				   if(strcmpi(v1.Access(),mn)==0)
				   {
						if(f.eof())
						break;
						flag=1;
						cout<<"\n\n\tTYPE\t\tMODEL\t\tCC\tPRICE";
						cout<<"\n\t--------------------------------------------------------";
						v1.Showdata();
						break;
				   }
			 }
			 if(flag==0)
			     {	cout<<"\n\tNo Record Found"<<endl;
				getch();
			     }
			 f.close();
			 getch();

		}




		void Delete()
		{
			 int flag=0,flag2=0;
			 char mn[15],ch,name1[20],name2[20];
			 int i=1;
			 ifstream F;
			 ofstream f;
		 delete1:{

				cout<<"\n\n\t\t\t---------------";
				cout<<"\n\t\t\tLIST OF VEHICLE";
				cout<<"\n\t\t\t---------------\t\t\t";
				cout<<"\n\t\t\tSerial.\tModel\tType";
				 ifstream F;
				 F.open("vehicle.dat",ios::binary);
				while(!F.eof())
				{     F.read((char*)&v,sizeof(v));
					 if(F.eof())
					 {
						break;
					 }
					strcpy(name1,v.Access());
					strcpy(name2,v.Access1());
					cout<<"\n\t\t\t"<<i<<"."<<"\t"<<name1<<"\t"<<name2;
					i++;

				 }
				 F.close();
				 cout<<"\n\t\tENTER MODEL NAME  :  ";
				 cin>>mn;
				 F.open("vehicle.dat",ios::binary);
				 while(!F.eof())
				 {     F.read((char*)&v,sizeof(v));
					 if(F.eof())
					 {
						break;

					 }
					if(strcmpi(mn,v.Access())==0)
					{      flag=1;

					}

				}
				F.close();
				if(flag==0)
				 {
					cout<<"\n\t\tNO SUCH RECORD FOUND RETRY"<<endl;
					getch();
					clrscr();
					i=1;
					Dis();
					 cout<<"\n\n\n\t\t********************************************";
					 cout<<"\n\t\t\t\tDELETE";
					 cout<<"\n\t\t********************************************";
					 goto delete1;

				}
			 }
		       if(flag==1)
		      {	 F.open("vehicle.dat",ios::binary);
			 f.open("temp.dat",ios::binary);
			 while(!F.eof())
			 {
				 F.read((char*)&v,sizeof(v));
				 if(F.eof())
				 {
					break;
				 }

				 if(strcmpi(v.Access(),mn)!=0)
				 {
					 f.write((char*)&v,sizeof(v));
				 }
				 else
				 {
					cout<<"\n\t\t     THIS RECORD IS GOING TO BE DELETE";
					cout<<"\n\n\t--------------------------------------------------------";
					cout<<"\n\tTYPE\tMODEL\tCC\tPRICE";
					cout<<"\n\t--------------------------------------------------------";
					if(F.eof())
					{
						break;
					}

					v.Showdata();
					cout<<"\n\n\t\t DO YOU WANT TO DELETE IT[y/n]  : ";
					cin>>ch;
					if(ch=='y'||ch=='Y')
						flag2++;
					if(ch=='n'||ch=='N')
						break;
				}
			 }
			 f.close();
			 F.close();

			 if(flag2==0)
			 {
				 cout<<"\n\t\t\t    RECORD NOT DELETED";
				 getch();
			 }
			 if(flag2==1)
			 {
				remove("vehicle.dat");
				rename("temp.dat","vehicle.dat");
			 }
			 f.close();
		      }
		}

		void Modify()
		{
			 int flag=0,pos;
			 vehicle v1;
			 char mn[25],ch;
			 fstream f;
			 cout<<"\n\t\tENTER MODEL NAME  :  ";
			 cin>>mn;
			 f.open("vehicle.dat",ios::binary|ios::in|ios::out);
			while(!f.eof())
			{
			    pos=f.tellg();
			    f.read((char*)&v1,sizeof(v1));
			    if(strcmpi(v1.Access(),mn)==0)
			    {
					flag=1;
					v1.Getdata();
					f.seekp(pos);
					f.write((char*)&v1,sizeof(v1));
					break;
			    }
			 }
			if(flag==0)
			   cout<<"\n\t\t\t    RECORD NOT FOUND";

			f.close();
			getch();
		}

		void numvehicle()
		{
			 ifstream f;
			 char choice;
			 char type[20];
			 int flag=0,x=0,c=0,b=0,sc=0,s=0;
			 cout<<"\n\t------------------------------------------------------------";
			 f.open("vehicle.dat",ios::binary);
			 vehicle v1;
			 while(f.read((char*)&v1,sizeof(v1)))
			 {

				  v1.Showdata();
				  x++;
				  if((strcmpi(v1.Access1(),"CAR")==0))
					c++;
				  else
				  if((strcmpi(v1.Access1(),"BIKE")==0))
					b++;
				  else
				  if((strcmpi(v1.Access1(),"SCOOTER")==0))
					sc++;
				  else
				  if((strcmpi(v1.Access1(),"SCOOTY")==0))
					s++;
			 }
			 if(x==0)
			 cout<<"\n\tNo Record Found"<<endl;
			 else
			 {
				cout<<"\n\tTotal no. of Vehicles : "<<x;
				cout<<"\n\t------------------------------------------------------------";
				cout<<"\n\n\tNo. of CARS \t "<< c;
				cout<<"\n\n\tNo. of BIKE  \t "<<b;
				cout<<"\n\n\tNo. of SCOOTERS\t "<<sc;
				cout<<"\n\n\tNo. of SCOOTY \t "<<s;
			 }
			 cout<<"\n\n\tDO YOU WANT TO SEE THE VEHICLES REGISTERED(Y\\N) ";
			 cin>>choice;
			 if(choice=='y'||choice=='Y')
			 {
				clrscr();
				char ch='y';
				while(ch=='y')
				{
				clrscr();
				Dis();
				cout<<"\n\t\tENTER TYPE(\"CAR\"\,\"BIKE\"\,\"SCOOTY\"\,\"SCOOTER\")      :  ";
				gets(type);
				if(strcmpi(type,"car")==0 || strcmpi(type,"bike")==0 || strcmpi(type,"bike")==0 || strcmpi(type,"scooter")==0 || strcmpi(type,"scooty")==0)
					{
						ch='n';
					}
				else
					{
					cout<<"\n\t\tWRONG TYPE ENTERED,KINDLY RE-ENTER"<<endl;

					getch();
					}
				}
			 }
			 else
			 {     	 clrscr();
				  char ch2;
					label2:

						 Dis();
						 cout<<"\n\t\t********************************************";
						 cout<<"\n\t\t\t\tOWNER MODE";
						 cout<<"\n\t\t********************************************";
						 cout<<"\n\t\t\t1.INSERTION";
						 cout<<"\n\t\t\t2.SEARCH";
						 cout<<"\n\t\t\t3.MODIFY";
						 cout<<"\n\t\t\t4.DELETE";
						 cout<<"\n\t\t\t5.DISPLAY";
						 cout<<"\n\t\t\t6.VIEW VEHICLE STATISICS OF THE SHOWROOM";
						 cout<<"\n\t\t\t7.ROLLBACK TO MAIN MENU";
						 cout<<"\n\t\t\t8.EXIT THE PROGRAM";
						 cout<<"\n\t\t--------------------------------------------";
						 cout<<"\n\t\t   ENTER YOUR CHOICE  : ";
						 cin>>ch2;
						 if((ch2>='A' && ch2<='Z')||(ch2>='a' && ch2<='z'))
						 {     	cout<<"\n\t\tWrong Input"<<"\n\t\tKindly Re-ENTER ,Press any key to enter again";
							getch();
							clrscr();
							goto label2;

						 }
						else if(ch2>='1'&& ch2<='8')
						{
							switch(ch2)
							 {
							 case '1' :      clrscr();
									 Dis();
									 cout<<"\n\t\t********************************************";
									 cout<<"\n\t\t\t\tINSERTION";
									 cout<<"\n\t\t********************************************";
									 Insertion();
									 clrscr();
									 goto label2;


							 case '2' :      clrscr();
									 Dis();
									 cout<<"\n\n\n\t\t********************************************";
									 cout<<"\n\t\t\t\tSEARCH";
									 cout<<"\n\t\t********************************************";
									 Search();
									 clrscr();
									 goto label2;

							 case '3' :      clrscr();
									 Dis();
									 cout<<"\n\n\n\t\t********************************************";
									 cout<<"\n\t\t\t\tMODIFY";
									 cout<<"\n\t\t********************************************";
									 Modify();
									 clrscr();
									 goto label2;

							 case '4' :      clrscr();
									 Dis();
									 cout<<"\n\n\n\t\t********************************************";
									 cout<<"\n\t\t\t\tDELETE";
									 cout<<"\n\t\t********************************************";
									 Delete();
									 clrscr();
									 goto label2;

							 case '5' :      clrscr();
									 Dis();
									 cout<<"\n\n\n\t\t********************************************";
									 cout<<"\n\t\t\t\tDISPLAY";
									 cout<<"\n\t\t********************************************";
									 Display();
									 clrscr();
									 goto label2;

							 case '6':       clrscr();
									 Dis();
									 cout<<"\n\n\n\t\t********************************************";
									 cout<<"\n\t\t\t\tRECORD CHECK";
									 cout<<"\n\t\t********************************************";
									 numvehicle();
									 clrscr();
									 goto label2;



							 case '7' : loading2();

							 break;

							 case '8' :        Dis();
									 cout<<"\n\n\n\t\t********************************************";
									 cout<<"\n\t\t\t\tEXIT";
									 cout<<"\n\t\t********************************************";
									 exit(1);
									 break;
							 }

						}

						else
						{


								cout<<"\n\t\tWrong Input"<<"\n\t\tKindly Re-ENTER,Press any key to enter again";
								getch();
								clrscr();
								goto  label2;


						}


			 }

			 f.close();
			 f.open("vehicle.dat",ios::binary);

			  cout<<"\n\n\tTYPE\t\tMODEL\t\tCC\tPRICE";
			  cout<<"\n\t--------------------------------------------------------";
			 while( f.read((char*)&v1,sizeof(v1)))
			 {

				   if(strcmpi(v1.Access1(),type)==0)
				   {
						flag=1;
						if(f.eof())
						break;
						v1.Showdata();
						cout<<endl;
				      }
			 }
			 if(flag==0)
				cout<<"\n\tNo Record Found"<<endl;

			 f.close();
			 getch();
		}


		void Owner()
		{
			  textcolor(LIGHTMAGENTA);
			  int f1=0;
			  char ch2;
			  char ch;
			  char user[7];
			  char pass[7];
			  cout<<"\t\t\tEnter Username"<<endl;
			  while(1)
			  {
				cout<<"\t\t\t";
				gets(user);
				if(strcmpi(user,"prakhar")==0||strcmpi(user,"keshav")==0)
					break;
				else
				 {
					   cout<<"\n\t\t\tWrong Username,Press any key to enter again"<<endl;
					   cout<<"\n\t\t\t";
					   getch();
					   des();
					   cout<<"\nRetry Entering username "<<endl;
					   continue;

				 }
			 }
			 cout<<"\n\t\t\tEnter  Password"<<endl;
			 password :
						cout<<"\t\t\t";
						for(int i=0;;i++)
						{
							ch=getch();							if(ch>='A'&&ch<='Z')
							{
								cout<<"*";
								pass[i]=ch;

							}
							else if(ch>='a'&&ch<='z')
							{
								cout<<"*";
								pass[i]=ch;

							}
							else if(ch=='\b')
							{
								cout<<"\b"<<" "<<"\b";
								i=i-2;

							}
							else if(ch=='\r')
							{
							       pass[i]='\0';
							       break;

							}


						}



				    if((strcmpi(pass,"prakhar")==0)||(strcmpi(pass,"keshav")==0))
					f1=1;
				    else
				    {
					cout<<"\n\t\t\tWrong Password,,Press any key to enter again"<<endl;
					cout<<"\n\t\t\t";
					getch();
					des();
					cout<<"\nRe-try Entering Password"<<endl;
					goto password;

				    }
				    if(f1==1)
				    {
						 clrscr();

					label2:

						 Dis();
						 cout<<"\n\t\t********************************************";
						 cout<<"\n\t\t\t\tOWNER MODE";
						 cout<<"\n\t\t********************************************";
						 cout<<"\n\t\t\t1.INSERTION";
						 cout<<"\n\t\t\t2.SEARCH";
						 cout<<"\n\t\t\t3.MODIFY";
						 cout<<"\n\t\t\t4.DELETE";
						 cout<<"\n\t\t\t5.DISPLAY";
						 cout<<"\n\t\t\t6.VIEW VEHICLE STATISICS OF THE SHOWROOM";
						 cout<<"\n\t\t\t7.ROLLBACK TO MAIN MENU";
						 cout<<"\n\t\t\t8.EXIT THE PROGRAM";
						 textcolor(BROWN);
						 cout<<"\n\t\t";
						 cprintf("--------------------------------------------");
						 cout<<"\n\t\t";
						 textcolor(YELLOW);
						 cprintf("   ENTER YOUR CHOICE  : ");
						 cin>>ch2;
						 if((ch2>='A' && ch2<='Z')||(ch2>='a' && ch2<='z'))
						 {     	cout<<"\n\t\tWrong Input"<<"\n\t\tKindly Re-ENTER,Press any key to enter again";
							getch();
							clrscr();
							goto label2;

						 }

						else if(ch2>='1'&& ch2<='8')
						{
							switch(ch2)
							 {
							 case '1' :      clrscr();
									 Dis();
									 cout<<"\n\t\t********************************************";
									 cout<<"\n\t\t\t\tINSERTION";
									 cout<<"\n\t\t********************************************";
									 Insertion();
									 clrscr();
									 goto label2;


							 case '2' :      clrscr();
									 Dis();
									 cout<<"\n\n\n\t\t********************************************";
									 cout<<"\n\t\t\t\tSEARCH";
									 cout<<"\n\t\t********************************************";
									 Search();
									 clrscr();
									 goto label2;

							 case '3' :      clrscr();
									 Dis();
									 cout<<"\n\n\n\t\t********************************************";
									 cout<<"\n\t\t\t\tMODIFY";
									 cout<<"\n\t\t********************************************";
									 Modify();
									 clrscr();
									 goto label2;

							 case '4' :      clrscr();
									 Dis();
									 cout<<"\n\n\n\t\t********************************************";
									 cout<<"\n\t\t\t\tDELETE";
									 cout<<"\n\t\t********************************************";
									 Delete();
									 clrscr();
									 goto label2;

							 case '5' :      clrscr();
									 Dis();
									 cout<<"\n\n\n\t\t********************************************";
									 cout<<"\n\t\t\t\tDISPLAY";
									 cout<<"\n\t\t********************************************";
									 Display();
									 clrscr();
									 goto label2;

							 case '6':       clrscr();
									 Dis();
									 cout<<"\n\n\n\t\t********************************************";
									 cout<<"\n\t\t\t\tRECORD CHECK";
									 cout<<"\n\t\t********************************************";
									 numvehicle();
									 clrscr();
									 goto  label2;

							 case '7' : loading2();

							 break;

							 case '8' :        Dis();
									 cout<<"\n\n\n\t\t********************************************";
									 cout<<"\n\t\t\t\tEXIT";
									 cout<<"\n\t\t********************************************";
									 exit(1);
									 break;
							 }

						}

						else
						{


								cout<<"\n\t\tWrong Input"<<"\n\t\tKindly Re-ENTER,Press any key to enter again";
								getch();
								clrscr();
								goto  label2;


						}



				    }
		}

		void User()
		{
			 clrscr();
			 int i=1;
			 long int lp,mp;
			 char name[15],mn[15];int flag=0;
			 Dis();
			 cout<<"\n\n\t********************************************************";
			 cout<<"\n\t\t\t\tUSER MODE";
			 cout<<"\n\t********************************************************";
			 cout<<"\n\t\t\t\t------";
			 cout<<"\n\t\t\t\tBUDGET";
			 cout<<"\n\t\t\t\t------";
			 cout<<"\n\t\t\tENTER LOWEST PRICE  : ";
			 cin>>lp;
			 cout<<"\n\t\t\tENTER HIGHEST PRICE : ";
			 cin>>mp;
			 ifstream f;
			 f.open("vehicle.dat",ios::binary);
			 cout<<"\n\t--------------------------------------------------------";
			 cout<<"\n\t\t\tLIST OF VEHICLE";
			 cout<<"\n\t--------------------------------------------------------\t\t\t";
			 while(!f.eof())
			 {
				  f.read((char*)&v,sizeof(v));
				  if((v.Access2()>=lp)&&(v.Access2()<=mp))
				  {        flag=1;
					   if(f.eof())
					       break;
					   strcpy(name,v.Access());
					   cout<<"\n\t\t\t"<<i<<". "<<name;
					   i++;
				  }

			 }
			 if(flag==0)
				{       getch();
					cout<<"No such record found in the list"<<endl;
					cout<<"\tPushing Back to the main menu "<<endl;
					getch();
					delay(150);
					loading2();
				}
		if(flag==1)
		{        int f1=0;
			 cout<<"\n\t--------------------------------------------------------";
			 cout<<"\n\t\tENTER MODEL NAME  :  ";
			 cin>>mn;
			 getch();
			 f.close();
			 f.open("vehicle.dat",ios::binary);
			 while(!f.eof())
			  {
				f.read((char*)&v,sizeof(v));
				if(strcmpi(v.Access(),mn)==0)
				{         f1=1;
					  if(f.eof())
					  break;
					  clrscr();
					  Dis();
					  cout<<"\n\t\t********************************************";
					  cout<<"\n\t\t\t       DETAILS";
					  cout<<"\n\t\t********************************************";
					  v.Putdata();
					  cout<<"\n\t\t********************************************";

				}

			  }
			  if(f1==0)
			  {             getch();
					cout<<"No such record found in the list"<<endl;
					cout<<"\tPushing Back to the main menu "<<endl;
					getch();
					delay(150);
					loading2();
			  }
			  if(f1==1)
			  {             getch();
					delay(150);
					loading2();
			  }

		}
			  getch();
			  f.close();
		}

		void Cal(int mon,long int price,int per)
		{
			    long int nprice=0,em=0;
			    nprice=price+((price*per)/100);
			    em=nprice/mon;
			    cout<<"\n\t\t  "<<mon<<"\t   "<<per<<"%\t\t"<<em<<"\t "<<nprice;
		}
		void Calc(int mon,long int price,int per)
		{
			  long int nprice=0,em=0;
			  nprice=price+((price*per)/100);
			  em=nprice/mon;
			  cout<<"\t\tMONTH                   : "<<mon;
			  cout<<"\n\t\tRATE OF INTEREST        : "<<per<<"%";
			  cout<<"\n\t\tMONTHLY COST            : "<<em;
			  cout<<"\n\t\tTOTAL COST              : "<<nprice;
		 }

	void Purchase()
	{
		 char pn[10];
		 char mode[20];
		 long int price;
		 int i=1,flag=0;
		 char mn[20],name[20],name1[20];
		 long int dis,month;
		 float da=0,netprice=0;
		 char ch,abc[20],address[50],ifsc[15],bankname[20],accno[10];
		 Dis();



			purchase :
			{
				  cout<<"\n\t********************************************************";
				  cout<<"\n\t\t\t     PURCHASE MODE";
				  cout<<"\n\t********************************************************";
				  ifstream f;
				  f.open("vehicle.dat",ios::binary);
				  cout<<"\n\n\t\t\t---------------";
				  cout<<"\n\t\t\tLIST OF VEHICLE";
				  cout<<"\n\t\t\t---------------\t\t\t";
				  cout<<"\n\t\t\tSerial.\tModel\tType";
				  while(!f.eof())
				  {
					f.read((char*)&v,sizeof(v));
					if(f.eof())
					break;
					strcpy(name,v.Access());
					strcpy(name1,v.Access1());
					cout<<"\n\t\t\t"<<i<<"."<<"\t"<<name<<"\t"<<name1;
					i++;
				  }
				  cout<<"\n\t--------------------------------------------------------";
				  cout<<"\n\t\tENTER MODEL NAME  :  ";
				  cin>>mn;
				  f.close();
			 }

			 ifstream f;
			 f.open("vehicle.dat",ios::binary);
			 while(!f.eof())
			 {
			    f.read((char*)&v,sizeof(v));
			    if(strcmpi(v.Access(),mn)==0)
			    {        flag=1;
				     if(f.eof())
				     break;
				     price=v.Access2();
			    }
			 }


			 if(flag==0)
			 {
				cout<<"\n\t\tNO SUCH RECORD FOUND RETRY"<<endl;
				getch();
				clrscr();
				i=1;
				Dis();
				goto purchase;

			}
			f.close();
			char x;
			ch='y';
			 while(ch=='y')
				{
					clrscr();
					Dis();
					cout<<"\n\t********************************************************";
					cout<<"\n\t\t\t    MODE OF PAYMENT";
					cout<<"\n\t********************************************************";
					cout<<"\n\t\t\t\t 1. CASH";
					cout<<"\n\t\t\t\t 2. EMI";
					cout<<"\n\t--------------------------------------------------------";
					cout<<"\n\t\t\tENTER YOUR CHOICE   : ";
					cin>>x;
					cout<<"\t--------------------------------------------------------\n";
					if(x=='1'||x=='c'||x=='C'||x=='a'||x=='A')
					{
						dis=5;
						netprice=price+(price*0.18)-(price*0.05);
						da=price*0.05;
						cout<<"\t\t\tPRICE               : "<<price;
						cout<<"\n\t\t\tDISCOUNT PERCENTAGE : "<<dis<<"%";
						cout<<"\n\t\t\tDISCOUNT AMOUNT     : "<<da;
						cout<<"\n\t\t\tGST INCLUDED        : 18%";
						cout<<"\n\t\t\tNET PRICE           : "<<netprice;
						strcpy(mode,"cash");
						ch='n';
					}
					else
					if(x=='2'||x=='e'||x=='e'||x=='b'||x=='B')
					{
						cout<<"\t\tPRICE                  : "<<price;
						cout<<"\n\t\t__________________________________________";
						cout<<"\n\t\tMONTH\tINTEREST\t\EMI\tTOTAL COST";
						cout<<"\n\t\t------------------------------------------";
						Cal(6,price,10);
						Cal(9,price,13);
						Cal(12,price,15);
						strcpy(mode,"emi");
						ch='n';
					}
					else
					{	cout<<"\n\n\tWrong Input";
						getch();
					}
				}
				cout<<"\n\n\t\t  DO YOU WANT TO PURCHASE[y/n] : ";
				cin>>ch;
				if(ch=='y'||ch=='Y')
				{
					clrscr();
					Dis();
				      cout<<"\n\t********************************************************";
				      cout<<"\n\t\t\t  ENTER DETAILS";
				      cout<<"\n\t********************************************************";
				      cout<<"\n\t\tENTER NAME                          : ";
				      gets(abc);
				      cout<<"\t\tENTER ADDRESS                       : ";
				      gets(address);
			      phone : cout<<"\t\tENTER PHONE NO.                     : ";
				      cin>>pn;
				      int l=strlen(pn);
				      if(l!=10)
				       goto phone;
				      if(strcmpi(mode,"emi")==0)
					{
						 cout<<"\t\tENTER NO. OF MONTHS FOR EMI[6/9/12] : ";
						 cin>>month;
						 cout<<"\t\tENTER ACCOUNT NUMBER                : ";
						 cin>>accno;
						 cout<<"\t\tENTER BANK NAME                     : ";
						 cin>>bankname;
						 cout<<"\t\tENTER IFSC CODE                     : ";
						 cin>>ifsc;
					}
				}
				else
				{    	cout<<"\n\n\t\tPushing back to main menu"<<endl;
					delay(100);
					loading2();
				}
				clrscr();
				Dis();
				int num=5;
				cout<<"\n\t********************************************************";
				cout<<"\n\t\t\t    DETAILS";
				cout<<"\n\t********************************************************";
				cout<<"\n\t\tTRANSACTION ID : ";
				for(i=0;i<7;i++)
					cout<<random(num);
				cout<<"\n\t\tNAME                    : ";
				puts(abc);
				cout<<"\t\tADDRESS                 : ";
				puts(address);
				cout<<"\t\tPHONE NO.               : ";
				cout<<pn;
				cout<<"\n\t********************************************************";
				cout<<"\n\t\tVEHICLE NAME            : ";
				cout<<mn;
				if(strcmpi(mode,"cash")==0)
				{
				   cout<<"\n\t\tPRICE                   : "<<price;
				   cout<<"\n\t\tDISCOUNT PERCENTAGE     : "<<dis<<"%";
				   cout<<"\n\t\tDISCOUNT AMOUNT         : "<<da;
				   cout<<"\n\t\tNET PRICE               : "<<netprice;
				   cout<<"\n\t********************************************************";
				}
				else if(strcmpi(mode,"emi")==0)
				 {
					   cout<<"\n\t\tPRICE                   : "<<price<<"\n";
					if(month==6)
						   Calc(6,price,10);
					else
					if(month==9)
						   Calc(9,price,13);
					else
					if(month==12)
						   Calc(12,price,15);
					cout<<"\n\t********************************************************";
					cout<<"\n\t\tACCOUNT NUMBER          : ";
					cout<<accno;
					cout<<"\n\t\tBANK NAME               : ";
					cout<<bankname;
					cout<<"\n\t\tIFSC CODE               : ";
					cout<<ifsc;
					cout<<"\n\t********************************************************";

				 }
				textcolor(LIGHTRED);
				cout<<"\n\n\t\tNow pushing back to main menu"<<endl;
				getch();
				loading2();


	      }


		void startup()
		{
			 int a=1;
			 char ch;
			 ch=a;
			 clrscr();
			 textcolor(LIGHTRED);
			 cout<<"\n\n";
			 cout<<"       * * * * *   *     *     * *      *  *      *         *     * *     \n";
			 cout<<"       *           *     *   *     *    *    *    *  *   *  *   *     *   \n";
			 cout<<"       * * * * *   * * * *   * * * *    *  *      *    *    *   * * * *   \n";
			 cout<<"               *   *     *   *     *    *   *     *         *   *     *   \n";
			 cout<<"       * * * * *   *     *   *     *    *    *    *	    *   *     *   \n";
			 cout<<"\n\n";
			 for(int i=0;i<=79;i++)
				cout<<ch;
			 delay(360);
			 cout<<"\n";
			 cout<<" * * * * *  *     *  *  *  *  *         *  * *    * * * *  * * * *  *        *  ";
			 cout<<" *  	    *     *  *     *  *         *  *   *  *     *  *     *  *  *   * *  ";
			 cout<<" * * * * *  * * * *  *     *  *    *    *  * *	  *     *  *     *  *    *   *  ";
			 cout<<"         *  *     *  *     *  *  *   *  *  *  *   *     *  *	 *  *        *  ";
			 cout<<" * * * * *  *     *  * * * *  *         *  *   *  * * * *  * * * *  *	     *  ";
			 cout<<"\n\n";
			 a=219;
			 ch=a;
			 for(i=0;i<=79;i++)
				cout<<ch;
			 cout<<"\n\n\t\t    Press any key to continue";
			 getch();
		}

		void menu1()
		{
			 char ch1;
			 label:
			 clrscr();
			 textcolor(LIGHTCYAN);
			 cout<<"\n\n\n\t\t";
			 cprintf("********************************************");
			 cout<<endl<<"\t\t\t";
			 cprintf("   SHARMA HONDA SHOWROOM ");
			 cout<<endl<<"\t\t";
			 cprintf("********************************************");
			 textcolor(LIGHTMAGENTA);
			 cout<<"\n\n\t\t\t1.OWNER MODE";
			 cout<<"\n\n\t\t\t2.USER MODE";
			 cout<<"\n\n\t\t\t3.PURCHASE";
			 cout<<"\n\n\t\t\t4.EXIT";
			 textcolor(BROWN);
			 cout<<"\n\t\t";
			 cprintf("--------------------------------------------");
			 cout<<"\n\t\t";
			 textcolor(YELLOW);
			 cprintf("   ENTER YOUR CHOICE  : ");
			 cin>>ch1;
			 if((ch1>='A' && ch1<='Z')||(ch1>='a' && ch1<='z'))
			 {
			      goto label;

			 }
			 if(ch1>='1'&&ch1<='4')
			 {
				switch(ch1)
				 {
					case '1' :
							Owner();
					break;
					case '2' :
							clrscr();
							User();
					break;
					case '3' :
							clrscr();
							Purchase();
					break;
					case '4' :
							exit(0);
					break;
				 }
			}
			else
			{
				while(1)
				{
					cout<<"\n\t\tWrong Input"<<"\n\t\tKindly Re-ENTER,Press any key to enter again";
					getch();
					menu1();
				}
			 }

		}


		void loading2()
		{
			textcolor(LIGHTBLUE);
			clrscr();
			textcolor(LIGHTCYAN);
			gotoxy(30,12);
			cprintf("LOADING....");
			int x=0,a=219,num=5;
			char ch;
			ch=a;
			for(int i=1;i<=20;i++)
			{
				gotoxy(30+x,13);
				delay(150);
				cout<<ch;
				x=x+1;
				gotoxy(53,13);
				cout<<num<<"%";
				num=num+5;
			}
			a=1;
			ch=a;
			gotoxy(35,14);
			cout<<"COMPLETING YOUR REQUEST "<<ch<<" "<<ch<<" ";
			for(int k=1;k<6;k++)
				{
					cout<<".";
					delay(100);
				}
			textcolor(LIGHTMAGENTA);
			menu1();
		}


		void loading()
		{

			clrscr();
			textcolor(LIGHTRED);
			gotoxy(30,12);
			cprintf("LOADING....");
			int x=0,a=219,num=5;
			char ch;
			ch=a;
			for(int i=1;i<=20;i++)
			{
				gotoxy(30+x,13);
				delay(250);
				cout<<ch;
				x=x+1;
				gotoxy(53,13);
				cout<<num<<"%";
				num=num+5;
			}
			a=1;
			ch=a;
			textcolor(LIGHTGREEN+BLINK);
			gotoxy(35,14);
			cprintf("COMPLETE ",ch," ",ch," ");
			delay(200);
			cprintf("!");
			delay(200);
			cprintf("!");
			delay(300);
			gotoxy(30,21);
			textcolor(CYAN);
			cprintf("Press any key to continue...........");
			getch();
		}

		void main()
		{
			textcolor(YELLOW);
			loading();
			textcolor(LIGHTRED);
			startup();
			textcolor(LIGHTMAGENTA);
			menu1();
			getch();
		}