#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <sstream>
#include <climits>
using namespace std;
#define RESET "\033[0m"
#define RED "\033[31m"
#define CYAN "\033[36m"

vector<string>Agents;
int totalagents;

int isInt(int n1, int n2);
string getTime();
string getTime1();

class registry
{
private:
    string name;
    int age;
    string address;
    string phone;
    string password;
public:
    void set1(int n);
};

int getTime2();
string getTime3(int n);
string getTime4(int n);
string getTime5(int time);
long long int getTime6(int n, int n1);
string getTime7(long long int n);
void adminMenu();
void agentMenu();
void buyTicket();
void addRoute(string);
void deleteRoute(string);
void addCoach(string);
void deleteCoach(string);
void busDetails();
void addNotice(string);
void deleteHistory();
int main()
{
    ifstream File4("admin.txt");
    if(!File4)
    {
        ofstream File5("admin.txt");
        File5<<"1234"<<endl;
    }

    ifstream File6("advanceBooking.txt");
    if(!File4)
    {
        ofstream File7("advanceBooking.txt");
        File7<<"0"<<endl;
    }

    ofstream File8("agents.txt", ios::app);
    ifstream File9("balance.txt");

    if(!File9)
    {
        ofstream File10("balance.txt");
        File10<<"0"<<endl;
    }

    ofstream File11("coach.txt", ios::app);
    ofstream File12("history.txt", ios::app);
    ofstream File13("notice.txt", ios::app);

    string temp,cdate,ctime;
    int temp1,k;
    vector<string>coach;
    ifstream open("coach.txt");
    while(getline(open,temp))
    {
        coach.push_back(temp);
    }
    for(int i=0; i<coach.size(); i=i+2)
    {
        ofstream File1("Travel_"+coach[i]+".txt",ios::app);
        ofstream File2("vehicle_control_"+coach[i]+".txt",ios::app);
        ofstream File3("vehicle_"+coach[i]+".txt",ios::app);
        int seatCount;
        int busCount=0;
        ifstream file5("vehicle_"+coach[i]+".txt");
        if(file5)
        {
            while(file5>>temp1)
            {
                busCount=busCount+temp1;
            }
        }
        string cdate=getTime()+"_"+coach[i]+".txt";
        stringstream ss(coach[i+1]);
        ss>>seatCount;
        ifstream file(cdate);
        if(!file)
        {
            string cdate1;
            for(int j=1; j<=365; j++)
            {
                cdate1=getTime4(j)+"_"+coach[i]+".txt";
                ifstream file1(cdate1);
                if(file1)
                {
                    file1.close();
                    remove(cdate1.c_str());
                }
            }
            ofstream new_file(cdate);
            for(k=0; k<busCount*seatCount; k++)
            {
                new_file<<"0"<<endl;
            }
            new_file.close();
        }
        else
        {
            string cdate1;
            for(int j=1; j<=365; j++)
            {
                cdate1=getTime4(j)+"_"+coach[i]+".txt";
                ifstream file1(cdate1);
                if(file1)
                {
                    file1.close();
                    remove(cdate1.c_str());
                }
            }
        }

    }
    ifstream adminPass("admin.txt");
    string admin;
    getline(adminPass,admin);
    int choice;
    int choice1;
    int choice2;
    totalagents=0;
    string counter;
    ifstream agent("agents.txt");
    while(getline(agent,counter))
    {
        Agents.push_back(counter);
        totalagents++;
    }
    agent.close();

    cout << "1.Log in \n2.Buy Ticket \n3.Bus Details \n4.Notice \n5.End program" << endl;
    do
    {
        cout << RED<<"Main Menu "<<RESET<<"- Enter your choice : ";
        choice=isInt(1,5);
        switch (choice)
        {
        case 1:
        {
            cout<<"1.Administrator 2.Agent "<<endl;
            cout<<"Enter your choice : ";
            choice1=isInt(1,2);
            switch(choice1)
            {
            case 1:
            {
                cout<<"Enter admin passcode :";
                getline(cin,temp);
                if(temp==admin)
                {
                    cout<<endl<<"Welcome admin"<<endl<<endl;
                    adminMenu();
                    bool ad=true;
                    while(ad)
                    {
                        cout<<endl<<CYAN<<"Admin"<<RESET<<" - Enter your choice : ";
                        choice2=isInt(1,15);
                        switch(choice2)
                        {
                        case 1:
                        {
                            ifstream history("history.txt");
                            while(getline(history,temp))
                            {
                                cout<<temp<<endl;
                            }
                        }
                        break;
                        case 2:
                        {
                            cout<<"Enter limit of advance booking ( max: 365 days ) :";
                            temp1=isInt(0,365);
                            ofstream file("advanceBooking.txt");
                            file<<temp1;
                            cout<<"Completed"<<endl;
                            if(temp1==0)
                            {
                                cout<<"Advance booking is stopped "<<endl;
                            }
                            else
                            {
                                cout<<"Now ticket can be booked from "<<temp1<<" days ago"<<endl;
                            }
                        }
                        break;
                        case 3:
                        {
                            addRoute("Admin");

                        }
                        break;

                        case 4:
                        {
                            addNotice("Admin");
                        }
                        break;
                        case 5:
                        {
                            int i=0;
                            int count=1;
                            ifstream agent("agents.txt");
                            while(getline(agent,temp))
                            {
                                if(temp=="#9ount99#+ted#999#Acc+#99dele9#")
                                {
                                    cout<<endl<<"Agent no "<<count<<" : "<<endl<<endl;
                                    cout<<"Deleted account "<<endl;
                                    count++;
                                    for(int j=0; j<4; j++)
                                    {
                                        getline(agent,temp);
                                    }
                                    continue;
                                }
                                if(i%5==0)
                                {
                                    cout<<endl<<"Agent no "<<count<<" : "<<endl<<endl;
                                    count++;
                                    cout<<"Agent's id       : "<<temp<<endl;
                                }
                                else if(i%5==1)
                                {
                                    cout<<"Agent's name     : "<<temp<<endl;
                                }
                                else if(i%5==2)
                                {
                                    cout<<"Agent's age      : "<<temp<<endl;
                                }
                                else if(i%5==3)
                                {
                                    cout<<"Agent's address  : "<<temp<<endl;
                                }
                                else if(i%5==4)
                                {
                                    cout<<"Agent's password : "<<temp<<endl;
                                }
                                i++;
                            }
                        }
                        break;
                        case 6:
                        {
                            cout<<"Enter new admin passcode :";
                            getline(cin,temp);
                            ofstream file("admin.txt");
                            file<<temp;
                            file.close();
                            temp.clear();
                            cout<<CYAN<<"Admin passcode is updated successfully "<<RESET<<endl;
                        }
                        break;
                        case 7:
                        {
                            addCoach("Admin");
                        }
                        break;
                        case 8:
                        {
                            deleteRoute("Admin");
                        }
                        break;
                        case 9:
                        {
                            long long int balance;
                            long long withdraw;
                            ifstream file("balance.txt");
                            file>>balance;
                            cout<<"Current Balance :"<<balance<<endl;
                            cout<<"Enter amount to withdraw :";
                            withdraw=isInt(0,balance);
                            balance=balance-withdraw;
                            ofstream file1("balance.txt");
                            file1<<balance;
                            ofstream file2("history.txt",ios::app);
                            cdate=getTime();
                            ctime=getTime1();
                            file2<<"On "<<ctime<<"  "<<cdate<<endl<<withdraw<<"Tk is withdrawn by admin"<<endl;
                            file2<<"Current balance : "<<balance<<"Tk"<<endl<<endl;
                            cout<<withdraw<<"Tk is withdrawn successfully "<<endl;
                        }
                        break;
                        case 10:
                        {
                            adminMenu();
                        }
                        break;
                        case 11:
                        {
                            deleteCoach("Admin");
                        }
                        break;
                        case 12:
                        {
                            deleteHistory();

                        }
                        break;
                        case 13:
                        {
                            bool b=false;
                            cout<<"Enter Agents's Id :";
                            getline(cin,temp);
                            for(int i=0; i<Agents.size(); i=i+5)
                            {
                                if(Agents[i]==temp)
                                {
                                    b=true;
                                    ofstream file1("history.txt",ios::app);
                                    cdate=getTime();
                                    ctime=getTime1();
                                    file1<<"On "<<ctime<<" "<<cdate<<endl;
                                    file1<<"An agent was removed "<<endl<<"Agent's id : "<<temp<<endl<<endl;
                                    Agents[i]="#9ount99#+ted#999#Acc+#99dele9#";
                                    ofstream file("agents.txt");
                                    for(int i=0; i<Agents.size(); i++)
                                    {
                                        file<<Agents[i]<<endl;
                                    }
                                    cout<<"Account is deleted "<<endl;
                                    break;
                                }
                            }
                            if(b==false)
                            {
                                cout<<"Account is not found "<<endl;
                            }
                        }
                        break;
                        case 14:
                        {
                            ad=false;
                        }
                        break;
                        case 15:
                        {
                            registry obj;
                            obj.set1(totalagents/5);
                        }
                        break;
                        default:
                            cout<<"Invalid input"<<endl;
                        }
                    }
                }
                else
                {
                    cout<<"Wrong password"<<endl;
                }
            }
            break;
            case 2:
            {
                int agentIndex;
                bool b1=false;
                bool b2=false;
                int i;
                string password;
                cout<<"Enter Agent's Id :";
                getline(cin,temp);
                for(i=0; i<Agents.size(); i=i+5)
                {
                    if(Agents[i]==temp)
                    {
                        agentIndex=i;
                        b1=true;
                        cout<<"Enter your password :";
                        getline(cin,password);
                        if(password==Agents[i+4])
                        {
                            cout<<endl<<"Welcome "<<Agents[i+1]<<endl;
                            b2=true;
                        }
                        else
                        {
                            cout<<"Wrong password "<<endl;
                        }
                        break;
                    }
                }
                if(b2==true)
                {
                    bool b3=true;
                    int choice;
                    agentMenu();
                    while(b3)
                    {
                        cout<<CYAN<<"Agent "<<RESET<<"- enter your choice :";
                        choice=isInt(1,10);
                        cout<<endl;
                        switch(choice)
                        {
                        case 1:
                        {
                            addCoach( Agents[agentIndex] );
                        }
                        break;
                        case 2:
                        {
                            deleteCoach( Agents[agentIndex] );
                        }
                        break;
                        case 3:
                        {
                            addRoute( Agents[agentIndex] );
                        }
                        break;
                        case 4:
                        {
                            deleteRoute( Agents[agentIndex] );
                        }
                        break;
                        case 5:
                        {
                            agentMenu();
                        }
                        break;
                        case 6:
                        {
                            cdate=getTime();
                            ctime=getTime1();
                            ofstream file1("history.txt",ios::app);
                            file1<<"On "<<ctime<<"  "<<cdate<<" An agent updated his/her details"<<endl;
                            file1<<"Agent's id : "<<Agents[agentIndex]<<endl;
                            cout<<"Enter new name :";
                            getline(cin,temp);
                            file1<<"Old name :"<<Agents[agentIndex+1]<<endl<<"New name : "<<temp<<endl;
                            Agents[agentIndex+1]=temp;
                            cout<<"Enter new age :";
                            getline(cin,temp);
                            file1<<"Old age  :"<<Agents[agentIndex+2]<<endl<<"New age  : "<<temp<<endl;
                            Agents[agentIndex+2]=temp;
                            cout<<"Enter new address :";
                            getline(cin,temp);
                            file1<<"Old address :"<<Agents[agentIndex+3]<<endl<<"New address : "<<temp<<endl<<endl;
                            Agents[agentIndex+3]=temp;
                            cout<<"Enter new password :";
                            getline(cin,temp);
                            Agents[agentIndex+4]=temp;
                            cout<<"Updated details :"<<endl;
                            cout<<"Id       :"<<Agents[agentIndex]<<endl;
                            cout<<"Name     :"<<Agents[agentIndex+1]<<endl;
                            cout<<"Age      :"<<Agents[agentIndex+2]<<endl;
                            cout<<"Address  :"<<Agents[agentIndex+3]<<endl;
                            cout<<"Password :"<<Agents[agentIndex+4]<<endl<<endl;
                            ofstream file("agents.txt");
                            for(int i=0; i<Agents.size(); i++)
                            {
                                file<<Agents[i]<<endl;
                            }
                        }
                        break;
                        case 7:
                        {
                            ifstream history("history.txt");
                            while(getline(history,temp))
                            {
                                cout<<temp<<endl;
                            }
                        }
                        break;
                        case 8:
                        {
                            b3=false;
                        }
                        break;
                        case 9:
                        {
                            addNotice(Agents[agentIndex]);
                        }
                        break;
                        case 10:
                        {
                            cout<<"Enter limit of advance booking ( max: 365 days ) :";
                            temp1=isInt(0,365);
                            ofstream file("advanceBooking.txt");
                            file<<temp1;
                            cout<<"Completed"<<endl;
                            if(temp1==0)
                            {
                                cout<<"Advance booking is stopped "<<endl;
                            }
                            else
                            {
                                cout<<"Now ticket can be booked from "<<temp1<<" days ago"<<endl;
                            }
                        }
                        break;
                        default:
                            cout<<"Invalid choice "<<endl;
                        }
                    }
                }
                else if(b1==false)
                {
                    cout<<"Account is not found "<<endl;
                }
            }
            break;
            default:
                cout<<"Invalid input"<<endl;
            }
        }
        break;
        case 2:
        {
            buyTicket();
        }
        break;
        case 3:
        {
            busDetails();

        }
        break;
        case 4:
        {
            ifstream file("notice.txt");
            if(file)
            {
                while(getline(file,temp))
                {
                    cout<<temp<<endl;
                }
            }
        }
        break;
        case 5:
            cout << "Terminating program........";
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    while (choice != 5);
}

// end of program //

void registry::set1(int n)
{
    cout<<"Enter agent's name :";
    getline(cin,name);
    cout<<"Enter agent's age :";
    age=isInt(0,INT_MAX);
    cout<<"Enter agent's address ";
    getline(cin,address);
    cout<<"Enter agent's password :";
    getline(cin,password);
    string temp =to_string(n+1);
    string id;
    int size=temp.size();
    for(int i=0; i<8-size; i++)
    {
        id=id+"0";
    }
    id=id+temp;
    ofstream file("agents.txt",ios::app);
    ofstream file1("history.txt",ios::app);
    string cdate,ctime;
    cdate=getTime();
    ctime=getTime1();
    file1<<"On "<<ctime<<" "<<cdate<<endl;
    file1<<"An agent was registered. "<<endl<<"Agent's details : "<<endl;

    file1<<"Id       :"<<id<<endl;
    file1<<"Name     :"<<name<<endl;
    file1<<"Age      :"<<age<<endl;
    file1<<"Address  :"<<address<<endl<<endl;

    file<<id<<endl;
    Agents.push_back(id);
    file<<name<<endl;
    Agents.push_back(name);
    file<<age<<endl;
    Agents.push_back(to_string(age));
    file<<address<<endl;
    Agents.push_back(address);
    file<<password<<endl;
    Agents.push_back(password);
    cout<<"Registration successful"<<endl;
    totalagents=totalagents+5;
    cout<<"Agents id :"<<id<<endl;
    cout<<"Agents password :"<<password<<endl;
}

void addCoach(string who)
{
    string temp,temp2,ctime,cdate;
    int temp1;
    ofstream file("coach.txt",ios::app);
    cout<<"Enter name of new Coach : ";
    getline(cin,temp);
    file<<temp<<endl;
    cout<<"Enter number of seats in the new Coach :";
    temp1=isInt(1,INT_MAX);
    file<<temp1<<endl;
    temp2="Travel_"+temp+".txt";
    ofstream file1(temp2);
    temp2="vehicle_control_"+temp+".txt";
    ofstream file2(temp2);
    temp2="vehicle_"+temp+".txt";
    ofstream file3(temp2);
    file.close();
    file1.close();
    file2.close();
    file3.close();
    ofstream file4("history.txt",ios::app);
    ctime=getTime1();
    cdate=getTime();
    file4<<"On "<<ctime <<" "<<cdate <<endl<<" A coach named "<<temp<<" was added by "<<who<<endl;
    cout<<"Coach is added successfully"<<endl;
}

void deleteCoach(string who)
{
    string temp,filename,cdate,ctime;
    int temp1;
    vector<string>coach;
    ifstream file("coach.txt");
    int k=1;
    while(getline(file,temp))
    {
        coach.push_back(temp);
    }
    if(coach.size()<1)
    {
        cout<<"No available coach "<<endl;
        return;
    }
    for(int i=0; i<coach.size(); i=i+2)
    {
        cout<<k<<" . "<<coach[i]<<endl;
        k++;
    }
    int coach1;
    cout<<"Please select your preferred coach : ";
    coach1=isInt(1,(coach.size()/2));
    coach1--;
    coach1=coach1*2;
    temp=coach[coach1];
    coach.erase(coach.begin()+coach1);
    coach.erase(coach.begin()+coach1);
    ofstream file1("coach.txt");
    for(int i=0; i<coach.size(); i++)
    {
        file1<<coach[i]<<endl;
    }
    filename="Travel_"+temp+".txt";
    remove(filename.c_str());
    filename="vehicle_control_"+temp+".txt";
    remove(filename.c_str());
    filename="vehicle_"+temp+".txt";
    remove(filename.c_str());
    for(int i=0; i<=365; i++)
    {
        filename=getTime3(i)+"_"+temp+".txt";
        ifstream file2(filename);
        if(file2)
        {
            file2.close();
            remove(filename.c_str());

        }
    }
    ctime=getTime1();
    cdate=getTime();
    ofstream file3("history.txt",ios::app);
    file3<<"On "<<ctime <<" "<<cdate <<endl<<" A coach named "<<temp<<" was deleted by "<<who<<endl;
    cout<<"Coach is deleted successfully "<<endl;
}

void addRoute(string who)
{
    string temp;
    int temp1;
    vector<string>coach;
    ifstream file20("coach.txt");
    int k=1;
    while(getline(file20,temp))
    {
        coach.push_back(temp);
    }
    if(coach.size()<1)
    {
        cout<<"No available coach "<<endl;
        return;
    }
    for(int i=0; i<coach.size(); i=i+2)
    {
        cout<<k<<" . "<<coach[i]<<endl;
        k++;
    }
    int coach1,coach2;
    cout<<"Please select your preferred coach : ";
    coach1=isInt(1,(coach.size()/2));
    coach2=coach1;
    coach1--;
    coach1=coach1*2;
    coach2=(coach2*2)-1;
    string coachName=coach[coach1];
    ofstream file2("Travel_"+coachName+".txt",ios::app);
    vector<string> newRoute;
    string station;
    cout<<"Enter name of first station :";
    getline(cin,temp);
    stringstream s1(temp);
    int c1=0;
    while(s1>>temp)
    {
        if(c1==0)
        {
            station=temp;
        }
        else
        {
            station=station+"_"+temp;
        }
        c1++;
    }
    file2<<station<<" <-> ";
    newRoute.push_back(station);
    station.clear();
    cout<<"Enter name of second station :";
    getline(cin,temp);
    stringstream s2(temp);
    c1=0;
    while(s2>>temp)
    {
        if(c1==0)
        {
            station=temp;
        }
        else
        {
            station=station+"_"+temp;
        }
        c1++;
    }
    file2<<station<<":  ";
    newRoute.push_back(station);
    cout<<"Enter distance between two stations(in Km) :";
    temp1=isInt(0,INT_MAX);
    file2<<temp1<<" Km   ";
    newRoute.push_back(to_string(temp1));
    cout<<"Enter number of schedule in this route :";
    temp1=isInt(0,INT_MAX);
    int schedule=temp1*2;
    int vCount=temp1*2;
    int sCount=vCount*stoi(coach[coach2]);
    int time,hour,minute,count;
    string M;
    for(int i=0; i<temp1; i++)
    {
        cout<<"Enter the start time of schedule no "<<i+1<<" : "<<endl;
        cout<<"Enter hour :";
        hour=isInt(1,12);
        cout<<"Enter minute :";
        minute=isInt(0,59);
        cout<<"1.AM 2.PM \n enter your choice :";
        count=isInt(1,2);
        if(count==1)
        {
            M="AM";
        }
        else
        {
            M="PM";
        }
        if(M=="AM")
        {
            if(hour==12)
            {
                hour=0;
            }
            time=hour*60+minute;
        }
        else if(M=="PM")
        {
            if(hour==12)
            {
                hour=0;
            }
            time=(hour+12)*60+minute;
        }
        newRoute.push_back(to_string(time));

    }
    cout<<"Enter duration of each journey ";
    cout<<"Enter hour :";
    hour=isInt(0,INT_MAX);
    cout<<"Enter minute :";
    minute=isInt(0,59);
    time=hour*60+minute;
    newRoute.push_back(to_string(time));
    cout<<"Enter price of ticket :";
    temp1=isInt(0,INT_MAX);
    file2<<"  - "<<temp1<<"Tk"<<endl;
    newRoute.push_back(to_string(temp1));
    string newRoute1;
    for(int i=0; i<newRoute.size(); i++)
    {
        newRoute1=newRoute1+newRoute[i]+" ";
    }
    ofstream file("vehicle_control_"+coach[coach1]+".txt",ios::app);
    file<<newRoute1<<endl;
    ofstream file3("vehicle_"+coach[coach1]+".txt",ios::app);
    file3<<schedule<<endl;
    string cdate1;
    for(int i=0; i<=365; i++)
    {
        cdate1=getTime3(i)+"_"+coach[coach1]+".txt";
        ifstream file8(cdate1);
        if(file8)
        {
            ofstream file9(cdate1,ios::app);
            for(int j=0; j<sCount; j++)
            {
                file9<<"0"<<endl;
            }
        }
    }
    ifstream file5("Travel_"+coach[coach1]+".txt");
    vector<string>travel;
    while(getline(file5,temp))
    {
        travel.push_back(temp);
    }
    temp=travel[travel.size()-1];
    ofstream file6("history.txt",ios::app);
    string cdate=getTime();
    string ctime=getTime1();
    file6<<"On "<<ctime<<"  "<<cdate<<" A new route was added by "<<who<<endl;
    file6<<"Route details : "<<temp<<endl<<endl;
    cout<<"Route is added successfully "<<endl;

}

void deleteRoute(string who)
{
    string temp,cdate,ctime;
    int temp1;
    vector<string>coach;
    ifstream file20("coach.txt");
    int k=1;
    while(getline(file20,temp))
    {
        coach.push_back(temp);
    }
    if(coach.size()<1)
    {
        cout<<"No available coach "<<endl;
        return;
    }
    for(int i=0; i<coach.size(); i=i+2)
    {
        cout<<k<<" . "<<coach[i]<<endl;
        k++;
    }
    int coach1,coach2;
    cout<<"Please select your preferred coach : ";
    coach1=isInt(1,(coach.size()/2));
    coach2=coach1;
    coach1--;
    coach1=coach1*2;
    coach2=(coach2*2)-1;
    string coachName=coach[coach1];
    int coachSeat=stoi(coach[coach2]);
    vector<string>travel;
    vector<string>vehicle_control;
    vector<int>vehicles;
    int counter=1;
    ifstream file("Travel_"+coachName+".txt");
    while(getline(file,temp))
    {
        travel.push_back(temp);
        cout<<counter<<". "<<temp<<endl;
        counter++;
    }
    file.close();
    if(counter==1)
    {
        cout<<"No route is available"<<endl;
        return;
    }
    ifstream file1("vehicle_control_"+coachName+".txt");
    while(getline(file1,temp))
    {
        vehicle_control.push_back(temp);
    }
    file1.close();
    ifstream file2("vehicle_"+coachName+".txt");
    while(file2>>temp1)
    {
        vehicles.push_back(temp1);
    }
    file2.close();
    int routeNo=counter;
    cout<<"Enter route number to delete :";
    counter=isInt(1,routeNo-1);
    counter--;
    int vCount=0;
    for(int i=0; i<counter; i++)
    {
        vCount=vCount+vehicles[i];
    }
    int totalSeat1=vCount*coachSeat;
    int totalSeat2=vehicles[counter]*coachSeat;

    int advanceDay;
    ifstream file10("advanceBooking.txt");
    file10>>advanceDay;
    for(int i=0; i<=advanceDay; i++)
    {
        cdate=getTime3(i)+"_"+coachName+".txt";
        ifstream file11(cdate);
        if(file11)
        {
            vector<int>totalSeat;
            while(file11>>temp1)
            {
                totalSeat.push_back(temp1);
            }
            for(int i=0; i<totalSeat2; i++)
            {
                totalSeat.erase(totalSeat.begin()+totalSeat1);
            }
            ofstream file12(cdate);
            for(int j=0; j<totalSeat.size(); j++)
            {
                file12<<totalSeat[j]<<endl;
            }
        }
    }
    ofstream file7("history.txt",ios::app);
    cdate=getTime();
    ctime=getTime1();
    file7<<"On "<<ctime<<"  "<<cdate<<" A route was deleted by "<<who<<endl;
    file7<<"Route details : "<<travel[counter]<<endl<<endl;
    travel.erase(travel.begin()+counter);
    vehicle_control.erase(vehicle_control.begin()+counter);
    vehicles.erase(vehicles.begin()+counter);
    ofstream file3("Travel_"+coachName+".txt");
    for(int i=0; i<travel.size(); i++)
    {
        file3<<travel[i]<<endl;
    }
    file3.close();
    ofstream file4("vehicle_control_"+coachName+".txt");
    for(int i=0; i<vehicle_control.size(); i++)
    {
        file4<<vehicle_control[i]<<endl;
    }
    file4.close();
    ofstream file5("vehicle_"+coachName+".txt");
    for(int i=0; i<vehicles.size(); i++)
    {
        file5<<vehicles[i]<<endl;
    }
    file5.close();
    cout<<"Route is deleted successfully "<<endl;
}

int isInt(int n1, int n2)
{
    string temp1;
    int temp2;
    bool b = false;
    while (b==false)
    {
        getline(cin, temp1);
        b = true;
        for (int i = 0; i < temp1.size(); i++)
        {
            if (!isdigit(temp1[i]))
            {
                cout << "Invalid input, try again : ";
                b = false;
                break;
            }
        }
        if (b==true)
        {
            stringstream ss(temp1);
            ss >> temp2;
            if (temp2 < n1 || temp2 > n2)
            {
                cout << "Input out of range, try again : ";
                b = false;
            }
        }
    }
    return temp2;
}

void buyTicket()
{
    string temp,cdate,ctime;
    int temp1;
    ifstream file10("advanceBooking.txt");
    int advance;
    int busCount,seatCount;
    string Day,Day1;
    file10>>advance;
    for(int i=0; i<=advance; i++)
    {
        Day=getTime3(i);
        cout<<i+1<<". "<<Day<<endl;
    }
    cout<<"Please select your boarding date : ";
    int day=isInt(1,advance+1);
    day--;
    vector<string>coach;
    ifstream file20("coach.txt");
    int k=1;
    while(getline(file20,temp))
    {
        coach.push_back(temp);
    }
    if(coach.size()<1)
    {
        cout<<"No available coach "<<endl;
        return;
    }
    for(int i=0; i<coach.size(); i=i+2)
    {
        cout<<k<<" . "<<coach[i]<<endl;
        k++;
    }
    int coach1,coach2;
    //coach1 find coach's name and coach2 find coach's total seat
    cout<<"Please select your preferred coach : ";
    coach1=isInt(1,(coach.size()/2));
    coach2=coach1;
    coach1--;
    coach1=coach1*2;
    coach2=(coach2*2)-1;

    Day=getTime3(day)+"_"+coach[coach1]+".txt";
    Day1=getTime3(day);



    seatCount=stoi(coach[coach2]);
    busCount=0;
    ifstream file5("vehicle_"+coach[coach1]+".txt");
    while(file5>>temp1)
    {
        busCount=busCount+temp1;
    }

    vector<int> totalSeat1(busCount*seatCount);
    ifstream file11(Day);
    if(!file11)
    {
        ofstream new_file(Day);

        int i;
        for(i=0; i<busCount*seatCount; i++)
        {
            new_file<<"0"<<endl;
            totalSeat1[i]=0;
        }
        new_file.close();
    }
    else
    {
        int i=0;
        while(file11>>temp1)
        {
            totalSeat1[i]=temp1;
            i++;
        }
        file11.close();
    }
    string details;
    ifstream booking("Travel_"+coach[coach1]+".txt");
    int counter1=1;
    while(getline(booking,temp))
    {
        cout<<counter1<<". "<<temp<<endl;
        counter1++;
    }
    if(counter1==1)
    {
        cout<<"No route is available"<<endl;
        return;
    }
    booking.close();
    cout<<"Enter your desired destination :";
    int busNO;
    int schedule;
    int busNO3;
    busNO=isInt(1,counter1-1);
    ifstream booking1("vehicle_control_"+coach[coach1]+".txt");
    for(int i=1; i<=busNO && getline(booking1,temp); i++)
    {
        if(i==busNO)
        {
            details=temp;
        }
    }
    stringstream ss(details);
    int count=0;
    vector<string >control1;
    while(ss>>temp)
    {
        control1.push_back(temp);
        count++;

    }
    int busCount1=(count-5);
    string control[count];
    for(int j=0; j<count; j++)
    {
        control[j]=control1[j];
    }
    cout<<"Ticket price :"<<control[count-1]<<" Tk"<<endl;
    cout<<"Distance :"<<control[2]<<" Km"<<endl;
    int j=1;
    vector<string>sDate;
    string sDate1,sDate2;
    long long int secondCount;
    j=0;
    for(int i=0; i<busCount1; i++)
    {
        secondCount=getTime6(day,stoi(control[3+i]));
        sDate1=getTime7(secondCount);
        sDate.push_back(sDate1);
        secondCount=secondCount+(stoi(control[count-2]))*60;
        sDate2=getTime7(secondCount);
        sDate.push_back(sDate2);
        cout<<1+j<<" : "<<control[0]<<" -> "<<control[1]<<" : ( "<<sDate1<<" -> "<<sDate2<<") "<<endl;
        cout<<2+j<<" : "<<control[1]<<" -> "<<control[0]<<" : ( "<<sDate1<<" -> "<<sDate2<<") "<<endl;
        j=j+2;
    }
    cout<<"Select schedule : ";
    schedule=isInt(1,busCount1*2);
    int h;
    if(schedule%2==0)
    {
        h=schedule-1;
    }
    else
    {
        h=schedule;
    }
    sDate1=sDate[h-1];
    sDate2=sDate[h];
    if(schedule%2==0)
    {
        h=schedule/2;
    }
    else
    {
        h=(schedule+1)/2;
    }
    int sTime=stoi(control1[h+2]);
    string pdate1=getTime();
    int ctime1=getTime2();
    if(pdate1==Day1)
    {
        if(ctime1>=sTime)
        {
            cout<<"Sorry, the bus is already left the station "<<endl;
            return;
        }
    }
    ifstream busNumber1("vehicle_"+coach[coach1]+".txt");
    int sbus=0;
    for(int i=1; i<busNO && getline(busNumber1,temp); i++)
    {
        sbus=sbus+stoi(temp);
    }
    busNumber1.close();

    int avSeat=(sbus+schedule-1)*stoi(coach[coach2]);
    int avSeat1=0;
    cout<<"Available seats : ";
    for(int i=avSeat; i<(avSeat+stoi(coach[coach2])); i++)
    {
        if(totalSeat1[i]==0)
        {
            cout<<avSeat1+1<<" ";
        }
        avSeat1++;
    }
    cout<<endl<<"Choice your seat(1 to "<< coach[coach2]<<") : ";
    busNO3=isInt(1,stoi(coach[coach2]));

    int seatNO=(sbus+schedule-1)*(stoi(coach[coach2]))+busNO3-1;
    pdate1=getTime();
    ctime1=getTime2();
    if(pdate1==Day1)
    {
        if(ctime1>=sTime)
        {
            cout<<"Sorry, the bus is already left the station "<<endl;
            return;
        }
    }
    if(totalSeat1[seatNO]!=1)
    {
        totalSeat1[seatNO]=1;
        ofstream file3(Day);
        for(int i=0; i<(busCount*seatCount); i++)
        {
            file3<<totalSeat1[i]<<endl;
        }
        cdate=getTime();
        ctime=getTime1();
        long double balance1;
        ifstream balance("balance.txt");
        balance>>balance1;
        balance1=balance1+stod(control[count-1]);
        balance.close();
        ofstream balance2("balance.txt");
        balance2<<balance1<<endl;
        balance2.close();
        string sTime1=getTime5(sTime);
        string sTerminal=control1[0];
        string eTerminal=control1[1];
        if(schedule%2==0)
        {
            sTerminal=control1[1];
            eTerminal=control1[0];
        }
        ofstream history("history.txt",ios::app);
        history<<"On "<<ctime<<"  "<<cdate<<endl<<"Seat no : "<<busNO3<<" was booked "<<endl;
        history<<"Coach :"<<coach[coach1]<<" , "<<"Route : "<<sTerminal<<" -> "<<eTerminal<<" , Date :"<<Day1<<" , Time : ("<<sDate1<<" - "<<sDate2<<") - Price : "<<control[count-1]<<" Tk "<<endl;
        history<<"Current balance : "<<balance1<<"Tk"<<endl<<endl;
        cout<<"Seat no : "<<busNO3<<" is booked successfully "<<endl;
        cout<<"Coach :"<<coach[coach1]<<" , "<<"Route : "<<sTerminal<<" -> "<<eTerminal<<" , Date :"<<Day1<<" , Time : ("<<sDate1<<" - "<<sDate2<<") - Price : "<<control[count-1]<<" Tk "<<endl;
    }
    else
    {
        cout<<"seat is already booked"<<endl;
    }


}

void busDetails()
{
    string temp;
    int temp1;
    vector<string>coach;
    ifstream file20("coach.txt");
    int k=1;
    while(getline(file20,temp))
    {
        coach.push_back(temp);
    }
    if(coach.size()<1)
    {
        cout<<"No available coach "<<endl;
        return;
    }
    int coach1,coach3;
    for(int i=0; i<coach.size(); i=i+2)
    {
        cout<<k<<" . "<<coach[i]<<endl;
        k++;
    }
    k=1;
    cout<<"Please select any coach (Press 0 to return to Main menu): ";
    coach3=isInt(0,(coach.size()/2));
    while(coach3!=0)
    {
        coach1=coach3;
        coach1--;
        coach1=coach1*2;
        string coachName=coach[coach1];

        ifstream file("Travel_"+coachName+".txt",ios::app);
        string s;
        int i=1;
        if (file.is_open())
        {
            while (getline(file, s))
            {
                cout <<i<<". "<< s << endl;
                i++;
            }
            file.close();
        }
        if(i==1)
        {
            cout<<"No route is available , enter 0 to return :";
        }
        else
        {
            cout<<"Enter route number to see details (Press 0 to return to the previous menu):";
        }
        int busNO,busNO3;
        busNO=isInt(0,i-1);
        while(busNO!=0)
        {

            string details;
            ifstream booking1("vehicle_control_"+coachName+".txt");
            for(int j=1; j<=busNO && getline(booking1,temp); j++)
            {
                if(j==busNO)
                {
                    details=temp;
                }
            }
            stringstream ss(details);
            int count=0;
            vector<string >control1;
            while(ss>>temp)
            {
                control1.push_back(temp);
                count++;

            }
            int busCount=(count-5);
            string control[count];
            for(int j=0; j<count; j++)
            {
                control[j]=control1[j];
            }
            vector<string>sDate;
            string sDate1,sDate2;
            long long int secondCount;
            int j=0;
            cout<<"Distance     : "<<control1[2]<<" Km"<<endl;
            cout<<"Ticket price : "<<control1[control1.size()-1]<<" Tk"<<endl;
            for(int i=0; i<busCount; i++)
            {
                secondCount=getTime6(0,stoi(control[3+i]));
                sDate1=getTime7(secondCount);
                sDate.push_back(sDate1);
                secondCount=secondCount+(stoi(control[count-2]))*60;
                sDate2=getTime7(secondCount);
                sDate.push_back(sDate2);
                cout<<1+j<<" : "<<control[0]<<" -> "<<control[1]<<" : ( "<<sDate1<<" -> "<<sDate2<<") "<<endl;
                cout<<2+j<<" : "<<control[1]<<" -> "<<control[0]<<" : ( "<<sDate1<<" -> "<<sDate2<<") "<<endl;
                j=j+2;
            }
            cout<<"Enter route number to see details (Press 0 to return to the previous menu):";
            busNO=isInt(0,i-1);
        }
        for(int i=0; i<coach.size(); i=i+2)
        {
            cout<<k<<" . "<<coach[i]<<endl;
            k++;
        }
        k=1;
        cout<<"Please select any coach (Press 0 to return to Main menu): ";
        coach3=isInt(0,(coach.size()/2));
    }
}

void addNotice(string who)
{
    int count1=10;
    bool b;
    string s;
    cout << "Enter new notice :" << endl;
    getline(cin,s);
    ofstream file("notice.txt");
    file<<s;
    ofstream file1("history.txt",ios::app);
    string ctime=getTime1();
    string cdate=getTime();
    file1<<"On "<<ctime <<" "<<cdate <<endl<<" Notice was updated by "<<who<<endl;
    cout << "Notice is updated" << endl;
    file.close();
    file1.close();
}

void deleteHistory()
{
    string temp;
    cout<<"Remember , due to this operation half of histroy from previous will be deleted "<<endl;
    cout<<"Do you want to continue ? (y/n)"<<endl;
    string choice2;
    getline(cin,choice2);
    if(choice2=="y")
    {
        vector<string>history;
        ifstream file("history.txt");
        while(getline(file,temp))
        {
            history.push_back(temp);
        }
        int size1=history.size();
        if(size1<=1)
        {
            cout<<"Completed "<<endl;
            return;
        }
        size1=size1/2;
        for(int i=0; i<size1; i++)
        {
            history.erase(history.begin()+0);
        }
        ofstream file2("history.txt");
        for(int i=0; i<history.size(); i++)
        {
            file2<<history[i]<<endl;
        }
        cout<<"Completed "<<endl;
    }
    else if(choice2=="n")
    {
        cout<<"Operation canceled "<<endl;
    }
    else
    {
        cout<<"Invalid choice "<<endl;
    }

}
string getTime()
{
    int day;
    int month;
    int year;
    time_t now=time(nullptr);
    struct tm time = *localtime(&now);
    day=time.tm_mday;
    month=1+time.tm_mon;
    year=1900+time.tm_year;
    string ftime=to_string(day)+"-"+to_string(month)+"-"+to_string(year);
    return ftime;
}

string getTime1()
{
    time_t currentTime = time(nullptr);
    char time[100];
    strftime(time,100,"%I:%M:%S%p", localtime(&currentTime));
    return time;
}
int getTime2()
{
    time_t now=time(nullptr);
    struct tm time = *localtime(&now);
    int time1=(time.tm_hour)*60+time.tm_min;
    return time1;
}

string getTime3(int n)
{
    int day;
    int month;
    int year;
    time_t now=time(nullptr)+n*86400;
    struct tm time = *localtime(&now);
    day=time.tm_mday;
    month=1+time.tm_mon;
    year=1900+time.tm_year;
    string ftime=to_string(day)+"-"+to_string(month)+"-"+to_string(year);
    return ftime;
}


string getTime4(int n)
{
    int day;
    int month;
    int year;
    time_t now=time(nullptr)-n*86400;
    struct tm time = *localtime(&now);
    day=time.tm_mday;
    month=1+time.tm_mon;
    year=1900+time.tm_year;
    string ftime=to_string(day)+"-"+to_string(month)+"-"+to_string(year);
    return ftime;
}

string getTime5(int time)
{
    string M1="AM";
    int hour1,minute1;
    hour1=time/60;
    minute1=time-hour1*60;
    if(hour1>=12)
    {
        M1="PM";
        if(hour1>12)
        {
            hour1=hour1-12;
        }
    }
    if(hour1==0)
    {
        hour1=12;
    }
    string ftime=to_string(hour1)+":"+to_string(minute1)+M1;
    return ftime;
}

long long int getTime6(int n, int n1)
{
    int hour = n1 / 60;
    int minute = n1 -hour*60;
    time_t now = time(NULL) + n * 86400;
    struct tm localTime = *localtime(&now);
    localTime.tm_hour = hour;
    localTime.tm_min = minute;
    localTime.tm_sec = 0;
    time_t now1 = mktime(&localTime);
    return static_cast<long long int>(now1);
}


string getTime7(long long int n)
{
    time_t now=n;
    char time[200];
    strftime(time,200,"%d-%m-%Y  %I:%M%p ", localtime(&now));
    return time;
}

void adminMenu()
{
    cout<<" 1. History         2. Update advance booking limit"<<endl;
    cout<<" 3. Add route       4. Update Notice "<<endl;
    cout<<" 5. Agents          6. Update admin passcode "<<endl;
    cout<<" 7. Add coach       8. Delete route  "<<endl;
    cout<<" 9. Withdraw       10. Print admin menu "<<endl;
    cout<<"11. Delete coach   12. Delete old history  "<<endl;
    cout<<"13. Remove agent   14. Return to Main menu "<<endl;
    cout<<"15. Add agent  "<<endl;
}

void agentMenu()
{
    cout<<endl;
    cout<<" 1.Add coach        2.Delete coach "<<endl;
    cout<<" 3.Add route        4.Delete route "<<endl;
    cout<<" 5.Agent menu       6.Update agent's details "<<endl;
    cout<<" 7.History          8.Return to Main menu "<<endl;
    cout<<" 9.Update Notice   10.Update advance booking limit "<<endl;
}

//EndGame//
