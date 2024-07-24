#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    while (true)
    {
        system("cls");
        // system("color DF");
        system("color F0");
        cout << "\t\t\t -- Dual Controller --\n";
        cout << "1:ADMINSITE\n";
        cout << "2:USERSITE\n";
        cout << "3:EXIT\n";
        char choice = _getch();
        switch (choice)
        {
        case '1':
            // system("color 97");
            system("Admin.exe");
            break;
        case '2':
            // system("color F0");
            system("User.exe");
            break;
        case '3':
            cout << "\t\t\t XX Closing Dual Controller XX\n";
            return 0;
        }
    }
}