#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include "Utility.h"
#include "ClassAndFuncsForCars.h"
#include "ClassAndFuncsForReservation.h"
#include "ClassAndFuncsForUser.h"
#include "ClassAndFuncsForComplaint.h"
using namespace std;

string CreateFolder = "mkdir ";

int DoAccountExists(string EnteredUserName)
{
    for (int i = 0; i < UserDatabaseCounter; i++)
    {
        if (EnteredUserName == Database[i].getUserName())
        {
            return i;
        }
    }
    return -1;
}
// Cars AvailabeCars[100];
int main()
{
// testing area
// system("Pause");
Home:
    // Very Common Whever You've to Choose , Choose Choice
    char choice;
    // Accounts Varibles
    LoadAccFromFile();
    int LoggedUser;

    // Search Variables
    Cars SearchResults[100];
    int SearchResults_Counter = 0;
    string WantedCredential;
    string Command;
    int RYear;

    // Reservation Variables
    string longChoice;
    int LongChoice;
    int CarIndex;
    while (true)
    {
        system("cls");
        cout << "\t\t\t -- Wellcome to Car Rental Hub --\n";
        cout << "1:REGISTER\n";
        cout << "2:LOGIN\n";
        cout << "3:EXIT\n";
        choice = _getch();
        string EnteredUserName;
        string EnteredPassword;
        int goAhead;

        switch (choice)
        {
        case '1':
            system("cls");
            cout << "\t\t\t-- Create Your Account -- \n";
            cout << " Enter Username : ";
            getline(cin, EnteredUserName);
            goAhead = DoAccountExists(EnteredUserName);
            Database[UserDatabaseCounter].setUserName(EnteredUserName);
            if (goAhead != -1)
            {
                cout << "This username is already Taken \n Try with another one \n";
                system("pause");
                break;
            }
            cout << " Enter Password : ";
            EnteredPassword = getPassword();
            Database[UserDatabaseCounter].setPassword(EnteredPassword);
            UserDatabaseCounter++;
            cout << " Account Created Successfully .. !\n ";
            Command = CreateFolder + "AllReservations" + "\\" + EnteredUserName + "Reservations";
            system(Command.c_str());
            system("Pause");
            break;
        case '2':
            system("cls");
            cout << "\t\t\t -- Login Your Account --\n";
            cout << "Enter Username : ";
            getline(cin, EnteredUserName);
            goAhead = DoAccountExists(EnteredUserName);
            if (goAhead != -1)
            {
                // cin.ignore();
                cout << "Enter Password : ";
                EnteredPassword = getPassword();
                // getline(cin, EnteredPassword);
                if (EnteredPassword == Database[goAhead].getPassword())
                {
                    cout << " Login Successfull ... !\n";
                    LoggedUser = goAhead;
                    goto LoggedIn;
                    system("pause");
                }
                else
                {
                    cout << "Wrong Password .. !" << endl;
                    system("pause");
                }
            }
            else
            {
                cout << " Account Dosen't Exist \n Enter Correct Username !!\n ";
                system("pause");
                break;
            }
            break;
        case '3':
            cout << " -- Have a Nice Day --\n";
            cout << " -- Application Closed --\n";
            cout << UserDatabaseCounter << endl; // Why Always comes with only one account
            UpdateFile();
            return 0;
            break;

        default:
            cout << " Invalid Choice !!! \n";
            system("Pause");
            break;
        }
    }
LoggedIn:

    while (true)
    {
        LoadAvailableCars();
        LoadReservedCars();
        Database[LoggedUser].LoadPreviousRerservations();
        Database[LoggedUser].LoadPrevioueComplaints();
        system("cls");
        cout << "\t\t\t -- Wellcome Mr. " << Database[LoggedUser].getUserName() << " -- " << endl;
        cout << "1:BROWSE CARS" << endl;
        cout << "2:SEARCH CARS" << endl;
        cout << "3:MAKE A RESERVATION" << endl;
        cout << "4:MY RESERVATIONS" << endl;
        cout << "5:PAYMENT" << endl;
        cout << "6:CUSTOMER SUPPORT" << endl;
        cout << "7:LOGOUT" << endl;
        choice = _getch();
        switch (choice)
        {
        case '1':
            system("cls");

            cout << " \t\t\t -- Available Cars --  \n";
            for (int i = 0; i < CarsEntryCounter; i++)
            {
                cout << "Car # " << i + 1 << "-->" << endl;
                AvailabeCars[i].DisplayOne();
            }
            system("Pause");
            break;
        case '2':
            while (true)
            {

                system("cls");
                cout << " You want to Search by What ? \n";
                // cout << "1:ID\n"; //IDs are for Admins to Manage Cars
                cout << "1:COMPANY(MAKE)\n";
                cout << "2:MODEL\n";
                cout << "3:COLOR\n";
                cout << "4:REGISTRATION YEAR\n";
                cout << "5:PREVIOUS MENU\n ";
                choice = _getch();
                switch (choice)
                {
                case '1':
                    system("cls");
                    SearchResults_Counter = 0;
                    cout << "\t\t\t -- Search By Company -- \n";
                    cout << " Enter Make (Company Name) : ";
                    getline(cin, WantedCredential);
                    for (int i = 0; i < CarsEntryCounter; i++)
                    {
                        if (WantedCredential == AvailabeCars[i].getMake())
                        {
                            SearchResults[SearchResults_Counter++] = AvailabeCars[i];
                        }
                    }

                    if (SearchResults_Counter > 0)
                    {
                        system("cls");
                        cout << "\t\t\t -- Search Results -- \n";
                        for (int i = 0; i < SearchResults_Counter; i++)
                        {
                            cout << "Car # " << i + 1 << " -->" << endl;
                            SearchResults[i].DisplayOne();
                        }
                        system("Pause");
                    }
                    else
                    {
                        cout << " No Cars Were Found With This Property \n";
                        cout << " To Go To Home Page Press ECS or to Search More Press any Other Key To Continue\n";
                        choice = _getch();
                        if (choice == 27)
                        {
                            goto LoggedIn;
                        }
                    }

                    break;
                case '2':
                    system("cls");
                    SearchResults_Counter = 0;
                    cout << "\t\t\t -- Search By Model -- \n";
                    cout << " Enter Model (Variants) : ";
                    getline(cin, WantedCredential);
                    for (int i = 0; i < CarsEntryCounter; i++)
                    {
                        if (WantedCredential == AvailabeCars[i].getModel())
                        {
                            SearchResults[SearchResults_Counter++] = AvailabeCars[i];
                        }
                    }

                    if (SearchResults_Counter > 0)
                    {
                        system("cls");
                        cout << "\t\t\t -- Search Results -- \n";
                        for (int i = 0; i < SearchResults_Counter; i++)
                        {
                            cout << "Car # " << i + 1 << " -->" << endl;
                            SearchResults[i].DisplayOne();
                        }
                        system("Pause");
                    }
                    else
                    {
                        cout << " No Cars Were Found With This Property \n";
                        cout << " To Go To Home Page Press ECS or to Search More Press any Other Key To Continue\n";
                        choice = _getch();
                        if (choice == 27)
                        {
                            goto LoggedIn;
                        }
                    }
                    break;
                case '3':
                    system("cls");
                    SearchResults_Counter = 0;
                    cout << "\t\t\t -- Search By Color -- \n";
                    cout << " Enter Car Color : ";
                    getline(cin, WantedCredential);
                    WantedCredential = toUpperCase(WantedCredential);

                    for (int i = 0; i < CarsEntryCounter; i++)
                    {
                        if (WantedCredential == AvailabeCars[i].getColor())
                        {
                            SearchResults[SearchResults_Counter++] = AvailabeCars[i];
                        }
                    }

                    if (SearchResults_Counter > 0)
                    {
                        system("cls");
                        cout << "\t\t\t -- Search Results -- \n";
                        for (int i = 0; i < SearchResults_Counter; i++)
                        {
                            cout << "Car # " << i + 1 << " -->" << endl;
                            SearchResults[i].DisplayOne();
                        }
                        system("Pause");
                    }
                    else
                    {
                        cout << " No Cars Were Found With This Property \n";
                        cout << " To Go To Home Page Press ECS or to Search More Press any Other Key To Continue\n";
                        choice = _getch();
                        if (choice == 27)
                        {
                            goto LoggedIn;
                        }
                    }

                    break;
                case '4':
                    system("cls");
                    SearchResults_Counter = 0;
                    cout << "\t\t\t -- Search By Registration Year -- \n";
                    cout << " Enter Car Registration Year With This Format (15) (Enter Only Year) : ";
                    // getline(cin, WantedCredential);
                    RYear = getNumsOnly(2);

                    // if (getNumOfDigits(RYear) == '4')
                    // {
                    //     RYear = ((WantedCredential[2] - 49) * 10) + ((WantedCredential[3] - 49));
                    // }
                    // if (getNumOfDigits(RYear) == '2')
                    // {

                    // }

                    for (int i = 0; i < CarsEntryCounter; i++)
                    {
                        if (RYear == AvailabeCars[i].getRegistrationYear())
                        {
                            SearchResults[SearchResults_Counter++] = AvailabeCars[i];
                        }
                    }

                    if (SearchResults_Counter > 0)
                    {
                        system("cls");
                        cout << "\t\t\t -- Search Results -- \n";
                        for (int i = 0; i < SearchResults_Counter; i++)
                        {
                            cout << "Car # " << i + 1 << " -->" << endl;
                            SearchResults[i].DisplayOne();
                        }
                        system("Pause");
                    }
                    else
                    {
                        cout << " No Cars Were Found With This Property \n";
                        cout << " To Go To Home Page Press ECS or to Search More Press any Other Key To Continue\n";
                        choice = _getch();
                        if (choice == 27)
                        {
                            goto LoggedIn;
                        }
                    }
                    break;
                case '5':
                    cout << " Press any Key To Go To Previous Menu\n";
                    _getch();
                    goto LoggedIn;
                    break;
                default:
                    cout << " Invalid Choice !! \n Choose Again .... \n";
                    system("Pause");
                    break;
                }
            }

            break;
        case '3':
        SelectAgain:
            system("cls");
            cout << " \t\t\t -- Make a Reservation --\n";

            cout << " You'll be Shown List of All Cars \n You've to Select From That !\n";
            for (int i = 0; i < CarsEntryCounter; i++)
            {
                cout << "Car # " << i + 1 << "-->" << endl;
                AvailabeCars[i].DisplayOne();
            }
            cout << "\t\t Select Car Number : ";
            getline(cin, longChoice);
            LongChoice = stoi(longChoice);
            LongChoice--;
            // cout << " Entered Choice is : " << LongChoice << endl;
            if (LongChoice < CarsEntryCounter)
            {
                system("cls");
                cout << " Nice Choice !! \n";
                AvailabeCars[LongChoice].DisplayOne();
            }
            else
            {
                cout << " Enter From Available Cars ... !" << endl;
                cout << " To Go To Previous Menu Press ECS \n & Select Again Press Any Other Key \n";
                choice = _getch();
                if (choice != 27)
                {
                    goto SelectAgain;
                }
            }
            CarIndex = LongChoice;
            Database[LoggedUser].SetReservationExceptCar(CarIndex);
            Database[LoggedUser].UploadAllReservations();
            ReservedCars[ReservedCarsCounter] = AvailabeCars[CarIndex];
            ReservedCarsCounter++;
            AvailabeCars[CarIndex].setNull();
            SortAvailableCarsAfterReservation(CarIndex);
            AvailabeCars[CarsEntryCounter].setNull();
            CarsEntryCounter--;
            UpdateCarsFile();
            UpdateReservedCarsFile();
            system("Pause");
            break;
        case '4':
            system("cls");
            cout << "\t\t\t -- List of All Reservations -- \n";
            Database[LoggedUser].DisplayAllReservations();
            system("Pause");
            break;
        case '5':
            cout << "You've Made :: " << Database[LoggedUser].getReservationCounter() << " :: Reservations\n";
            cout << " >> Here's Payment Status of All >> \n";
            Database[LoggedUser].PaymentStatuses();
            Database[LoggedUser].UploadAllReservations();
            system("Pause");
            break;
        case '6':

            system("cls");
            cout << " \t\t\t -- Customer Support -- \n";
            cout << " 1:FEEDBACK\n";
            cout << " 2:COMPLAINT\n";
            choice = _getch();
            if (choice == '1')
            {
                Date ResponseDate;
                ResponseDate.SetToday();
                system("cls");
                cout << " Rate Our Service (From 0 to 9) ";
                choice = _getche();
                cout << " Thanks for Your Response\n";
                ofstream fout("FeedbacksForAdmin.txt", ios::app);
                fout << "Feedback by " << Database[LoggedUser].getUserName() << " " << choice << " Stars , On " << ResponseDate.ReturnDate() << endl;
                fout.close();
            }
            else if (choice == '2')
            {
                Database[LoggedUser].AddComplaint();
                Database[LoggedUser].UpdateComplaintFile();
            }
            else
            {
                cout << " Invalid Choice \n";
            }

            system("Pause");
            break;
        case '7':
            system("cls");
            cout << " You're Logged Out \n Have a Nice Day Mr. " << Database[LoggedUser].getUserName() << "\n ";

            Database[LoggedUser].ShowAllComplaints();

            system("Pause");
            goto Home;
            break;
        default:
            cout << " Please Choose From Given Options \n ";
            system("Pause");
        }
    }

    return 0;
}