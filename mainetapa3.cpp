#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>


using namespace std;

ifstream player("players.in");
ifstream team_players("team_players.in");
ifstream team("teams.in");
ofstream output("team_players.out");
class Entity
{
    int age;
public:
    virtual void show() = 0;
    int getAge()
    {
        return this->age;
    }
    void setAge(int age)
    {
        this->age=age;
    }
};
class Coach:public Entity
{
private:
    char* name;
    float bonusoverall;
    float salary;

public:
    Coach()
    {

    }
    Coach operator = (Coach const &obj)
    {
        this->name = new char[strlen(name)];
        strcpy(this->name, name);
        salary=obj.salary;
        bonusoverall=obj.bonusoverall;

        return *this;

    }
    friend istream& operator>>(istream& is, Coach& coach);
    void setName(char* name)
    {
        this->name = new char[strlen(name)];
        strcpy(this->name, name);
    }
    void setBonusoverall(float bonusoverall)
    {
        this->bonusoverall=bonusoverall;
    }
    void setSalary(float salary)
    {
        this->salary=salary;
    }
    char* getName()
    {
        return this->name;
    }
    float getBonusoverall()
    {
        return this->bonusoverall;
    }
    float getSalary()
    {
        return this->salary;
    }
    void show()
    {
        cout << "Age is:"<<getAge();
    }
};

class Player
{
private:
    int *stats;
    string name;
    double salary;
    int fans;
    bool healthy;
    int overall;
public:

    Player()
    {
        salary=0;
        fans=0;
        overall=0;
        stats = new int[3]();
    }
    Player(string name, double salary)
    {
        this->name = name;
        this->salary = salary;
    }
    Player operator = (Player const &obj)
    {
        name=obj.name;
        salary=obj.salary;
        fans=obj.fans;
        overall=obj.overall;
        stats=new int[3]();
        stats[0]=obj.stats[0];
        stats[1]=obj.stats[1];
        stats[2]=obj.stats[2];
        healthy=obj.healthy;
        return *this;

    }

    operator double() const
    {
        return this->salary;
    }
    Player& operator ++ ()
    {
        overall++;
        for(int i=0; i<3; i++)
        {
            stats[i]++;
        }
        return *this;
    }

    Player& operator --()
    {
        overall--;
        for(int i=0; i<3; i++)
        {
            stats[i]--;
        }
        return *this;
    }
    Player operator --(int)
    {
        Player temp = *this;
        --temp;
        return temp;
    }
    Player operator ++ (int)
    {
        Player temp = *this;
        ++temp;
        return temp;
    }

    Player operator + (Player const &obj)
    {
        Player play;
        play.fans = fans + obj.fans;
        play.overall = overall + obj.overall;
        play.salary=salary+obj.salary;
        for(int i=0; i<3; i++)
            play.stats[i]=stats[i]+obj.stats[i];
        return play;
    }
    friend istream& operator>>(istream& is, Player& player);
    void setStats(int* stats, int length)
    {
        this->stats = new int[length];
        for (int i=0; i<length; i++)
        {
            this->stats[i] = stats[i];
        }
    }
    friend ostream& operator<<(ostream& os, const Player& dt);
    void setFans(int fans)
    {
        this->fans=fans;
    }
    int getStat(int i)
    {
        return stats[i];
    }
    int getFans()
    {
        return this->fans;
    }
    void setName(string name)
    {
        this->name=name;
    }
    string getName()
    {
        return this->name;
    }
    void setSalary(double salary)
    {
        this->salary=salary;
    }
    double getSalary()
    {
        return this->salary;
    }
    void setHealthy(bool healthy)
    {
        this->healthy=healthy;
    }
    bool getHealthy()
    {
        return healthy;
    }
    void setOverall(int overall)
    {
        this->overall=overall;
    }
    int getOverall()
    {
        int *stats;
        return overall;
    }

};
class Team
{
private:

    int playernr=5;
    int fans;
    float overall;
    float revenue;
    char* name;
    int stats[4];
    static const char* league;
    Player player[20];
    Player playerteam;
    float budget;
    float ticket_price=19.50;

    Coach coach;
    const int arena_seats=20900;
public:
    Team()
    {

    }
    Team(int playernr,int fans,float overall, float budget,char* name, int stats[])
    {
        this->playernr=playernr;
        this->fans=fans;
        this->overall=overall;
        this->budget=budget;
        this->stats[0]=stats[0];
        this->stats[1]=stats[1];
        this->stats[2]=stats[2];
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
    }
    Team operator = (Team  &obj)
    {
        this->name=new char[strlen(obj.getName())+1];
        strcpy(this->name,obj.getName());
        this->name[strlen(obj.getName())] = '\0';
        playernr=obj.playernr;
        fans=obj.fans;
        overall=obj.overall;
        for (int i=0; i<3; i++)
            stats[i]=obj.stats[i];
        return *this;

    }
    float getOverall()
    {
        return this->overall;
    }
    int getStats(int i)
    {
        return this->stats[i];
    }
    void trainplayer(int i)
    {
        player[i]++;
    }

    void setPHealth(int i,bool healthy)
    {
        player[i].setHealthy(healthy);
    }
    void setBudget(float budget)
    {
        this->budget=budget;
    }
    void setStat(int i,int j)
    {
        this->stats[j]+=player[i].getStat(j);
    }
    float getBudget()
    {
        return this->budget;
    }
    void setTicketprice( float tprice)
    {
        this->ticket_price=tprice;
    }
    bool operator ==(Team &obj)
    {
        int i;
        i=strcmp(name, obj.name);
        return i;
    }
    bool operator <(Team &obj)
    {
        return this->overall<obj.overall;
    }
    bool operator >(Team &obj)
    {
        return this->overall>obj.overall;
    }
    Team(int playernr, int fans, float revenue, char* name, Player player[20])
    {
        this->playernr = playernr;
        this->fans = fans;
        this->revenue = revenue;
        this->name = new char[strlen(name)];
        strcpy(this->name, name);
        for (int i=0; i<playernr; i++)
        {
            this->player[i] = player[i];
        }
    }
    void calculateeverything()
    {
        Player sum ;

        for(int i=0; i<playernr; i++)
        {
            sum=player[i]+sum;
        }
        fans=sum.getFans();
        overall=sum.getOverall()/playernr;
        for (int i=0; i<3; i++)
        {
            stats[i]=sum.getStat(i);

        }
    }
    friend istream& operator>>(istream& is, Team& team);
    float getPSalary(int i)
    {
        return player[i].getSalary();
    }
    int getArenaseats()
    {
        return this->arena_seats;
    }
    void setCoach(char* name, float bonusoverall, float salary,int age)
    {
        coach.setName(name);
        coach.setBonusoverall(bonusoverall);
        coach.setSalary(salary);
        coach.setAge(age);
    }
    friend ostream& operator<<(ostream& os, const Team& dt);
    int getPOverall(int i)
    {
        return player[i].getOverall();
    }
    int getPFans(int i)
    {
        return player[i].getFans();
    }

    void setName(char* name)
    {
        this->name = new char[strlen(name)];
        strcpy(this->name, name);
    }
    int getFans()
    {
        return this->fans;
    }
    char* getName()
    {
        return this->name;
    }
    int getPStats(int i,int j)
    {
        return player[i].getStat(j);
    }
    int getPlayernr()
    {
        return playernr;
    }
    float getTicketprice()
    {
        return this-> ticket_price;
    }
    void setRevenue(float revenue)
    {
        this->revenue=revenue;
    }
    void setPlayer(Player player,int a)
    {
        this->player[a]=player;
    }
    void hurtplayer(int i)
    {
        player[i]--;
    }
    char* getCoachname()
    {
        return coach.getName();
    }
    float getCoachSalary()
    {
        return coach.getSalary();
    }
    float getCoachoverall()
    {
        return coach.getBonusoverall();
    }
    int getCoachage()
    {
        return coach.getAge();
    }
    string getPlayername(int i)
    {
        return player[i].getName();
    }
    void setPSalary(int i,float salary)
    {
        player[i].setSalary(salary);
    }
    void playerswap(int i, int j)
    {
        Player aux;
        aux=player[i];
        player[i]=player[j];
        player[j]=aux;
    }
    void playerdelete(int i)
    {
        this->player[i]=player[i+1];
        playernr--;
    }
    void addPlayer(Player player)
    {
        this->player[playernr]=player;
        playernr++;
    }

    ~Team()
    {
        if (!name)
            delete [] name;
    }
};

ostream& operator<<(ostream& os, Team& dt)
{
    srand((unsigned)time(0));
    os<<dt.getName() <<" with "<<   rand() % 30 + 101 <<"\n";
    return os;
}
istream& operator>>(istream& is,Player& player)
{

    char aux[100];
    int stats[3];
    string forTokens;
    getline(is, forTokens);
    strcpy(aux, forTokens.c_str());
    char *p = strtok(aux, ",");
    player.setName(p);
    p = strtok(NULL, ",");
    player.setSalary(atoi(p));
    p= strtok(NULL,",");
    player.setFans(atoi(p));
    p= strtok(NULL,",");
    player.setOverall(atoi(p));
    p= strtok(NULL,",");
    for (int i=0; i<3; i++)
    {
        stats[i] = atoi(p);
        p = strtok(NULL, ",");
    }
    player.setStats(stats, 3);
    return is;
}
istream& operator>>(istream& is,Team& team)
{
    char s[20];
    cout<<"Type the name of your team:\n";
    is>>s;
    team.setName(s);
    return is;
}
istream& operator>>(istream& is,Coach& coach)
{
    char s[20];
    int i,a;
    cout<<"Type in the name of the coach:\n";
    is>>s;
    cout<<"Introduce coach's salary: \n";
    is>>i;
    cout<<"Introduce coach's age: \n";
    is>>a;
    coach.setAge(a);
    coach.setSalary(i);
    coach.setBonusoverall(25);
    return is;

}
ostream& operator<<(ostream& os,Player& dt)
{
    os << dt.getName() << " " << dt.getOverall()<<" "<<dt.getStat(0)<<" "<<dt.getStat(1)<<" "<<dt.getStat(2)<<"\n";
    return os;
}
class Match
{
private:
    Team team1;
    Team team2;
    int pointst1;
    int pointst2;

public:
    Team getTeam1()
    {
        return this->team1;
    }
    Team getTeam2()
    {
        return this->team2;
    }
    void setTeams(Team& team1, Team& team2)
    {

        this->team1 = team1;
        this->team2 = team2;
    }
    Match operator = (Match const &obj)
    {
        pointst1=obj.pointst1;
        pointst2=obj.pointst2;

        return *this;

    }
    virtual int getWinner()
    {
        for(int i=0;i<3;i++)
        {
            cout<<team1.getStats(i)<< " "<<team2.getStats(i)<<"\n";
        }
        int chancetl=1;
        if(team1<team2)
        {
            chancetl++;
        }

        if(team1.getStats(0)>team2.getStats(0))
            chancetl++;


        if(team1.getStats(1)>team2.getStats(1))
            chancetl++;

        if(team1.getStats(2)>team1.getStats(2))
            chancetl++;

        srand((unsigned)time(0));
        int rez;
        rez = rand() % 4;
        if(rez < chancetl)
        {
            return 1;
        }
        else
            return 0;
    }

};

class Finale:public Match
{
private:
    Team team1, team2;
    int nr_cups;
public:
     void setTeams(Team& team1, Team& team2)
    {

        this->team1 = team1;
        this->team2 = team2;
    }
    int getWinner()
    {
    for(int i=0;i<3;i++)
        {
            cout<<team1.getStats(i)<< " "<<team2.getStats(i)<<"\n";
        }
        int chancetl=1;
        if(team1<team2)
        {
            chancetl++;
        }

        if(team1.getStats(0)>team2.getStats(0))
            chancetl++;


        if(team1.getStats(1)>team2.getStats(1))
            chancetl++;

        if(team1.getStats(2)>team1.getStats(2))
            chancetl++;

        srand((unsigned)time(0));
        int rez;
        rez = rand() % 4 ;
        if(rez < chancetl)
        {
            nr_cups++;
            return 1;
        }
        else
            return 0;
    }
    int getCups()
    {
        return this->nr_cups;
    }
    void setCups(int nr_cups)
    {
        this->nr_cups=nr_cups;
    }

};

class Manager:public Coach
{
private:
    int free_days[8];
    int nr_max_free_days;
public:
    void setNrFreeDays(int i)
    {
        this->nr_max_free_days=i;
    }
    int getNrFreeDays()
    {
        return this->nr_max_free_days;
    }
    void setFreeDays()
    {
        if(nr_max_free_days>0)
        {
            for(int i=1; i<8; i++)
            {
                if(i==1)
                {
                    cout<<"Is Monday a free day?(1-yes/0-no)\n";
                    cin>>free_days[i];
                    if(free_days[i]==1)
                        nr_max_free_days--;
                    system("CLS");
                }
                else if(i==2)
                {
                    cout<<"Is Tuesday a free day?(1-yes/0-no)\n";
                    cin>>free_days[i];
                    if(free_days[i]==1)
                        nr_max_free_days--;
                    system("CLS");
                }
                else if(i==3)
                {
                    cout<<"Is Wednesday a free day?(1-yes/0-no)\n";
                    cin>>free_days[i];
                    if(free_days[i]==1)
                        nr_max_free_days--;
                    system("CLS");
                }
                else if(i==4)
                {
                    cout<<"Is Thursday a free day?(1-yes/0-no)\n";
                    cin>>free_days[i];
                    if(free_days[i]==1)
                        nr_max_free_days--;
                    system("CLS");
                }
                else if(i==5)
                {
                    cout<<"Is Friday a free day?(1-yes/0-no)\n";
                    cin>>free_days[i];
                    if(free_days[i]==1)
                        nr_max_free_days--;
                    system("CLS");
                }
                else if(i==6)
                {
                    cout<<"Is Saturday a free day?(1-yes/0-no)\n";
                    cin>>free_days[i];
                    if(free_days[i]==1)
                        nr_max_free_days--;
                    system("CLS");
                }
                else
                {
                    cout<<"Is Sunday a free day?(1-yes/0-no)\n";
                    cin>>free_days[i];
                    if(free_days[i]==1)
                        nr_max_free_days--;
                    system("CLS");
                }
                if(nr_max_free_days<=0)
                {
                    cout<<"You have no more free days to chose\n";

                    break;
                }


            }
        }
        else
            cout<<"You have no more free days to chose\n";

    }
    void ShowFreeDays()
    {
        int ok=0;
        cout<<"You are free on the next days:\n";
        for(int i=1; i<8; i++)
        {
            if(free_days[i]==1)
            {
                ok=1;
                if(i==1)
                    cout<<"Monday ";
                else if(i==2)
                    cout<<"Tuesday ";
                else if(i==3)
                    cout<<"Wednesday ";
                else if(i==4)
                    cout<<"Thursday ";
                else if(i==5)
                    cout<<"Friday ";
                else if(i==6)
                    cout<<"Saturday ";
                else
                    cout<<"Sunday ";
            }

        }
        cout<<"\n";
        if(ok==0)
            cout<<"You haven't selected the free days yet\n";
    }
};



int main()
{
    Manager manager;
    cout<<"Please introduce your name: ";
    char np[100];
    cin.get(np,100);
    cout<<"\n";
    cout<<"How old are you? ";
    int ag;
    cin>>ag;
    manager.setAge(ag);
    manager.setName(np);
    manager.setNrFreeDays(3);
    cout<<"What is your salary? ";
    float sal;
    cin>>sal;
    cout<<"\n";
    manager.setSalary(sal);
    manager.setBonusoverall(10);
    Team twinner;
    Coach coach1;
    Team teams[5];
    teams[0].setName("Denver Nuggets");
    teams[1].setName("Los Angeles Lakers");
    teams[2].setName("Miami Heat");
    teams[3].setName("Boston Celtics");
    Player players[30];
    teams[0].setCoach("Michael Malone",25,12000,49);
    teams[1].setCoach("Frank Vogel",25,12000,47);
    teams[2].setCoach("Erik Spoelstra",20,12000,50);
    teams[3].setCoach("Brad Stevens",15,12000,44);
    teams[0].setBudget(25000000);
    teams[1].setBudget(25000000);
    teams[2].setBudget(25000000);
    teams[3].setBudget(25000000);
    int z,teamnr=4,salary1;
    cout<<"1-Create your own team\n";
    cout<<"2-Use a predefine team\n";
    char s1[20],s2[20];
    int c1;
    cin>>c1;
    int a;
    int x=0;
    Finale fmatch;
    Match match;
    while(c1>2||c1<1)
    {
        cout<<"Unidentified command please enter agian: \n";
        cin>>c1;
    }
    if(c1==1)
    {



        a=4;
        teamnr++;
        cin>>teams[4];
        cin>>coach1;
        teams[a].setCoach(coach1.getName(),coach1.getBonusoverall(),coach1.getSalary(),coach1.getAge());


    }
    for(int i=0; i<30; i++)
    {

        team_players>>players[i];


    }
    for(int i=0; i<teamnr; i++)
    {
        for(int j=0; j<5; j++)
        {
            z=i*5+j;

            teams[i].setPlayer(players[z], j);
        }
    }
    for(int i=0; i<teamnr; i++)
    {
        teams[i].calculateeverything();
    }

    if(c1==2)
    {
        while(x!=1)
        {




            cout<<"Please choose a team you want to see the roster to:\n";

            for(int i=0; i<4; i++)
            {
                cout<<i+1<<"-"<<teams[i].getName()<<"\n";
            }

            cin>>a;
            system("CLS");
            while(a>5||a<0)
            {
                system("CLS");
                cout<<"Unidentified command please enter agian: \n";
                cin>>a;
            }
            a=a-1;

            for(int i=0; i<teams[a].getPlayernr(); i++)
            {
                cout<<teams[a].getPlayername(i)<<" "<<teams[a].getPStats(i,0)<<" "<<teams[a].getPStats(i,1)<<" "<<teams[a].getPStats(i,2)<<"\n";

            }
            cout<<"Coached by: "<<teams[a].getCoachname()<<endl;
            cout<<"You want to mange this team?(1-yes/0-no) "<<endl;
            cin>>x;
            if(x>1)
            {
                system("CLS");
                cout<<"Unidentified command please enter agian: \n";
                x=0;
            }
        }
    }
    int nmatch=teamnr-a-1;
    system("CLS");
    teams[a].setBudget(300000000);
    int b=1;
    while(b!=0)
    {
        cout<<"1-Manage Line-Up \n";
        cout<<"2-Budget Administration \n";
        cout<<"3-Next Adversary -League Match \n";
        cout<<"4-Manage Coach \n";
        cout<<"5-Manage Free Days\n";
        cout<<"6-Next Adversary -Championship Fianle \n";
        cout<<"0-EXIT \n";
        cin>>b;
        system("CLS");
        if(b==1)
        {
            while(b!=3&&b!=0)
            {

                cout<<"1-Change Lineup \n";
                cout<<"2-Manage a player \n";
                cout<<"3-BACK \n";
                cout<<"0-EXIT \n";
                cin>>b;
                system("CLS");
                if(b==1)
                {
                    for(int i=0; i<teams[a].getPlayernr(); i++)
                    {
                        cout<<i+1<<" "<<teams[a].getPlayername(i)<<" \n";

                    }
                    cout<<"Choose two players you want to swap(0,0 if you want to go back): \n";
                    int p1,p2;
                    cin>>p1>>p2;
                    system("CLS");
                    if(p1!=0&&p2!=0)
                    {
                        p1=p1-1;
                        p2=p2-1;
                        teams[a].playerswap(p1,p2);
                        b=3;
                    }
                }
                else if(b==2)
                {
                    for(int i=0; i<teams[a].getPlayernr(); i++)
                    {
                        cout<<i+1<<" "<<teams[a].getPlayername(i)<<" \n";

                    }
                    cout<<"Chose a player: ";
                    int p1;
                    cin>>p1;
                    p1--;
                    system("CLS");
                    cout<<teams[a].getPlayername(p1)<<"\n";
                    cout<<"PPG: "<<teams[a].getPStats(p1,0)<< "  APG: "<<teams[a].getPStats(p1,1)<<"  BPG: "<<teams[a].getPStats(p1,2)<<"  Salary: "<<teams[a].getPSalary(p1)<<"\n";
                    cout<<"1-Fire this player \n";
                    cout<<"2-Train player \n";
                    cout<<"3-Change player salary \n";
                    cout<<"4-Back \n";
                    cout<<"0-EXIT \n";
                    cin>>b;
                    system("CLS");
                    if(b==1 && teams[a].getPlayernr()<=5)
                        cout<<"You cannot fire a player if your team does not have at least 6 players\n";
                    else if(b==1&&teams[a].getPlayernr()>5)
                    {
                        int plnr;
                        plnr=teams[a].getPlayernr()-1;
                        teams[a].playerswap(p1,plnr);
                        teams[a].playerdelete(plnr);
                        cout<<"Player was fired\n";
                        teams[a].calculateeverything();

                    }
                    else if(b==2)
                    {
                        teams[a].trainplayer(p1);
                        srand((unsigned)time(0));
                        bool TrueFalse = (rand() % 100) < 90;
                        if(!TrueFalse)
                        {
                            cout<<"Player suffered an injury you should change him for the next match\n";
                            teams[a].setPHealth(p1,false);
                            teams[a].hurtplayer(p1);
                        }
                    }

                    else if(b==3)
                    {
                        cout<<"Old salary "<<teams[a].getPSalary(p1)<<" \n";
                        cout<<"Introduce new salary "<<"\n";
                        int newsal;
                        cin>>newsal;
                        teams[a].setPSalary(p1,newsal);
                    }


                    else if(b>4||b<0)
                    {
                        system("CLS");
                        cout<<"Unidentified command please enter agian: \n";
                    }
                }
                else if(b!=1&&b!=2&&b!=3&&b!=0)
                    cout<<"Unidentified command please enter agian: \n";
            }
        }
        else if(b==2)
        {
            while(b!=4&&b!=0)
            {

                cout<<"1-Get a new player \n";
                cout<<"2-See revenue per match \n";
                cout<<"3-Change ticket prices \n";
                cout<<"4-Back \n";
                cout<<"0-Exit \n";

                cin>>b;
                system("CLS");
                if(b==1)
                {
                    int nr1=teamnr*5+teams[a].getPlayernr()-5;
                    for(int i=nr1; i<30; i++)
                        cout<<i-nr1+1<<" "<<players[i].getName()<<"PPG: "<<players[i].getStat(0)<< "  APG: "<<players[i].getStat(1)<<"  BPG: "<<players[i].getStat(2)<<"  Salary: "<<players[i].getSalary()<<"\n";

                    cout<<"0-Add no players\n";

                    int p1;
                    cin>>p1;
                    if(p1!=0)
                    {
                        Player aux;
                        teams[a].addPlayer(players[p1+nr1-1]);
                        aux=players[p1];
                        players[p1]=players[nr1];
                        players[nr1]=aux;
                        teams[a].calculateeverything();
                    }

                }
                else if(b==2)
                {
                    system("CLS");
                    cout<<"Revenue on match is: ";
                    if(teams[a].getArenaseats()>teams[a].getFans())
                    {
                        cout<<teams[a].getTicketprice()*teams[a].getFans()<<"\n";
                    }
                    else
                    {
                        cout<<teams[a].getTicketprice()*teams[a].getArenaseats()<<"\n";
                    }
                    cout<<"Team budget is : "<<teams[a].getBudget()<<"\n";
                }
                else if(b==3)
                {
                    int tprice;
                    cout<<"Old Ticket Price: \n"<<teams[a].getTicketprice()<<" \n";
                    cout<<"New Ticket Price: \n";

                    cin>>tprice;

                    teams[a].setTicketprice(tprice);

                }
                else if(b<0||b>4)
                    cout<<"Unidentified command please enter agian: \n";
            }

        }
        else if(b==3)
        {
            nmatch++;
            nmatch=nmatch%teamnr;
            if(nmatch==a)
            {
                nmatch++;
            }

            while(b!=4&&b!=0)
            {


                cout<<"1-Show adversary name and line-up\n";
                cout<<"2-Show chances to win\n";
                cout<<"3-Simulate the next match\n";
                cout<<"4-Back\n";
                cout<<"0-EXIT\n";

                cin>>b;
                system("CLS");
                if(b==1)
                {
                    cout<<teams[nmatch].getName()<<"\n";
                    for(int i=1; i<5; i++)
                        cout<<teams[nmatch].getPlayername(i)<<"\n";


                }
                else if(b==2)
                {
                    if(teams[a]<teams[nmatch])
                        cout<<"This match is a hard to win match, try to change your line-up\n";
                    else if(teams[a]>teams[nmatch])
                        cout<<"This match is easier than most but you can still improve your line-up\n";
                    else if(teams[a]==teams[nmatch])
                        cout<<"This match is pretty even try to do some changes to your line-up\n";
                }
                else if(b==3)
                {

                    match.setTeams(teams[a],teams[nmatch]);

                    if(match.getWinner())
                    {
                        cout<<"Winner is ";
                        cout<<teams[a];
                    }
                    else
                    {
                        cout<<"Loser is ";
                        cout<<teams[a];
                    }
                    nmatch++;
                }
                else if(b<0||b>4)
                    cout<<"Unidentified command please enter agian: \n";
            }
        }
        else if(b==4)
        {
            cout<<teams[a].getCoachname()<<"at age: "<<teams[a].getCoachage()<<" is provinding a "<<teams[a].getCoachoverall()<<"% boost to our team\n";
        }
        else if(b==5)
        {
            cout<<"1-Show free days\n";
            cout<<"2-Select free days\n";
            cin>>b;
            if(b==1)
            {
                manager.ShowFreeDays();

            }
            else if(b==2)
            {
                cout<<"You have "<<manager.getNrFreeDays()<<" free days avalable\n";
                manager.setFreeDays();
            }

        }
        else if(b==6)
        {
            nmatch++;
            nmatch=nmatch%teamnr;
            if(nmatch==a)
            {
                nmatch++;
            }

            while(b!=4&&b!=0)
            {


                cout<<"1-Show adversary name and line-up\n";
                cout<<"2-Show chances to win\n";
                cout<<"3-Simulate the next match\n";
                cout<<"4-See how many finals you won\n";
                cout<<"5-Back\n";
                cout<<"0-EXIT\n";

                cin>>b;
                system("CLS");
                if(b==1)
                {
                    cout<<teams[nmatch].getName()<<"\n";
                    for(int i=1; i<5; i++)
                        cout<<teams[nmatch].getPlayername(i)<<"\n";


                }
                else if(b==2)
                {
                    if(teams[a]<teams[nmatch])
                        cout<<"This match is a hard to win match, try to change your line-up\n";
                    else if(teams[a]>teams[nmatch])
                        cout<<"This match is easier than most but you can still improve your line-up\n";
                    else if(teams[a]==teams[nmatch])
                        cout<<"This match is pretty even try to do some changes to your line-up\n";
                }
                else if(b==3)
                {

                    fmatch.setTeams(teams[a],teams[nmatch]);

                    if(fmatch.getWinner())
                    {
                        cout<<"Winner is ";
                        cout<<teams[a];
                        output<<"The "<<teams[a]<<" has won a championship using this roster: "<<"\n";
                        for(int i=1;i<teams[a].getPlayernr();i++)
                            output<<teams[nmatch].getPlayername(i)<<"\n";
                    }
                    else
                    {
                        cout<<"Loser is ";
                        cout<<teams[a];
                    }
                    nmatch++;
                }
                else if(b==4)
                {
                    int cu;
                    cu=fmatch.getCups();
                    cout<<"Your team has won :"<< cu<<" cups.\n";
                }
                else if(b<0||b>5)
                    cout<<"Unidentified command please enter agian: \n";
            }
        }
        else if(b!=0)
            cout<<"Unidentified command please enter agian: \n";
    }

    return 0;
}
