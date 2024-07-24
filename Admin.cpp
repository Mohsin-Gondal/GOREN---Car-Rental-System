#include <iostream>
#include <conio.h>
#include <fstream>
#include "Utility.h"
#include "ClassAndFuncsForCars.h"
#include "ClassAndFuncsForReservation.h"
#include "ClassAndFuncsForUser.h"
using namespace std;
// Convert String to UperCase

// Speacial Functions for Number Plate
// Irada Badal gya ab ni bnaoun ga
// Classes
// Cars AvailabeCars[100];
// Global Functions
bool Home()
{
    ifstream fin("AdminInfo.txt");
    string AdminFFile, PassFFile;
    fin >> AdminFFile;
    fin >> PassFFile;
    fin.close();
    system("cls");

    cout << "\t\t\t Car Rental Hub Admin Site " << endl;
    cout << " Enter Username : ";
    string username;
    getline(cin, username);
    if (username != AdminFFile)
    {
        cout << " Username not found !! " << endl;
        system("Pause");
        return false;
    }
    cout << " Enter Password : ";
    string Password = getPassword();
    if (PassFFile == Password)
    {
        cout << " Login Successfull ... ! \n";
        system("Pause");
        return true;
    }
    else
    {
        cout << " Wrong Password ... !!\n";
        system("Pause");
        return false;
    }
}

int main()
{
    // Testing Area
    // system("pause");
    // For Validation of Correct Admin --- !!
    while (true)
        if (Home() == true)
        {
            break;
        }
    // Now Functions and Menues for Administration -- !!
    LoadAvailableCars();
    
    while (true)
    {
        LoadAccFromFile();
        UpdateCarsFile();
        system("cls");
        cout << "\t\t\t Car Rental Hub Admin Site \n";
        cout << "1:See Availabe Cars\n";
        cout << "2:Add New Car Available\n";
        cout << "3:Reservations\n";
        cout << "4:Customer Service\n";
        cout << "5:Log Out\n";
        char Choice = _getch();
        int AccountChosen; // Reservation Variables <--

        switch (Choice)
        {
        case '1':
            system("Cls");
            cout << "\t\t\t -- LIST OF AVAILABLE CARS -- " << endl;
            for (int i = 0; i < CarsEntryCounter; i++)
            {
                cout << "Car #" << i + 1 << " -->" << endl;
                AvailabeCars[i].DisplayOne();
            }
            system("Pause");
            break;
        case '2':
            AvailabeCars[CarsEntryCounter++].AddCar();
            system("pause");
            break;
        case '3':
            system("cls");
            cout << "\t\t\t -- Reservations --\n";
            cout << " 1:CHOOSE ACCOUNT TO SEE RESERVATIONS\n";
            cout << " 2:SEE ALL RESERVATIONS\n";
            Choice = _getch();
            if (Choice == '1')
            {
                system("cls");
                cout << " Choose Account --> \n";
                for (int i = 0; i < UserDatabaseCounter; i++)
                {
                    cout << "Account #" << i + 1 << "-->";
                    cout << Database[i].getUserName() << endl;
                }
                cin >> AccountChosen;
                AccountChosen--;
                Database[AccountChosen].LoadPreviousRerservations();
                Database[AccountChosen].DisplayAllReservations();
            }
            else if (Choice == '2')
            {
                system("cls");
                cout << "\t\t\t -- List of All Reservations --\n";
                for (int i = 0; i < UserDatabaseCounter; i++)
                {

                    cout << "\t\t\t --| Mr " << Database[i].getUserName() << "'s Reservations |--" << endl;
                    Database[i].LoadPreviousRerservations();
                    Database[i].DisplayAllReservations();
                    cout << "==========================================>\n";
                }
            }
            else
            {
                cout << " Invalid Choice !!!\n";
            }

            system("pause");

            break;
        case '4':
        Case4:
            system("cls");
            cout << "\t\t\t -- Customer Care --\n";
            cout << "1:VIEW COMPLAINTS\n";
            cout << "2:VIEW FEEDBACKS\n";
            Choice = _getch();
            if (Choice == '1')
            {
                system("cls");
                cout << "\t\t\t -- COMPLAINTS SECTION --\n";
                cout << "1:VIEW ALL\n";
                cout << "2:VIEW PARTICULAR\n";
                cout << "(Press any Other Key to Go back)\n";
                Choice = _getch();
                if (Choice == '1')
                {
                    for (int i = 0; i < UserDatabaseCounter; i++)
                    {
                        cout << "\t\t\t --Mr. " << Database[i].getUserName() << "Complaints --\n";
                        Database[i].LoadPrevioueComplaints();
                        Database[i].ShowAllComplaints();
                        cout << "-------------------->\n\n\n\n";
                    }
                }
                else if (Choice == '2')
                {
                    system("cls");
                    cout << " Choose Account --> \n";
                    for (int i = 0; i < UserDatabaseCounter; i++)
                    {
                        cout << "Account #" << i + 1 << "-->";
                        cout << Database[i].getUserName() << endl;
                    }
                    cin >> AccountChosen;
                    AccountChosen--;
                    Database[AccountChosen].LoadPrevioueComplaints();
                    Database[AccountChosen].ShowAllComplaints();
                }
                else
                {
                    cout << "Invalid Choice\n";
                    goto Case4;
                }
            }
            else if (Choice == '2')
            {
                system("cls");
                cout << "\t\t\t -- FeedBacks --\n";
                string line;
                ifstream fin("FeedbacksForAdmin.txt");
                while (getline(fin, line))
                {
                    cout << line << endl;
                }
            }
            else
            {
                cout << " Invalid Choice \n";
            }
            system("Pause");
            break;
        case '5':
            cout << " --- Application Closed ---\n";
            // for (int i = 0; i < UserDatabaseCounter; i++)
            // {
            //     Database[i].DisplayOne();
            // }

            return 0;
            break;
        default:
            break;
        }
    }

    return 0;
}