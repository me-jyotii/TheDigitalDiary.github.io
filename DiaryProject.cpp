//<-------------------------------------------Project Diary------------------------------------------->
#include<iostream>
#include<fstream>
#include<process.h> //exit(0)  ;  //0 ---exit with success
#include<stdio.h>
#include<string.h>
using namespace std;

class Diary{
	
	//data members in class 'Diary'
	
	int sno;
	char personName[40];
	char nickName[30];
	char emailId[50];
	char relation[40];
	char phoneNumber[15];
	char mobileNumber[15];
	char address[100];
	char message[1000];
	char dateOfMessage[30];
	char dateOfBirth[30];
	
	//constructer of class "Diary"
	public:
	   void testcase()
	{
	
		char upass[20];
		ag:
		system("cls");
		cout<<"\nEnter passcode to open this digital diary :: ";
		cin>>upass;
		if(!strcmp(upass,"2021"))
			cout<<"Login success";
		else
			goto ag;	
		
	}	
		Diary()
		{
			strcpy(personName,"\0");
			strcpy(nickName,"");
			strcpy(emailId,"");
			strcpy(relation,"");
			strcpy(phoneNumber,"");
			strcpy(mobileNumber,"");
			strcpy(address,"");
			strcpy(message,"");
			strcpy(dateOfMessage,"");
			strcpy(dateOfBirth,"");
		}
		
		//defining setters and getters for data members in class 'Diary'
		
		//defining setters
		
		void setSerialNumber(int sno)
		{
			this->sno = sno;
		}
		
		void setPersonName(char *persoNname)
		{
			strcpy(this->personName,personName);
		}
		
		void setNickName(char *nickName)
		{
			strcpy(this->nickName,nickName);
		}
		
		void setEmailId(char *emailId)
		{
			strcpy(this->emailId,emailId);
		}
		void setRelation(char *relation)
		{
			strcpy(this->relation,relation);
		}
		void setPhoneNumber(char *phoneNumber)
		{
			strcpy(this->phoneNumber,phoneNumber);
		}
		void setMobileNumber(char *mobileNumber)
		{
			strcpy(this->mobileNumber,mobileNumber);
		}
		void setAddress(char *address)
		{
			strcpy(this->address,address);
		}
		void setMessage(char *message)
		{
			strcpy(this->message,message);
		}
		void setDateOfMessage(char *dateOfMessage)
		{
			strcpy(this->dateOfMessage,dateOfMessage);
		}
		void setDateOfBirth(char *dateOfBirth)
		{
			strcpy(this->dateOfBirth,dateOfBirth);
		}
		
		//defining getters
		
		
		int getSerialNumber()
		{
			return sno;
		}
		
		char* getPersonName()
		{
			return personName;
		}
		
		char* getNickName()
		{
			return nickName;
		}
		
		char* getEmailId()
		{
			return emailId;
		}
		
		char* getRelation()
		{
			return relation;
		}
		
		char* getPhoneNumber()
		{
			return phoneNumber;
		}
		
		char* getMobileNumber()
		{
			return mobileNumber;
		}
		
		char* getAddress()
		{
			return address;
		}
		
		char* getMessage()
		{
			return message;
		}
		
		char* getDateOfMessage()
		{
			return dateOfMessage;
		}
		
		char* getDateOfBirth()
		{
			return dateOfBirth;
		}
		
		
		//method for operations like setData, getData, searchData, modifyData, deleteData, find birthday
		void setData();
		void getData();
		void searchData();		
		void modifyData();
		void deleteData();
		void findDOB();
		void searchByName();
		void searchByMobileNumber();
		void searchByEmail();		
};

//setData()----with file handling

void Diary::setData()
{
	ofstream fout("Diary.dat",ios::app|ios::binary);
	
	cout<<"\nEnter person details in your Diary\n"<<endl;
	cout<<"\nEnter serial number :: ";
	cin>>sno;
	cout<<"\nEnter person name :: ";
	cin.ignore();
	cin.getline(personName,40);
	cout<<"\nEnter person nickname :: ";
	cin.getline(nickName,30);
	cout<<"\nEnter person email id :: ";
	cin.getline(emailId,50);
	cout<<"\nEnter person relation :: ";
	cin.getline(relation,40);
	cout<<"\nEnter person phone number :: ";
	cin.getline(phoneNumber,15);
	cout<<"\nEnter person mobile number :: ";
	cin.getline(mobileNumber,15);
	cout<<"\nEnter person address :: ";
	cin.getline(address,100);
	cout<<"\nEnter person message :: ";
	cin.getline(message,1000);
	cout<<"\nEnter person date of message :: ";
	cin.getline(dateOfMessage,30);
	cout<<"\nEnter person date of birth :: ";
	cin.getline(dateOfBirth,30);
	
	fout.write((char*)this,sizeof(*this));

    fout.close();
}
	
//getData()----with file handling
		
void Diary::getData()
{
	 //Diary.dat
	ifstream fin("Diary.dat",ios::in|ios::binary);
	
	while(fin.read((char*)this,sizeof(*this)))
	{
		cout<<"\n------Details of the person------\n"<<endl;
		cout<<"\nSno :: "<<sno<<endl;
		cout<<"\nName :: "<<personName<<endl;
		cout<<"\nNickname :: "<<nickName<<endl;
		cout<<"\nEmail id :: "<<emailId<<endl;
		cout<<"\nRelation :: "<<relation<<endl;
		cout<<"\nPhone number :: "<<phoneNumber<<endl;
		cout<<"\nMobile number :: "<<mobileNumber<<endl;
		cout<<"\nAddress :: "<<address<<endl;
		cout<<"\nMessage :: "<<message<<endl;
		cout<<"\nDate of message :: "<<dateOfMessage<<endl;
		cout<<"\nDate of birth :: "<<dateOfBirth<<endl;
	    system("pause");
	}
	
	fin.close();
}	



//searchData()----with file handling
		
void Diary:: searchData()
{
	int choice;
	cout<<"\n1_Search by name."<<endl;
	cout<<"\n2_Search by mobile number."<<endl;
	cout<<"\n3_Search by email id."<<endl;
	cout<<"\n\nEnter your choice :: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			searchByName();      
			break;
		case 2:
			searchByMobileNumber(); 
			break;
		case 3:
			searchByEmail(); 
			break;
		default:
		cout<<"\nEnter a valid input.";	
	}
}

//search by name

void Diary::searchByName()
{
	ifstream fin("Diary.dat",ios::in);
	
	char pname[40];
	bool f=false;
	cout<<"\nEnter person name to get its details :: ";
	cin.ignore();
	cin.getline(pname,40);
	
	while(fin.read((char*)this,sizeof(*this)))  //&stobj=current calling object----details of all the existing person
	{
		if( strcmp(pname, personName) == 0)
		{
		    cout<<"\nPerson details found in diary\n";
			cout<<"\nSno :: "<<sno<<endl;
			cout<<"\nName :: "<<personName<<endl;
			cout<<"\nNickname :: "<<nickName<<endl;
			cout<<"\nEmail id :: "<<emailId<<endl;
			cout<<"\nRelation :: "<<relation<<endl;
			cout<<"\nPhone number :: "<<phoneNumber<<endl;
			cout<<"\nMobile number :: "<<mobileNumber<<endl;
			cout<<"\nAddress :: "<<address<<endl;
			cout<<"\n~Message :: "<<message<<endl;
			cout<<"\nDate of message :: "<<dateOfMessage<<endl;
			cout<<"\nDate of birth :: "<<dateOfBirth<<endl;
			f=true;
			break;
		}
	}
	if(f==false)
	{
		cout<<"\nPerson details not found in diary";	
	}
	
	fin.close();
}

//search by mobile number

void Diary::searchByMobileNumber()
{
	ifstream fin("Diary.dat",ios::in);
	
	char phnNum[15];
	bool f=false;
	cout<<"\nEnter mobile number  to get its details :: ";
	cin.ignore();
	cin.getline(phnNum,15);
	
	while(fin.read((char*)this,sizeof(*this)))  //&stobj=current calling object----details of all the existing person
	{
		if( strcmp(phnNum, mobileNumber) == 0)
		{
		    cout<<"\nPerson details found in diary\n";
			cout<<"\nSno :: "<<sno<<endl;
			cout<<"\nName :: "<<personName<<endl;
			cout<<"\nNickname :: "<<nickName<<endl;
			cout<<"\nEmail id :: "<<emailId<<endl;
			cout<<"\nRelation :: "<<relation<<endl;
			cout<<"\nPhone number :: "<<phoneNumber<<endl;
			cout<<"\nMobile number :: "<<mobileNumber<<endl;
			cout<<"\nAddress :: "<<address<<endl;
			cout<<"\n~Message :: "<<message<<endl;
			cout<<"\nDate of message :: "<<dateOfMessage<<endl;
			cout<<"\nDate of birth :: "<<dateOfBirth<<endl;
			f=true;
			break;
		}
	}
	if(f==false)
	{
		cout<<"\nPerson details not found in diary";	
	}
	
	fin.close();
}

//search by email id
void Diary::searchByEmail()
{
	ifstream fin("Diary.dat",ios::in);
	
	char email[50];
	bool f=false;
	cout<<"\nEnter email id to get its details :: ";
	cin.ignore();
	cin.getline(email,50);
	
	while(fin.read((char*)this,sizeof(*this)))  //&stobj=current calling object----details of all the existing person
	{
		if( strcmp(email, emailId) == 0)
		{
		    cout<<"\nPerson details found in diary\n";
			cout<<"\nSno :: "<<sno<<endl;
			cout<<"\nName :: "<<personName<<endl;
			cout<<"\nNickname :: "<<nickName<<endl;
			cout<<"\nEmail id :: "<<emailId<<endl;
			cout<<"\nRelation :: "<<relation<<endl;
			cout<<"\nPhone number :: "<<phoneNumber<<endl;
			cout<<"\nMobile number :: "<<mobileNumber<<endl;
			cout<<"\nAddress :: "<<address<<endl;
			cout<<"\n~Message :: "<<message<<endl;
			cout<<"\nDate of message :: "<<dateOfMessage<<endl;
			cout<<"\nDate of birth :: "<<dateOfBirth<<endl;
			f=true;
			break;
		}
	}
	
	if(f==false)
	{
		cout<<"\nPerson details not found in diary";	
	}
	
	fin.close();
}

//modifyData()----with file handling	
	
void Diary::modifyData()
{
	//tempDiary---> updated data and old data--write
	ifstream fin("Diary.dat",ios::in); //reading from old file
	ofstream fout("tempDiaryDiary.dat",ios::out); //write updated and old file data
	char mob[15];
	bool f=false;
	cout<<"\nEnter mobile number to get existing person detail :: ";
	cin>>mob;
	
	while(fin.read((char*)this,sizeof(*this)))  //&stobj=current calling object---- details of all the existing person
	{
		if( strcmp(mob, mobileNumber) == 0)
		{
		    cout<<"\nPerson details found in diary\n";
			cout<<"\nSno :: "<<sno<<endl;
			cout<<"\nName :: "<<personName<<endl;
			cout<<"\nNickname :: "<<nickName<<endl;
			cout<<"\nEmail id :: "<<emailId<<endl;
			cout<<"\nRelation :: "<<relation<<endl;
			cout<<"\nPhone number :: "<<phoneNumber<<endl;
			cout<<"\nMobile number :: "<<mobileNumber<<endl;
			cout<<"\nAddress :: "<<address<<endl;
			cout<<"\n~Message :: "<<message<<endl;
			cout<<"\nDate of message :: "<<dateOfMessage<<endl;
			cout<<"\nDate of birth :: "<<dateOfBirth<<endl;
			
			//Now taking new inputs/ inserting modified data 
			
			cout<<"\nEnter person details in your Diary\n"<<endl;
			cout<<"\nEnter serial number :: ";
			cin>>sno;
			cout<<"\nEnter person name :: ";
			cin.ignore();
			cin.getline(personName,40);
			cout<<"\nEnter person nickname :: ";
			cin.ignore();
			cin.getline(nickName,30);
			cout<<"\nEnter person email id :: ";
			cin.ignore();
			cin.getline(emailId,50);
			cout<<"\nEnter person relation :: ";
			cin.ignore();
			cin.getline(relation,40);
			cout<<"\nEnter person phone number :: ";
			cin.ignore();
			cin.getline(phoneNumber,15);
			cout<<"\nEnter person mobile number :: ";
			cin.ignore();
			cin.getline(mobileNumber,15);
			cout<<"\nEnter person address :: ";
			cin.ignore();
			cin.getline(address,100);
			cout<<"\nEnter person message :: ";
			cin.ignore();
			cin.getline(message,1000);
			cout<<"\nEnter person date of message :: ";
			cin.ignore();
			cin.getline(dateOfMessage,30);
			cout<<"\nEnter person date of birth :: ";
			cin.ignore();
			cin.getline(dateOfBirth,30);
			
			fout.write((char*)this,sizeof(*this));
			f=true;
		}
		else
		{
			fout.write((char*)this,sizeof(*this));	
		}
	}
	
	if(f==false)
	{
		cout<<"\nPerson details not found in diary";	
	}
	
	fin.close();
	fout.close();	
	remove("Diary.dat");
	rename("tempDiary.dat","Diary.dat");
}
		
//	deleteData()------with file handling
	
void Diary::deleteData()
{
	ifstream fin("Diary.dat",ios::in); //reading from old file
	ofstream fout("tempDiary.dat",ios::out); //write updated and old file data
	char mob[15];
	bool f=false;
	cout<<"\nEnter mobile number to get existing person detail :: ";
	cin>>mob;
	char cv;
	while(fin.read((char*)this,sizeof(*this)))  //&stobj=current calling object-----details of all the existing person
	{
		if( strcmp(mob, mobileNumber) == 0)
		{
		    cout<<"\nPerson details found in diary\n";
			cout<<"\nSno :: "<<sno<<endl;
			cout<<"\nName :: "<<personName<<endl;
			cout<<"\nNickname :: "<<nickName<<endl;
			cout<<"\nEmail id :: "<<emailId<<endl;
			cout<<"\nRelation :: "<<relation<<endl;
			cout<<"\nPhone number :: "<<phoneNumber<<endl;
			cout<<"\nMobile number :: "<<mobileNumber<<endl;
			cout<<"\nAddress :: "<<address<<endl;
			cout<<"\n~Message :: "<<message<<endl;
			cout<<"\nDate of message :: "<<dateOfMessage<<endl;
			cout<<"\nDate of birth :: "<<dateOfBirth<<endl;
			
			//make sure for one more time
			cout<<"\nDo you want delete this person details y/n :";
			cin.ignore();
			cin>>cv;
				
			//Object---(update data)=memory----transter into file(write)
			if(cv!='y')
				fout.write((char*)this,sizeof(*this));
			f=true;
		}
		else
		{
			fout.write((char*)this,sizeof(*this));	
		}
	}
	
	if(f==false)
	{
		cout<<"\nPerson details not found in diary";
	}
	
	fin.close();
	fout.close();	
	
	remove("Diary.dat");
	rename("tempDiary.dat","Diary.dat");
}

int main()
{
	//ofstream fout("Diary.dat",ios::out);
	int ich;
	Diary dobj;
	
		dobj.testcase();
	
	
	 while(true)
	 {
	 	system("cls");
			cout<<"\n1.Input";
			cout<<"\n2.show";
			cout<<"\n3.search";
			cout<<"\n4.update";
			cout<<"\n5.delete";
			cout<<"\nEnter Your choice:";
			cin>>ich;
			system("cls");
			switch(ich)
			{
				case 1:
					dobj.setData(); //internally file handling
				break;
				case 2:
					dobj.getData();
				break;
				case 3:
					dobj.searchData();
				break;
				case 4:
					dobj.modifyData();
				break;
				case 5:
					dobj.deleteData();
				break;
				case 6:
					exit(0); //terminate program/exit from main
				default:
					printf("Wrong choice");
			}     				 
		cout<<endl;
		system("pause");
	 }
	return 0;
}

















