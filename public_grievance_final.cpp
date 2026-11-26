#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Citizen  
{
    string citizenname;
    int phone;
    string address;
    int citizenID;
    static int citizenCount;
    public:
    Citizen()
    {
        citizenID=citizenCount++;
    }
    Citizen(string name,int ph,string add)
    {
        citizenname=name;
        phone=ph;
        address=add;
    }
    void adduser()
    {
        cout<<"New user added successfully!"<<endl;
    }
    void modifyuser()
    {
        cout<<"User details modified successfully!"<<endl;
    }
    void display()
    {
        cout<<"Citizen ID: "<<citizenID<<endl;
        cout<<"Citizen Name: "<<citizenname<<endl;
        cout<<"Phone Number: "<<phone<<endl;
        cout<<"Address: "<<address<<endl;
    }
};
int Citizen::citizenCount=1;  
class Grievance : public Citizen  
{
    int grievanceID,choice,date,categoryID;
    static int grievancecount;
    string description,status,location,categoryname;
    public:
    Grievance()
    {
       grievanceID=grievancecount++;
    }
    Grievance(string descr,int d,string loc,int ch)
    {
        description=descr;
        date=d;
        location=loc;
        choice=ch;
    }
    void getgrievance()
    {
        
        switch(choice)
        {
            case 1:
            {
             categoryID=1001; 
             categoryname="Road";
             break;  
            }
            case 2:
            {
             categoryID=1002; 
             categoryname="Water supply";  
             break;  
            }
            case 3:
            {
             categoryID=1003;  
             categoryname="Drainage"; 
             break;  
            }
            case 4:
            {
             categoryID=1004;  
             categoryname="Sanitation"; 
             break;  
            }
            case 5:
            {
             categoryID=1005;  
                categoryname="Street Lights"; 
             break;  
            }
            case 6:
            {
             categoryID=1006;  
             categoryname="Waste Management"; 
             break;  
            }
            case 7:
            {
             categoryID=1007;  
                categoryname="Public Facilities"; 
             break;  
            }
            case 8:
            {
             categoryID=1008; 
                categoryname="Others";  
             break;  

             default:
                cout<<"Invalid choice"<<endl;
            }
        }
    }
    void viewstatus()
    {
     
    }

};
int Grievance::grievancecount=500;
int main()
{

    cout<<"Welcome to the Public Grievance Portal"<<endl;
    int choice;
    string name,address;
    int ph;
    
    do
    {
    cout<<"choose a process"<<endl;
    cout<<"1.Add a user\n2.Modify user details\n3.Search user\n4.Display\n5.Report a grievance\n6.Exit"<<endl;
    cin>>choice;
    cin.ignore();
    switch(choice)
    {
        case 1:
        {
            cout<<"==============================="<<endl;
            cout<<"Enter your name: ";
            getline(cin,name);
            cout<<"Enter your phone number: ";
            cin>>ph;
            cin.ignore();
            cout<<"Enter your address: ";
            getline(cin,address);
            cout<<"==============================="<<endl;
            ofstream file1;
            file1.open("citizen details.txt",ios::app);
            file1<<"Name : "<<name<<" Phone : "<<ph<<" Address : "<<address<<endl;
            file1.close();
            Citizen c1(name,ph,address);
            c1.adduser();
            break;
        }
        case 2:
        {
            cout<<"==============================="<<endl;
            cout<<"Enter your modified name: ";
            getline(cin,name);
            cout<<"Enter your modified phone number: ";
            cin>>ph;
            cin.ignore();
            cout<<"Enter your modified address: ";
            getline(cin,address);
            cout<<"==============================="<<endl;
            ofstream file1;
            file1.open("citizen details.txt",ios::app);
            file1<<"Name : "<<name<<" Phone : "<<ph<<" Address : "<<address<<endl;
            file1.close();
            Citizen c1(name,ph,address);
            c1.modifyuser();
            break;
        }
        case 3:
        {
            ifstream file1;
            file1.open("citizen details.txt");
            string line;
            cout<<"Enter your name to search: ";
            getline(cin,name);
            bool found=false;
            while(getline(file1,line))
            {
                if(line.find(name)!=string::npos)
                {
                    cout<<"User found: "<<line<<endl;
                    found=true;
                    break;
                }
            }
            if(!found)
            {
                cout<<"User not found"<<endl;
            }
            file1.close();
            break;
        }
        case 4:
        {
            Citizen c1(name,ph,address);
            c1.display();
            break;
        }
        case 5:
        {
        int choice,date;   
        string description,status,location;
            cout<<"\n\nChoose your category of grievance"<<endl;
            cout<<"1. Road\n2. Water supply\n3. Drainage\n4. Sanitation\n5. Street Lights\n6. Waste Management\n7. Public Facilities\n8. Others"<<endl;
            cout<<"\nEnter your choice: ";
            cin>>choice;
            cin.ignore();
            cout<<"Enter the description of your grievance  : "; 
            getline(cin,description);
            cout<<"Enter the location of your grievance  : ";
            getline(cin,location);
            cout<<"Enter the date of greivance (DD-MM-YYYY) : ";
            cin.ignore();
            cin>>date;
            ofstream file1;
            file1.open("citizen details.txt",ios::app);
            file1<<"Description : "<<description<<endl<<" Date : "<<date<<endl<<" Location : "<<location<<endl;
            file1.close();
            Grievance g1(description,date,location,choice);
            g1.getgrievance();
            break;
        }
        
    }
  }while(choice!=6);

    
    
    return 0;
}