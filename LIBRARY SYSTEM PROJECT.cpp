#include<fstream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<iostream>
using namespace std;

fstream fp,fp1;//filing

void book_menu();
void student_menu();
void issue_book();
void book_return();
void write_student();
void book_return();
int fines();
void display_all_students();
static int stock=100; 

class book
{
    char book_number[30];
    char book_name[50];
    char author_name[20];
    char book_nu[10];
    
  	public:
  		
        void create_book()
        {
            cout<<"\nEnter Book Number: ";
            cin>>book_number;
            cout<<"\nEnter Name of The Book: ";
            cin.ignore();
            cin.getline(book_name,50);
            cout<<"\nEnter Author's Name: ";
            cin.getline(author_name,50);
           	cout<<"\nEnter Stock";
			cin.getline(book_nu,10); 
		    cout<<"\t\t\n\nBook Created Successfully";
            system("cls");
            
		}
 
        void show_book()
        {
        	cout<<"\nBook Number: "<<book_number;
            cout<<"\nBook Name: "<<book_name;
            cout<<"\nAuthor's Name: "<<author_name;
        }
        
        void modify_book()
        {
            cout<<"\nBook number : "<<book_number;
            cout<<"\nModify Book Name : ";
            cin.ignore();
            cin.getline(book_name,50);
            cout<<"\nModify Author's Name: ";
            cin.ignore();
            cin.getline(author_name,50);
            cout<<"\nModify Stock:";
            cin.getline(book_nu,10);
        }
        
        char* getbooknumber()
        {
            return book_number;
        }
          
		void report()
        {
			cout << book_number << setw(30) << book_name <<setw (30) << author_name << endl;
		}
		
 		void getstock()
		{
 			cout<< stock;;
		}
};               

class admin: public book
{
	int option;
	
	public: 
	
	
	int passwordforAdmin()
	{
		string pass1 ="";
    	char ch1;
    	cout << "ENTER ADMIN PASSWORD: ";
    	ch1 = _getch();
    	
    	while(ch1 != 13)
		{
      		pass1.push_back(ch1);
      		cout << '*';
      		ch1 = _getch();
      		
    	}
    		system("cls");
    	
    	if(pass1 == "admin" || pass1 == "ADMIN")
		{
			for(;;)
			{
			
      		cout << "\n\n\t\t\tADMIN MENU";
      		cout << "\n\n\tPRESS 1) BOOK MENU\n\tPRESS 2) STUDENT MENU\n\tPRESS 3) EXIT\n\n\tOPTION: ";
      		cin >> option;
      		
      		if(option == 1)
			{
			  book_menu();	
			}
			
			else if (option == 2)
			{
				student_menu();
			}
			
			else if (option == 3)
			{
				break;
			}
			
			else 
			{
				cout << "INVALID CHOICE ENTERED! ";
			}
    	}
    	}
    	else 
		{
			cout << "INCORRECT PASSWORD!";
		}
    }
};
 
class student: public book
{
    char ID_number[20];
    char Student_name[20];
    char stbno[6];
    int token;
    int option;
    
	public:
		
		int passwordforstudent()
		{
			string pass ="";
   			char ch;
   			
   			cout << "ENTER STUDENT PASSWORD: ";
   			ch = _getch();
   			
   			while(ch != 13)	
			{
      			pass.push_back(ch);
      			cout << '*';
      			ch = _getch();
   			}
   			
   			system("cls");
   			
   			if(pass == "fahad")
			{
      			for(;;)
				{
			
      		cout << "\n\n\t\t\tSTUDENT MENU";
      		cout << "\n\n\tPRESS 1) ISSUE BOOK\n\tPRESS 2) RETURN BOOK\n\tPRESS 3) EXIT\n\n\tOPTION: ";
      		cin >> option;
      		
      		if(option == 1)
			{
			  	issue_book();
			}
			
			else if (option == 2)
			{
				book_return(); 
			}
			
			else if (option == 3)
			{
				break;	
			}
			
			else 
			{
				cout << "INVALID CHOICE ENTERED! ";
				return 0;
			}
			}
			}
		}
		
        void create_student()
        {
        	cout<<"\nENTER ID: ";
            cin>>ID_number;
            cout<<"\nENTER STUDENT NAME: ";
            cin>>Student_name;
            token=0;
            stbno[0]='/0';
            cout<<"\t\t\n\nSTUDENT RECORD CREATED SUCCESSFULLY!";
            system("cls");
//            write_student();
        }
        
        void show_student()
        {
            cout<<"\nSTUDENT: " <<ID_number;
            cout<<"\nSTUDENT NAME: ";
            puts(Student_name);
            cout<<"\nNO OF BOOKS ISSUED: "<<token;
            
            if(token==1)
                cout<<"\nBook No "<< stbno;
        }
        
        void modify_student()
        {
            cout<<"\nSTUDENT ID: " << ID_number;
            cout<<"\nMODIFY STUDENT NAME: ";
            cin.ignore();
            cin.getline(Student_name,50);
        }
        
        char* get_ID_number()
        {
            return ID_number;
        }
        
        char* retstbno()
        {
            return stbno;
    	}
    	
        int rettoken()
        {
            return token;
        }
        
        void addtoken()
        {
			token=1;
		}
          
		void resettoken()
        {token=0;
		}
          
		void getstbno(char t[])
        {
            strcpy(stbno,t);
        }
        
        void report()
        {
			cout<<"\t"<<ID_number<<setw(20)<<Student_name<<setw(10)<<token<<endl;
		}
};        

book bk;// object
admin ad;// object
student st;//object

class librarian: protected book
{
	char g[20];
	int t1;
	
	public:
		
		void inventory(char n[])
		{
    		system("cls");
    		int check=0;

    		cout<<"\nSTOCK Details\n";
    
    		fp.open("book.dat",ios::in);
    
    		while(fp.read((char*)&bk,sizeof(book)))
   			{
        		if(strcmpi(bk.getbooknumber(),n)==0)
        		{
            		bk.getstock();
            		check=1;
        		}
    		}
          
			fp.close();
    
			if(check==0)
        		cout<<"\n\nNO STOCK!";
        		getch();
		}
		
		int passwordforlibrarian()
		{
			string pass ="";
   			char ch;
   			
   			cout << "ENTER LIBRARIAN PASSWORD: ";
   			ch = _getch();
   			
   			while(ch != 13)	
			{
      			pass.push_back(ch);
      			cout << '*';
      			ch = _getch();
   			}
   			
   			system("cls");
   			
   			if(pass == "librarian")
			{
      			for(;;)
				{
			
      		cout<<"\n\n\t\tLIBRARIAN MENU\n\n\tPRESS 1) STOCK CHECK\n\tPRESS 2) STUDENT INFO\n\tPRESS 3) FINE\n\tPRESS 4) EXIT";
			cout << "\n\n\tENTER: ";
			cin>>t1;
			system("cls");
      		
      		if(t1==1)
			{
				cout<<"\n\nEnter Book number: ";
				cin>>g;
				inventory(g);
			}

			else if(t1==2)
			{				
				system("cls");
            	display_all_students();
			}
			
			else if(t1==3)
			{				
				cout<<"\n\nCURRENT STUDENT FINES: " << fines();
			}
					
			else if (t1 == 4)
			{
				break;	
			}
			
			else 
			{
				cout << "INVALID CHOICE ENTERED! ";
				return 0;
			}
			}
			}
	}
};

librarian li;//object
 
void write_book()
{
    system("cls");
    int more_or_main;
    
    fp.open("book.dat",ios::out|ios::app);
    
    do
    {
        bk.create_book();
        fp.write((char*)&bk,sizeof(book));
        cout<<"\nPress 1) CREATE ANOTHER BOOK";
        cout<<"\nPress 2) MAIN MENU";
        cout<<"\nEnter: ";
        cin>>more_or_main;
        system("cls");
    }
	
	while(more_or_main == 1);
    fp.close();
}

void write_student()
{
    system("cls");
    int more_or_main;
    
    fp.open("student.dat",ios::out|ios::app);
          
	do
    {
        st.create_student();
        fp.write((char*)&st,sizeof(student));
        cout<<"\nPress 1) CREATE ANOTHER STUDENT";
        cout<<"\nPress 2) MAIN MENU\n";
        cout<<"Enter: ";
        cin>>more_or_main;
        system("cls");
    }
	
	while(more_or_main == 1);
    fp.close();
}

void display_a_book(char n[])
{
    system("cls");
    int check=0;

    cout<<"\nBOOK DETAILS\n";
    
    fp.open("book.dat",ios::in);
    
    while(fp.read((char*)&bk,sizeof(book)))
    {
        if(strcmpi(bk.getbooknumber(),n)==0)
        {
            bk.show_book();
            check=1;
        }
    }
          
	fp.close();
    
	if(check==0)
        cout<<"\n\nBook does not exist";
        getch();
}

void display_a_student(char n[])
{
    system("cls");
    int check=0;
    
    cout<<"\nSTUDENT DETAILS\n";
          
    fp.open("student.dat",ios::in);
    
    while(fp.read((char*)&st,sizeof(student)))
    {
        if((strcmpi(st.get_ID_number(),n)==0))
        {
            st.show_student();
            check=1;
        }
    }
          
	fp.close();
          
	if(check==0)
        cout<<"\n\nStudent does not exist";
        getch();
}

void modify_book()
{
    system("cls");
    char n[20];
    int found=0;
    
    cout<<"\n\n\tMODIFY BOOK";
    cout<<"\n\n\tEnter The book number: ";
    cin>>n;
          
	fp.open("book.dat",ios::in|ios::out);
	
    while(fp.read((char*)&bk,sizeof(book)) && found==0)
    {
        if(strcmpi(bk.getbooknumber(),n)==0)
        {
            bk.show_book();
            cout<<"\nEnter The New Details of book"<<endl;
            bk.modify_book();
            int pos=-1*sizeof(bk);
                              
			fp.seekp(pos,ios::cur);
            fp.write((char*)&bk,sizeof(book));
            cout<<"\n\n\t Record Updated Successfully...";
            found=1;
        }
    }
          
	fp.close();
    
	if(found==0)
        cout<<"\n\n Record Not Found ";
        getch();
}

void modify_student()
{
    system("cls");
    char n[20];
    int found=0;
    
    cout<<"\n\n\tMODIFY STUDENT RECORD... ";
    cout<<"\n\n\tEnter Student's ID number: ";
    cin>>n;
          
	fp.open("student.dat",ios::in|ios::out);
          
	while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
        if(strcmpi(st.get_ID_number(),n)==0)
        {
            st.show_student();
            cout<<"\nEnter The New Details of student"<<endl;
            st.modify_student();
            int pos=-1*sizeof(st);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&st,sizeof(student));
            cout<<"\n\n\t Record Updated Successfully...";
            found=1;
        }
    }
          
	fp.close();
          
	if(found==0)
        cout<<"\n\n Record Not Found ";
        getch();
}

void delete_student()
{
    system("cls");
    char n[20];
    int flag=0;
    
    cout<<"\n\n\n\tDELETE STUDENT";
    cout<<"\n\nEnter The ID number of the Student You Want To Delete: ";
    cin>>n;
    
    fp.open("student.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    
    while(fp.read((char*)&st,sizeof(student)))
    {
        if(strcmpi(st.get_ID_number(),n)!=0)
        fp2.write((char*)&st,sizeof(student));
        
		else
        	flag=1;
    }
          
	fp2.close();
    fp.close();
    remove("student.dat");
    rename("Temp.dat","student.dat");
    
    if(flag==1)
        cout<<"\n\n\tRecord Deleted ..";
          
	else
        cout<<"\n\nRecord not found";
        getch();
}

void delete_book()
{
    system("cls");
    char n[20];
    int flag=0;
    
    cout<<"\n\n\n\tDELETE BOOK";
    cout<<"\n\nEnter The Book's number You Want To Delete: ";
    cin>>n;
          
	fp.open("book.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    
    while(fp.read((char*)&bk,sizeof(book)))
    {
        if(strcmpi(bk.getbooknumber(),n)!=0)  
        {
            fp2.write((char*)&bk,sizeof(book));
        }
                    
		else
            flag=1;
    }
    
    fp2.close();
    fp.close();
    remove("book.dat");
    rename("Temp.dat","book.dat");
    
    if(flag==1)
        cout<<"\n\n\tRecord Deleted ..";
          
	else
        cout<<"\n\nRecord not found";
        getch();
}

void display_all_students()
{
    system("cls");
    
    fp.open("student.dat",ios::in);
    
    if(!fp)
    {
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
        getch();
        return;
    }
          
	cout<<"\n\n\t\tSTUDENT LIST\n\n";
    cout<<"==================================================================\n";
    cout<<"\tID Number"<<setw(10)<<"Name"<<setw(15)<<"Book Issued\n";
    cout<<"==================================================================\n";
          
	while(fp.read((char*)&st,sizeof(student)))
    {
        st.report();
    }
          
	fp.close();
    getch();
}

void display_allb()
{
    system("cls");
          
	fp.open("book.dat",ios::in);
          
	if(!fp)
    {
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
        getch();
        return;
    }
    
    cout<<"\n\n\t\tBook LIST\n\n";
    cout<<"=========================================================================\n";
    cout<<"Book Number"<<setw(20)<<"Book Name"<<setw(25)<<"Author\n";
    cout<<"=========================================================================\n";
          
	while(fp.read((char*)&bk,sizeof(book)))
    {
        bk.report();
    }
    
	fp.close();
    getch();
}

void issue_book()
{
    system("cls");
    char sn[20],bn[20];
    int found=0,flag=0;
    
    cout<<"\t\t\t\nBOOK ISSUE";
    cout<<"\n\n\tENTER STUDENT ID: ";
    cin>>sn;
    
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    
    while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
        if(strcmpi(st.get_ID_number(),sn)==0)
        {
            found=1;
                        
				if(st.rettoken()==0)
            	{
                    cout<<"\n\n\tENTER BOOK NO: ";
                    cin>>bn;
                                         
						while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
                        {
                            if(strcmpi(bk.getbooknumber(),bn)==0)
                            {
                                bk.show_book();
                                flag=1;
                                st.addtoken();
                                st.getstbno(bk.getbooknumber());
                                int pos=-1*sizeof(st);
                                fp.seekp(pos,ios::cur);
                                fp.write((char*)&st,sizeof(student));
                                cout<<"\n\n\tBOOK ISSUED SUCCESSFULLY!";
                                stock-=1;
                            }
                        }
                                        
						if(flag==0)
						{						
            				cout<<"BOOK NUMBER DOES NOT EXISTS";
            			}
                }
        else
            cout<<"YOU HAVE NOT RETURNED THE LAST BOOK!";
        }
    }
          
	if(found==0)
        cout<<"\n\tSTUDENT RECORD NOT FOUND1";
        getch();
        system("cls");
    
        fp.close();
        fp1.close();
}

int fines()
{
	int day, fine=50;
	
	cout<<"\n\nBOOK RETURNED IN HOW MANY DAYS?: ";
    cin>>day;
                        
	if(day>15)
    {
        fine=(day-15)*fine;
        cout<<"\n\nYOU HAVE TO PAY A FINE OF:  "<< fine;
    }
                        
        return fine;
}

void book_return()
{
    system("cls");
    char sn[20],bn[20];
    int found=0, flag=0, day, fine=250;
    
    cout<<"\t\tRETURN BOOKS\n";
    cout<<"\n\n\tEnter STUDENT ID: ";
    cin>>sn;
    
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    
    while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
        if(strcmpi(st.get_ID_number(),sn)==0)
        {
            found=1;
            
			if(st.rettoken()==1)
            {
                while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
                {
                    if(strcmpi(bk.getbooknumber(),st.retstbno())==0)
                    {
                        bk.show_book();
                        flag=1;
						fines();
                        
                        st.resettoken();
                        int pos=-1*sizeof(st);
                        fp.seekp(pos,ios::cur);
                        fp.write((char*)&st,sizeof(student));
                        cout<<"\n\n\tBOOK RETURNED SUCCESSFULLY!";
                        stock+=1;
                    }
            	}
                
				if(flag==0)
                    cout<<"BOOK NUMBER NOT FOUND";
            }
                     
				else
            		cout<<"NO BOOK ISSUED!";
        }
    }
    
    if(found==0)
        cout<<"Student record not exist...";
        getch();
        system("cls");
        
  		fp.close();
  		fp1.close();
}

void book_menu()
{
    int option;
    
    cout<<"\n\t\tPress 1) CREATE BOOKS";
    cout<<"\n\t\tPress 2) DISPLAY ALL BOOKS";
    cout<<"\n\t\tPress 3) DISPLAY SPECIFIC BOOK";
    cout<<"\n\t\tPress 4) MODIFY BOOKS";
    cout<<"\n\t\tPress 5) DELETE BOOKS";
    cout<<"\n\t\tPress 6) BACK TO MAIN MENU";
 	cout<<"\t\tOption: ";
 	cin>>option;
 	
 	switch(option)
    {
                    
		case 1:  
			system("cls");
            write_book();
            break;
                               
		case 2: 
			display_allb();
            break;
                    
		
		case 3:
            
			char num[20];
            system("cls");
            cout<<"\n\n\tENTER BOOK NO: ";
            cin>>num;
            display_a_book(num);
            break;
            
        case 4: 
			modify_book();
			break;
                    
		case 5: 
			delete_book();
			break;
                    
		case 6: 
			system("cls");
            break;
            
        default:
			cout<<"\a";
    }
}

void student_menu()
{
    int option;
                
	cout<<"\n\t\tPress 1) CREATE STUDENT RECORD";
    cout<<"\n\t\tPress 2) DISPLAY ALL STUDENTS RECORD";
    cout<<"\n\t\tPress 3) DISPLAY SPECIFIC STUDENT RECORD";
    cout<<"\n\t\tPress 4) MODIFY STUDENT RECORD";
    cout<<"\n\t\tPress 5) DELETE STUDENT RECORD";
    cout<<"\n\t\tPress 6) BACK TO MAIN MENU";
 	cout<<"\n\n\tOption: ";
 	cin>>option;
 	
 	switch(option)
    {
        case 1:  
			system("cls");
            write_student();
            break;
            
        case 2: 
			system("cls");
            display_all_students();
            break;
                    
		case 3:
			
            char num[20];
            system("cls");
            cout<<"\n\n\tENTER STUDENT ID: ";
            cin>>num;
            display_a_student(num);
            break;
            
        case 4:
			system("cls");
            modify_student();
			break;
                    
		case 5: 
			system("cls");
            delete_student();
			break;
                
		case 6: 
            break;
                    
		default:
			cout<<"\a";
    }
}

int who()
{
	int t,t1;
	
	cout<<"\n\n\t\tPRESS 1) STUDENT\n\t\tPRESS 2) LIBRARIAN\n\t\tPRESS 3) ADMIN\n\n\t\tPRESS 4) EXIT\n\n\n\t\tENTER USER: ";
    cin>>t;
    system("cls");
    
    if(t==1)
	{
    	st.passwordforstudent();
	}
	
	else if(t==2)
	{
		li.passwordforlibrarian();
	}
	
	else if(t==3)
	{
		ad.passwordforAdmin();
	}
	
	else if(t==4)
	{
		exit(0);
	}
	
	else 
	{
		return 0;
	}
	
}

void intro()
{
    system("color 06");
    system("cls");
    cout << "\n\t\t\tWELCOME TO THE LIBRARY\n\n"; 
    who();
}

int main()
{   
    for(;;)
    {
        intro();
    }  
		
	return 0; 
}
