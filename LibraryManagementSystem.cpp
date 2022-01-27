// cout<<"Name: Khushi"<<endl;

// Using C++, WAP of a Library Management Systems with the concepts of File Handling. 
// It must Allow the Library to Manage the records of Issues and Deposits of Books and 
// Add, Retrieve, and update Details of any Student or Book.
// The basic features the library management system must include are:
// •	Admin Access
// Create Separate Records/files for Students and Books
// 	In Students File, store: Student Name, Admission Number, Class, No of Books Issued.
// 	In Books File, store: Book Number, Author name, Book Title, Domain, Edition and No of 
//     Copies Available.
// The admin has access to:
// 	Add new Student and Book records.
// 	Modify any Student or Book record.
// 	Delete any Student or Book record.
// 	View any Specific or Whole Student record and Book record.
// •	Book Issue: Used at time of Issuing A book. Takes in input as Book Number and 
//     Issuer’s Admission number, issue date. Adds that detail to the student record that 
//     the specific Student has issued a book. Create a file which stores this record of Book Issue.
// •	Book Deposit: When Student returns the book, it uses student Admission Number and Book Number 
//     to modify the record of Book issued by the student. Create a file which stores this record of 
//     Book Deposit.
// Note: A book Cannot be issued if there are no more copies available and a student can only issue 
//     1 copy of a book and at max 3 books at a time.
//     A book can only be issued for 15 days at once. After that it needs to be re-issued. If the book 
//     is deposited after 15 days of issue, a fine is imposed on per day basis.

// Note: A book Cannot be issued if there are no more copies available and a student can only issue 1 
//     copy of a book and at max 3 books at a time.

#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
using namespace std;

class book{
    char bno[6];
    char bname[50];
    char aname[20];
    char domain[10];
    int edition;
    int copies;

    public:
    void createbook(){
        system("CLS");
        cout<< "\t\tNEW BOOK ENTRY" <<endl;
        cout<< "Book Number: " ;
        cin>> bno ;
        fflush(stdin);
        getch();
        cout<< "Book Title: ";
        gets(bname);
        cout<< "Author's Name: ";
        gets(aname);
        cout<< "Domain: ";
        cin>>domain;
        cout<< "Edition: ";
        cin>>edition;
        cout<< "Copies: ";
        cin>>copies;
        cout<< "\t\tNEW BOOK CREATED!"<<endl;
    }

    void showbook(){
        cout<<"\n\nBook No: "<<bno<<endl;
        cout<<"Book Title: ";
        puts(bname);
        cout<<endl<<"Author's Name: ";
        puts(aname);
        cout<<endl<<"Domain: "<<domain<<endl;
        cout<<"Edition: "<<edition<<endl;
    }

    void modifybook(){
        cout<<"\nBook Number: "<<bno<<endl;
        fflush(stdin);
        getch();
        cout<<"Modify Book Title: ";
        gets(bname);
        cout<<"Modify Author's Name: ";
        gets(aname);
        cout<< "Domain: ";
        cin>>domain;
        cout<< "Edition: ";
        cin>>edition;
        cout<< "Copies: ";
        cin>>copies;
    }

    char* retbno(){
        return bno;
    }

    void breport(){
        cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<setw(30)<<domain<<setw(30)<<edition<<endl;
    }
};

class student{
    char admno[6];
    char sname[20];
    char stbno[6];
    int sclass;
    int booksissued;

    public:
    void createstudent(){
        system("CLS");
        cout<< "\t\tNEW STUDENT ENTRY" <<endl;
        cout<< "Admission Number: " ;
        cin>> admno ;
        fflush(stdin);
        getch();
        cout<< "Student Name: ";
        gets(sname);
        cout<<"Student Class: ";
        cin>>sclass;
                booksissued=0;
        stbno[0]='\0';
        cout<< "\t\tNEW RECORD CREATED!"<<endl;
    }

    void showstudent(){
        cout<<"\n\nAdmission Number: "<<admno<<endl;
        cout<<"Student Name: ";
        puts(sname);
        cout<<endl<<"Student Class: "<<sclass<<endl;
        cout<<"No. of Books Issued: "<<booksissued<<endl;
        if(booksissued==1){
            cout<<"Book Number: "<<stbno<<endl;
        }
    }

    void modifystudent(){
        cout<<"\nAdmission Number: "<<admno<<endl;
        fflush(stdin);
        getch();
        cout<<"Modify Student Name: ";
        gets(sname);
        cout<< "Student Class: ";
        cin>>sclass;
    }

    char* retadmno(){
        return admno;
    }

    char* retstbno(){
        return stbno;
    }

    int retbi(){
        return booksissued;
    }

    void addbook(){
        booksissued=1;
    }

    void resetbook(){
        booksissued=0;
    }

    void getstbno(char t[]){
        strcpy(stbno,t);
    }
    
    void sreport(){
        cout<<"\t   "<<admno<<setw(16)<<sname<<setw(10)<<sclass<<setw(20)<<booksissued<<endl;
    }
};

fstream fp,fp1;
book bk;
student st;

void writebook(){
    char ch;
    fp.open("book.dat",ios::out|ios::app);
    do{
        system("CLS");
        bk.createbook();
        fp.write((char*)&bk,sizeof(book));
        cout<<"\nAdd more book (y/n): ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}

void writestudent(){
    char ch;
    fp.open("student.dat",ios::out|ios::app);
    do{
        system("CLS");
        st.createstudent();
        fp.write((char*)&st,sizeof(student));
        cout<<"\nAdd more student (y/n): ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}

void specificbook(char n[]){
    cout<<"\nBOOK DETAILS"<<endl;
    int flag=0;
    fp.open("book.dat",ios::in);
    while(fp.read((char*)&bk,sizeof(book))){
        if(strcmpi(bk.retbno(),n)==0){
            bk.showbook();
            flag=1;
        }
    }
    fp.close();
    if(flag==0){
        cout<<"Book does not exist!"<<endl;
    }
    getch();
}

void specificstudent(char n[]){
    cout<<"\nSTUDENT DETAILS"<<endl;
    int flag=0;
    fp.open("student.dat",ios::in);
    while(fp.read((char*)&st,sizeof(student))){
        if(strcmpi(st.retadmno(),n)==0){
            st.showstudent();
            flag=1;
        }
    }
    fp.close();
    if(flag==0){
        cout<<"Student does not exist!"<<endl;
    }
    getch();
}

void modifybook(){
    char n[6];
    int flag=0;
    system("CLS");
    cout<<"\nMODIFY BOOK RECORD"<<endl;
    cout<<"Enter Book No.: ";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&bk,sizeof(book)) && flag==0){
        if(strcmpi(bk.retbno(),n)==0){
            bk.showbook();
            cout<<"\nEnter Modified Details: "<<endl;
            bk.modifybook();
            int pos = -1*sizeof(bk);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&bk,sizeof(book));
            cout<<"\nRecord Updated!"<<endl;
            flag=1;
        }
    }
    fp.close();
    if(flag==0){
        cout<<"\nBook does not exist!"<<endl;
    }
    getch();
}


void modifystudent(){
    char n[6];
    int flag=0;
    system("CLS");
    cout<<"\nMODIFY STUDENT RECORD"<<endl;
    cout<<"Enter Admission No.: ";
    cin>>n;
    fp.open("student.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && flag==0){
        if(strcmpi(st.retadmno(),n)==0){
            st.showstudent();
            cout<<"\nEnter Modified Details: "<<endl;
            st.modifystudent();
            int pos = -1*sizeof(bk);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&st,sizeof(student));
            cout<<"\nRecord Updated!"<<endl;
            flag=1;
        }
    }
    fp.close();
    if(flag==0){
        cout<<"\nStudent does not exist!"<<endl;
    }
    getch();
}

void deletestudent(){
    char n[6];
    int flag=0;
    system("CLS");
    cout<<"\nDELETE STUDENT RECORD"<<endl;
    cout<<"Enter Admission No.: ";
    cin>>n;
    fp.open("student.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("temp1.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&st,sizeof(student)) && flag==0){
        if(strcmpi(st.retadmno(),n)!=0){
            fp2.write((char*)&st,sizeof(student));
        }
        else{
            flag=1;
        }
    }
    fp2.close();
    fp.close();
    remove("student.dat");
    rename("temp1.dat","student.dat");

    if(flag==1){
        cout<<"\nRecord Deleted!"<<endl;
    }else{
        cout<<"\nRecord does not exit"<<endl;
    }
    getch();
}

void deletebook(){
    char n[6];
    int flag=0;
    system("CLS");
    cout<<"\nDELETE BOOK RECORD"<<endl;
    cout<<"Enter Book No.: ";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&bk,sizeof(book)) && flag==0){
        if(strcmpi(bk.retbno(),n)!=0){
            fp2.write((char*)&bk,sizeof(book));
        }
        else{
            flag=1;
        }
    }
    fp2.close();
    fp.close();
    remove("book.dat");
    rename("temp.dat","book.dat");

    if(flag==1){
        cout<<"\nRecord Deleted!"<<endl;
    }else{
        cout<<"\nRecord does not exit"<<endl;
    }
    getch();
}

void displayallstudent(){
    system("CLS");
    fp.open("student.dat",ios::in);
    if(!fp){
        cout<<"File cannot be accessed!"<<endl;
        getch();
        return;
    }
    cout<<"\t\t\tSTUDENT LIST"<<endl<<endl;
     cout<<"\t"<<"Admission No."<<setw(10)<<"Name"<<setw(10)<<"class"<<setw(20)<<"Books Issued"<<endl;

    while(fp.read((char*)&st,sizeof(student))){
        st.sreport();
    }

    fp.close();
    getch();
}

void displayallbook(){
    system("CLS");
    fp.open("book.dat",ios::in);
    if(!fp){
        cout<<"File cannot be accessed!"<<endl;
        getch();
        return;
    }
    cout<<"\t\t\tBOOK LIST"<<endl<<endl;
    cout<<"Book No."<<setw(30)<<"Title"<<setw(30)<<"Author"<<setw(30)<<"Domain"<<setw(30)<<"Edition"<<endl;

    while(fp.read((char*)&bk,sizeof(book))){
        bk.breport();
    }

    fp.close();
    getch();
}

void bookissue(){
    char sn[6],bn[6];
    int sflag=0,bflag=0;
    system("CLS");
    cout<<"\t\tBOOK ISSUE"<<endl;
    cout<<"Enter Admission No.: ";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student))&&sflag==0){
        if(strcmpi(st.retadmno(),sn)==0){
            sflag=1;
            if(st.retbi()==0){
                cout<<"Enter Book No.: ";
                cin>>bn;
                while(fp1.read((char*)&bk,sizeof(book))&&bflag==0){
                    if(strcmpi(bk.retbno(),bn)==0){
                        bflag=1;
                        st.addbook();
                        st.getstbno(bk.retbno());
                        int pos=-1*sizeof(st);
                        fp.seekg(pos,ios::cur);
                        fp.write((char*)&st,sizeof(student));
                        cout<<"Book Issued Successfuly!"<<endl;
                    }
                }
                if(bflag==0){
                    cout<<"Invalid Book Number!"<<endl;
                }
            }else{
                cout<<"Book not returned by student!"<<endl;
            }
        }
    }
    if(sflag==0){
        cout<<"Invalid Admission Number!"<<endl;
    }
    getch();
    fp.close();
    fp1.close();
}

void bookdeposit(){
    char sn[6],bn[6];
    int sflag=0,bflag=0,day,fine;
    system("CLS");
    cout<<"\t\tBOOK DEPOSIT"<<endl;
    cout<<"Enter Admission No.: ";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student))&&sflag==0){
        if(strcmpi(st.retadmno(),sn)==0){
            sflag=1;
            if(st.retbi()==0){
                cout<<"Enter Book No.: ";
                cin>>bn;
                while(fp1.read((char*)&bk,sizeof(book))&&bflag==0){
                    if(strcmpi(bk.retbno(),st.retstbno())==0){
                        bflag=1;
                        bk.showbook();
                        cout<<"\nBook Deposited in no. of days: ";
                        cin>>day;
                        if(day>15){
                            fine=(day-15)*1;
                            cout<<"Fine: "<<fine<<endl;
                        }
                        st.resetbook();
                        int pos=-1*sizeof(st);
                        fp.seekg(pos,ios::cur);
                        fp.write((char*)&st,sizeof(student));
                        cout<<"Book Deposited Successfuly!"<<endl;
                    }
                }
                if(bflag==0){
                    cout<<"Invalid Book Number!"<<endl;
                }
            }else{
                cout<<"No Book is issued to student!"<<endl;
            }
        }
    }
    if(sflag==0){
        cout<<"Invalid Admission Number!"<<endl;
    }
    getch();
    fp.close();
    fp1.close();
}

void pass(int x){
	int i = 0;
	char ch, st[21], ch1[21] = {"password"};
	cout << "\n\t\tEnter Password : ";
	while (1)
	{
		ch = getch();
		if (ch == 13)
		{
			st[i] = '\0';
			break;
		}
		else if (ch == 8 && i > 0)
		{
			i--;
			cout << "\b \b";
		}
		else
		{
			cout << "*";
			st[i] = ch;
			i++;
		}
	}
	ifstream inf("password.txt");
	inf >> ch1;
	inf.close();
	for (i = 0; st[i] == ch1[i] && st[i] != '\0' && ch1[i] != '\0'; i++)
		;
	if (st[i] == '\0' && ch1[i] == '\0')
	{
		system("cls");
        if(x==1){
            bookissue();
        }else if(x==2){
            bookdeposit();
        }
	}
	else
	{
		cout << "\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
		getch();
		system("cls");
	}
}

void password()
{
	int i = 0, j = 0;
	char ch, st[21], ch1[21] = {"password"};
	system("cls");
	cout << "\n\n\t\tEnter Old Password : ";
	while (1)
	{
		ch = getch();
		if (ch == 13)
		{
			st[i] = '\0';
			break;
		}
		else if (ch == 8 && i > 0)
		{
			i--;
			cout << "\b \b";
		}
		else
		{
			cout << "*";
			st[i] = ch;
			i++;
		}
	}
	ifstream intf("password.txt");
	intf >> ch1;
	intf.close();
	for (i = 0; st[i] == ch1[i] && st[i] != '\0' && ch1[i] != '\0'; i++)
		;
	if (st[i] == '\0' && ch1[i] == '\0')
	{
		system("cls");
		cout << "\n\t**The Password Should be less than 20 characters & don't use spaces**\n\n";
		cout << "\n\t\tEnter New Password : ";
		fflush(stdin);
		i = 0;
		while (1)
		{
			j++;
			ch = getch();
			if (ch == 13)
			{
				for (i = 0; st[i] != ' ' && st[i] != '\0'; i++)
					;
				if (j > 20 || st[i] == ' ')
				{
					cout << "\n\n\t\tYou did't follow the instruction \n\n\t\tPress any key for try again.....";
					getch();
					system("cls");
					password();
					return;
				}
				st[i] = '\0';
				break;
			}
			else if (ch == 8 && i > 0)
			{
				i--;
				cout << "\b \b";
			}
			else
			{
				cout << "*";
				st[i] = ch;
				i++;
			}
		}
		ofstream outf("password.txt");
		outf << st;
		outf.close();
		cout << "\n\n\t\tYour Password has been changed Successfully.";
		cout << "\n\t\tPress any key to continue......";
		getch();
		system("cls");
		return;
	}
	else
	{
		cout << "\n\n\t\tPassword is incorrect.....\n";
		cout << "\n\t\tEnter 1 for retry or 2 for menu";
		cin >> i;
		if (i == 1)
		{
			system("cls");
			password();
		}
		else
		{
			system("cls");
			return;
		}
	}
}

void start(){
    system("CLS");
    cout<<"\t\t\tLIBRARY"<<endl;
    cout<< "\t\t       MANAGEMENT" <<endl;
    cout<< "\t\t\tSYSTEM" <<endl<<endl;

    cout<<"\t\t\t\tBy: Khushi";
    
    getch();
}

void adminmenu(){
    system("CLS");
    int ch;
    cout<< "\t\tADMINISTRATOR MENU" <<endl;
    cout<< "1. CREATE STUDENT RECORD" <<endl;
    cout<< "2. DISPLAY ALL STUDENTS RECORD" <<endl;
    cout<< "3. DISPLAY SPECIFIC STUDENT RECORD" <<endl;
    cout<< "4. MODIFY SPECIFIC STUDENT RECORD" <<endl;
    cout<< "5. DELETE SPECIFIC STUDENT RECORD" <<endl;
    cout<< "6. CREATE BOOK RECORD" <<endl;
    cout<< "7. DISPLAY ALL BOOKS RECORD" <<endl;
    cout<< "8. DISPLAY SPECIFIC BOOK RECORD" <<endl;
    cout<< "9. MODIFY SPECIFIC BOOK RECORD" <<endl;
    cout<< "10. DELETE SPECIFIC BOOK RECORD" <<endl;
    cout<< "11. CHANGE PASSWORD" <<endl;
    cout<< "12. MAIN MENU" <<endl;
    cout<< "Enter your choice: " ;
    cin>> ch ;
    switch (ch)
    {
    case 1:
       writestudent();
        break;
    case 2:
       displayallstudent();
        break;
    case 3:
        char num_s[6];
        system("CLS");
        cout<< "Enter Admission Number: ";
        cin>>num_s;
       specificstudent(num_s);  
        break;
    case 4:
        modifystudent();
        break;
    case 5:
        deletestudent();
        break;
    case 6:
       writebook();
        break;
    case 7:
       displayallbook();
        break;
    case 8:
        char num_b[6];
        system("CLS");
        cout<< "Enter Book Number: ";
        cin>>num_b;
       specificbook(num_b);
        break;
    case 9:
        modifybook();
        break;
    case 10:
        deletebook();
        break;
    case 11:
        password();
        break;
    case 12:
        return;
    
    default:
        cout<< "Invalid Choice!" <<endl;
        break;
    }
    
}

int main(){
    int ch;
    start();

    do{
        system("CLS");
        cout<< "\t\t\tMAIN MENU" <<endl;
        cout<< "1. BOOK ISSUE" <<endl;
        cout<< "2. BOOK DEPOSIT" <<endl;
        cout<< "3. ADMINISTRATOR MENU" <<endl;
        cout<< "4. EXIT" <<endl;
        cout<< "Enter your choice: " ;
        cin>>ch;
        
        switch(ch){
            case 1 :
            pass(1);
            break;

            case 2 :
            pass(2);
            break;

            case 3 : 
            adminmenu(); 
            break;

            case 4 :
            exit(0);
            break;

            default: 
            cout<< "Invalid Choice" <<endl;
            
        }
        
    }while(ch!=4);

    return 0;
}