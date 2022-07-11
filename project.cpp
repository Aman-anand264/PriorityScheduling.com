#include<bits/stdc++.h>
using namespace std;

class Project
{

private:
    int s_no;
    string name;
    int income;
    int age;
    int days;
    string address;
    string gender;
    int loan_amount;
    string education;
    string credit_history;
    string married;
    int x;
    int count=0;
    vector<int>vi;
    vector<int>l;
    vector<int>d;
    vector<int> ct;
    vector<int>tat;
    int loan_days;
    vector<int>l_d;
    vector<int> s;




public:
    void func_intro();
    void selectloan();
    void scheduling();
    void emi();


};
void Project :: func_intro()
{

    int n;
    cout<<"\t\t\t\t ---------- Welcome to PNB Bank Portal---------"<<endl;
    cout<<"\nNumber of customers applied for loan-> ";
    cin>>n;
    cout<<endl;
    for(int i=0; i<n; i++)
    {

        cout<<"Enter the Number of customer ->";
        cin>>s_no;
        cout<<endl;

        cout<<"Enter the Name of the customer -> ";
        cin>>name;
        cout<<endl;

        cout<<"Enter the income of the customer -> ";
        cin>>income;
        cout<<endl;
        vi.push_back(income);

        cout<<"Enter the age of the customer -> ";
        cin>>age;
        cout<<endl;

        cout<<"Address -> ";
        cin>>address;
        cout<<endl;

        cout<<"Gender --> ";
        cin>>gender;
        cout<<endl;

        cout<<"Enter the loan amount -> ";
        cin>>loan_amount;
        cout<<endl;
        l.push_back(loan_amount);


        cout<<"Education ->";
        cin>>education;
        cout<<endl;


        cout<<"Married -> ";
        cin>>married;
        cout<<endl;

        cout<<"Credit History -> ";
        cin>>credit_history;
        cout<<endl;

        cout<<"Enter the days -> ";
        cin>>days;
        cout<<endl;
        d.push_back(days);

        cout<<"Number of years you wanted for the loan ->";
        cin>>loan_days;
        cout<<endl;
        l_d.push_back(loan_days);


        count++;




    }

}




void Project :: selectloan()
{

    cout<<"-------Enter the type of loan----->"<<endl;
    cout<<"0 -> Education Loan"<<endl;
    cout<<"1 -> Housing Loan"<<endl;
    cout<<"2 -> Car Loan"<<endl;
    cout<<"3 -> Gold Loan"<<endl;
    cout<<"4 ->Personal Loan"<<endl;
    cout<<endl;
    cin>>x;


    switch(x)
    {

    case 0:
        cout<<"Education loan is selected";
        break;
    case 1:
        cout<<"Housing loan is selected";
        break;
    case 2:
        cout<<"Car loan is selected";
        break;
    case 3:
        cout<<"Gold loan is selected";
        break;
    case 4:
        cout<<"Personal loan is selected";
        break;
    default:
        cout<<"Mandatory to choose above loan";
        break;

    }
    cout<<endl;

}




void Project :: scheduling()
{

    int at[count]= {0}, days[count],s_no[count],wt[count],loan_amount[count],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    int sum=0,add=0,sum1=0;

    vector <int> pt1 = l;
    sort(pt1.begin(),pt1.end(),greater<int>());
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if(pt1[i] == l[j] && l[j]!=-1)
            {
                l[j]=-1;
                sum += d[j];
                ct.push_back(sum);
                break;
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        add += ct[i]-at[i];
        int a1 = ct[i]-at[i];
        tat.push_back(a1);
    }
    for (int i = 0; i < count; i++)
    {
        sum1 += tat[i]-d[i];
    }

    cout<<endl;

    int wait=(sum1)/(count);

    cout<<"loan will approved in -->"<<endl;

    for(int i=0;i<count;i++)
    {

        if(d[i]<wait)
        {
          cout<<"customer "<<i+1<<"--> "<<d[i]<<" days |"<<"EMI per month --> Rs."<<s[i]<<endl;
        }
        else{
         cout<<"customer "<<i+1<<"--> "<<wait<<" days |"<<"EMI per month --> Rs."<<s[i]<<endl;
        }
    }

}

void Project :: emi()
{

    for(int i=0 ;i<count;i++)
    {
        int add0=l[i]/l_d[i];
        add0=add0/12;
        s.push_back(add0);
    }


}


int main()
{

    Project p;
    p.func_intro();
    p.selectloan();
    p.emi();
    p.scheduling();



    return 0;

}
