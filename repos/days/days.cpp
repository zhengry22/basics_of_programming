#include<iostream>
using namespace std;

char date1[8], date2[8];

struct date {
    int year;
    int month;
    int day;
};

int day_of_years(int year)
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return 366;
    else
        return 365;
}

int day_of_months(int month, int year)
{
    if (day_of_years(year) == 366)
    {
        if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
            return 31;
        else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
            return 30;
        else if (month == 2)
            return 29;
    }
    else
    {
        if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
            return 31;
        else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
            return 30;
        else if (month == 2)
            return 28;
    }
}

int main()
{
    int result=0;
    int date1, date2;
    date d1, d2;
    cin >> date1 >> date2;
    d1.year = date1 / 10000;
    d1.month = (date1 % 10000) / 100;
    d1.day = (date1 % 10000) % 100;

    d2.year = date2 / 10000;
    d2.month = (date2 % 10000) / 100;
    d2.day = (date2 % 10000) % 100;
    //year
    /*for (int i = 2021; i <= 2049; i++)
    {
        if ((i % 4 != 0) && (day_of_years(i) != 365))
        {
            cout << "error";
            break;
        }
        else if ((i % 4 == 0) && (day_of_years(i) != 366))
        {
            cout << "error";
            break;
        }
        cout << day_of_years(i) << endl;
        for (int j = 1; j <= 12; j++)
        {
            if (i % 4 != 0)
            {
                if ((j == 1) || (j == 3) || (j == 5) || (j == 7) || (j == 8) || (j == 10) || (j == 12))
                {
                    if (day_of_months(j, i) != 31)
                    {
                        cout << "error";
                        break;
                    }       
                }
                else if ((j == 4) || (j == 6) || (j == 9) || (j == 11))
                {
                    if (day_of_months(j, i) != 30)
                    {
                        cout << "error";
                        break;
                    }
                }                    
                else if (j == 2)
                {
                    if (day_of_months(j, i) != 28)
                    {
                        cout << "error";
                        break;
                    }
                }                        
            }
            else
            {
                if ((j == 1) || (j == 3) || (j == 5) || (j == 7) || (j == 8) || (j == 10) || (j == 12))
                {
                    if (day_of_months(j, i) != 31)
                    {
                        cout << "error";
                        break;
                    }
                }
                else if ((j == 4) || (j == 6) || (j == 9) || (j == 11))
                {
                    if (day_of_months(j, i) != 30)
                    {
                        cout << "error";
                        break;
                    }
                }
                else if (j == 2)
                {
                    if (day_of_months(j, i) != 29)
                    {
                        cout << "error";
                        break;
                    }
                }
            }
            cout << day_of_months(j, i) << endl;
        }
    }*/
    

    for (int i = d1.year; i <= d2.year; i++)
    {
        result = result + day_of_years(i);
    }
    for (int i = 1; i < d1.month; i++)
    {
        result = result - day_of_months(i, d1.year);
    }
    for (int i = 12; i >= d2.month; i--)
    {
        result = result - day_of_months(i, d2.year);
    }
    result = result + d2.day - d1.day + 1;
   
    cout << result<<endl;

    return 0;
}