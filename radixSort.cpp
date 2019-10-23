
#include<iostream>
using namespace std;

class student
{
private:
    int id,credit,modId;
    double cgpa;
    string firstname,lastname;
public:
    student()
    {
        id = modId = credit = 0;
    }
    void input()
    {
        cin >> id >> firstname >> lastname >> credit >> cgpa;
        modId = id;
    }
    void display()
    {
        cout << id << "  " << firstname << " " << lastname << "  " << credit << "  " << cgpa << endl;
    }
    int getmodId()
    {
        return modId;
    }
    void modifyId();
    void operator =(student);

};

void student :: operator =(student st)
{
    id = st.id;
    modId = st.modId;
    credit = st.credit;
    firstname = st.firstname;
    lastname = st.lastname;
    cgpa = st.cgpa;
}

void student :: modifyId()
{
    modId /= 10;
}

void counting(student STudeNt[], int digit[], int n)
{
    student res[1000];

    int i,dig;

    for(i = 1; i < 10; i++)
    {
        digit[i] += digit[i-1];

    }

    for(i = n; i > 0; i--)
    {
        dig = STudeNt[i].getmodId();
        dig %= 10;
        res[digit[dig]] = STudeNt[i];
        res[digit[dig]].modifyId();
        //cout << digit[dig] << " " << dig << endl;
        digit[dig]--;
    }

    for(i = n; i > 0; i--)STudeNt[i] = res[i];
    //for(i = n; i>0; i--)STudeNt[i].display();
}

void Radix(student STudeNt[], int n)
{
    int i,digit[11];
    bool fg;
    fg=true;
    while(fg)
    {
        fg=false;
        for(i = 0; i < 10; i++)digit[i] = 0;
        for(i = 1; i <= n; i++)
        {
            int res = (STudeNt[i].getmodId());
            if(res>0)fg=true;
            res=res%10;
            digit[res]++;
        }
        if(fg)counting(STudeNt,digit,n);
    }
}

int main()
{
    int n,i;
    cin >> n;
    student STudeNt[1000];
    for(i = 1; i <= n; i++)STudeNt[i].input();
    Radix(STudeNt,n);
    cout << endl;
    for(i = 1; i <= n; i++)STudeNt[i].display();
    return 0;
}

/*
5
12345 Abid Raihan 30 3.4
26345 Hafiz Adnan 100 3.24
17345 Jakaria Ahmed 80 2.94
72845 Harun Yahia 100 3.84
23745 Jabid Hannan 80 3.47
*/
