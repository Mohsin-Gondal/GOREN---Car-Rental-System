#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <conio.h>
#include <ctime>
#include <algorithm>
using namespace std;

string getPassword()
{
    char Result[256];
    char tempCh;
    int i = 0;
    while (true)
    {
        tempCh = _getch();
        if (tempCh == '\r' && i > 0)
        {
            Result[i] = '\0';
            break;
        }
        else if (tempCh == '\b')
        {
            if (i > 0)
            {
                cout << "\b \b";
                Result[i] = '\b';
                i--;
            }
        }
        else
        {
            Result[i] = tempCh;
            cout << "*";
            i++;
        }
    }
    cout << endl;

    return Result;
}

bool WrongEntry()
{
    char tempCh;
    cout << " Invalid Choice \n Press Escape(ESC) to Go To Home Screen \n or Press any Other Key to Choose Again......\n";
    tempCh = _getch();
    if (tempCh == 27)
    {
        return false;
    }
    return true;
}

string toUpperCase(const string &str)
{
    char result[str.length() + 1];
    int i = 0;
    for (; i < str.length(); i++)
    {
        result[i] = str[i];
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            result[i] -= 32;
        }
    }
    result[i] = '\0';
    return result;
}

string getAlphasOnly(int length)
{
    string Buffer = "";
    char tempCh;
    int i = 0;

    while (i < length)
    {
        tempCh = _getch();
        if ((tempCh >= 'A' && tempCh <= 'Z') || (tempCh >= 'a' && tempCh <= 'z'))
        {
            cout << tempCh;
            Buffer.push_back(tempCh);
            i++;
        }
        else if (tempCh == '\b' && i > 0)
        {
            cout << "\b \b";
            Buffer.pop_back();
            i--;
        }
        else if (tempCh == '\r' && i > 0)
        {

            break;
        }
    }
    cout << endl;
    return Buffer;
}
string getAlphasOnly(int length, string WithSpaces)
{
    string Buffer = "";
    char tempCh;
    int i = 0;

    while (i < length)
    {
        tempCh = _getch();
        if ((tempCh >= 'A' && tempCh <= 'Z') || (tempCh >= 'a' && tempCh <= 'z' || tempCh == ' '))
        {
            cout << tempCh;
            Buffer.push_back(tempCh);
            i++;
        }
        else if (tempCh == '\b' && i > 0)
        {
            cout << "\b \b";
            Buffer.pop_back();
            i--;
        }
        else if (tempCh == '\r' && i > 0)
        {

            break;
        }
    }
    cout << endl;
    return Buffer;
}

int getNumsOnly(int length)
{
    string Buffer = "";
    char tempCh;
    int i = 0;
    int Result;

    while (i < length)
    {
        tempCh = _getch();
        if (tempCh >= '0' && tempCh <= '9')
        {
            cout << tempCh;
            Buffer.push_back(tempCh);
            i++;
        }
        else if (tempCh == '\b' && i > 0)
        {
            cout << "\b \b";
            Buffer.pop_back();
            i--;
        }
        else if (tempCh == '\r' && i > 0)
        {

            break;
        }
    }
    Result = atoi(Buffer.c_str());
    cout << endl;
    return Result;
}
long long int getNumsOnly(int length, int longlongintOverloadingCheck)
{
    string Buffer = "";
    char tempCh;
    int i = 0;
    long long int Result;

    while (i < length)
    {
        tempCh = _getch();
        if (tempCh >= '0' && tempCh <= '9')
        {
            cout << tempCh;
            Buffer.push_back(tempCh);
            i++;
        }
        else if (tempCh == '\b' && i > 0)
        {
            cout << "\b \b";
            Buffer.pop_back();
            i--;
        }
        else if (tempCh == '\r' && i > 0)
        {

            break;
        }
    }
    Result = atoi(Buffer.c_str());
    cout << endl;
    return Result;
}
int getNumOfDigits(int Value)
{
    int digits = 0;
    while (Value > 0)
    {
        Value = Value / 10;
        digits++;
    }
    return digits;
}

void replaceCommasWithBackslashes(string &str)
{
    replace(str.begin(), str.end(), ',', '\\');
}
class Date
{
private:
    int dd, mm, yy;

public:
    // MemberFunctions
    void SetNull()
    {
        dd = 0;
        mm = 0;
        yy = 0;
    }
    string PrintDate()
    {
        cout << dd << "/" << mm << "/" << yy << endl;
    }
    string ReturnDate()
    {
        string str = to_string(dd);
        string str1 = to_string(mm);
        string str2 = to_string(yy);

        return str + "," + str1 + "," + str2;
    }
    void SetToday()
    {
        time_t tim = time(0);
        tm *gottime = localtime(&tim);
        yy = gottime->tm_year + 1900;
        mm = gottime->tm_mon + 1;
        dd = gottime->tm_mday;
    }
    void SetDate(int d, int m, int y)
    {
        dd = d;
        mm = m;
        yy = y;
    }
    void SetDate()
    {
    D:
        cout << " Enter Day : ";
        dd = getNumsOnly(2);
        if (dd > 31 || dd == 0)
        {
            cout << " Invalid Day!! \n Press any Key to Enter Again.....";
            getch();
            cout << "\n";
            goto D;
        }

    M:
        cout << " Enter Month : ";
        mm = getNumsOnly(2);
        if (mm > 12 || mm == 0)
        {
            cout << " Invalid Month!! \n Press any Key to Enter Again.....";
            getch();
            cout << "\n";
            goto M;
        }
        if (mm == 2 && dd > 29)
        {
            cout << " February Can't have More Days than 29\n";
            cout << " Invlid Day & Month \n";
            cout << " Press any key to Enter Again ...";
            getch();
            cout << "\n";
            goto D;
        }
        else if (mm <= 7)
        {
            if (mm % 2 == 0 && dd > 30)
            {
                cout << " Invlid Day & Month \n";
                cout << " Press any key to Enter Again ...";
                getch();
                cout << "\n";
                goto D;
            }
        }
        else if (mm <= 12)
        {
            if (mm % 2 != 0 && dd > 30)
            {
                cout << " Invlid Day & Month \n";
                cout << " Press any key to Enter Again ...";
                getch();
                cout << "\n";
                goto D;
            }
        }

    Y:
        cout << " Enter Year : ";
        yy = getNumsOnly(4);
        if (yy == 0)
        {
            cout << " Invalid Year!! \n Press any Key to Enter Again.....\n";
            getch();
            goto Y;
        }
        else if (dd >= 29 && mm == 2)
        {
            if ((yy % 4 != 0))
            {
                cout << "It's not Leap year And You've Put 29, And You think You're Smart!!! \n Go Back and Enter values Again \n Never Mind, It was a Joke \n";
                goto D;
            }
        }
    }
    // Constructors
    Date()
    {
        time_t tim = time(0);
        tm *gottime = localtime(&tim);
        yy = gottime->tm_year + 1900;
        mm = gottime->tm_mon + 1;
        dd = gottime->tm_mday;
    }
};

#endif