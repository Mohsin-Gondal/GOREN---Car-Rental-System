#ifndef USERCLASS_H
#define USERCLASS_H

#include <iostream>
#include <fstream>
#include "Utility.h"
#include "ClassAndFuncsForCars.h"
#include "ClassAndFuncsForReservation.h"
#include "ClassAndFuncsForComplaint.h"

int UserDatabaseCounter = 0;
class User
{
    string username;
    string password;
    int ReservationCoutner;
    Reservation Reservations[100];
    int ComplaintCounter;
    Complaint Complaints[100];

public:
    // Member Functions
    string getUserName()
    {
        return username;
    }
    string getPassword()
    {
        return password;
    }
    string setUserName()
    {
        cout << " Enter Username : ";
        getline(cin, username);
        return username;
    }
    string setUserName(string asargument)
    {
        username = asargument;
        return username;
    }
    string setPassword()
    {
        cin.ignore();
        cout << " Enter Password : ";
        password = getPassword();
        return password;
    }
    string setPassword(string asargument)
    {
        password = asargument;
        return password;
    }
    void UploadOne()
    {
        ofstream fout("UserDatabase.txt", ios::app);
        fout << username << "," << password << endl;
        fout.close();
    }
    void UploadOne(ofstream &fout)
    {

        fout << username << "," << password << endl;
    }
    void LoadOne(string line)
    {
        int pos;
        string token;
        pos = line.find(',');
        token = line.substr(0, pos);
        username = token;
        line.erase(0, pos + 1);

        pos = line.find(',');
        token = line.substr(0, pos);
        password = token;
        line.erase(0, pos + 1);
    }
    void DisplayOne()
    {
        cout << " User name : " << username << endl;
        cout << " Password : " << password << endl;
    }
    void SetReservationExceptCar(int CarIndex)
    {
        Reservations[ReservationCoutner++].SetReservationExceptCar(CarIndex);
    }
    void DisplayAllReservations()
    {
        if (ReservationCoutner > 0)
            for (int i = 0; i < ReservationCoutner; i++)
            {
                cout << "--------------->\n";
                cout << " Reservation #" << i + 1 << endl;
                cout << "--------------->\n";
                Reservations[i].DisplayOne();
                cout << "----------------------------->\n\n\n";
            }
        else
            cout << "NO RESERVATIONS YET !!! \n";
    }
    void UploadAllReservations()
    {
        ofstream fout;
        fout.open("AllReservations/" + username + "Reservations/Reservations.txt");
        fout << ReservationCoutner << endl;
        for (int i = 0; i < ReservationCoutner; i++)
        {
            Reservations[i].UploadOne(fout);
        }
        // fout << endl;

        // cout << "Saara Data Upload Kar Ghatta a" << endl;
        fout.close();
    }
    void LoadPreviousRerservations()
    {
        ifstream fin("AllReservations/" + username + "Reservations/Reservations.txt");
        if (fin.is_open())
        {
            string line;
            getline(fin, line);
            ReservationCoutner = atoi(line.c_str());
            cout << "Value of Reservation Counter is : " << ReservationCoutner << endl;
            for (int i = 0; i < ReservationCoutner; i++)
            {
                Reservations[i].LoadOne(line, fin);
            }
        }
        else
        {
            // cout << " File Not Found or Wrong Dictionory " << endl;
        }
        fin.close();
    }
    int getReservationCounter()
    {
        return ReservationCoutner;
    }
    void PaymentStatuses()
    {
        for (int i = 0; i < ReservationCoutner; i++)
        {
            cout << "Person on Name of Whoom Reservation is Made : " << Reservations[i].getReserver() << endl;
            cout << "Payment Status : ";
            if (Reservations[i].PayByWhat() == 0)
            {
                if (Reservations[i].isPayed() == 0)
                {
                    cout << " Unpaid\n";
                    cout << " You've Choosed to Pay By Visiting the Site \n Come soon We're Waiting for You \n";
                }
                else
                {
                    cout << "Paid\n";
                }
            }
            else if (Reservations[i].PayByWhat() == 1)
            {
                if (Reservations[i].isPayed() == 0)
                {
                    cout << " Unpaid\n";
                    cout << " Your Card Is Under Process \n We'll Deduct From it If Credentials Came out \n To be Correct\n";
                }
                else
                {
                    cout << "Paid\n";
                }
            }
            else
            {
                cout << " You haven't Choose Payment Method So.. \n Choose Accordingly\n";
                cout << " 1:By Visiting Site\n";
                cout << " 2:By Card\n";
                char Choice = _getch();
                if (Choice == '1')
                {
                    Reservations[i].PayByWhat(0);
                }
                else if (Choice == '2')
                {
                    Reservations[i].PayByWhat(1);
                    Reservations[i].AddCardToBeUsed();
                }
                else
                {
                    cout << " Invalid Choice\n";
                }
            }
        }
    }
    void AddComplaint()
    {
        Complaints[ComplaintCounter++].AddComplaint();
    }
    void ShowAllComplaints()
    {

        if (ComplaintCounter > 0)
        {

            for (int i = 0; i < ComplaintCounter; i++)
            {
                cout << " Complaint #" << i + 1 << " ----> \n";
                Complaints[i].DisplayComplaint();
                cout << "------------------------------> \n";
            }
        }
        else
        {
            cout << " NO Complaints Yet " << endl;
        }
    }
    void UpdateComplaintFile()
    {
        ofstream fout("AllReservations/" + username + "Reservations/" + username + "Complaints.txt");
        fout << ComplaintCounter << endl;
        for (int i = 0; i < ComplaintCounter; i++)
        {

            Complaints[i].UploadComplaint(fout);
        }

        fout.close();
    }
    void LoadPrevioueComplaints()
    {
        string line;
        ifstream fin("AllReservations/" + username + "Reservations/" + username + "Complaints.txt");
        getline(fin, line);
        ComplaintCounter = atoi(line.c_str());
        for (int i = 0; i < ComplaintCounter; i++)
        {
            getline(fin, line);
            Complaints[i].DownloadComplaint(line);
        }
        fin.close();
    }

    // Constructors
    User()
    {
        ReservationCoutner = 0;
        username = "NoName";
        password = "NoPass";
        ComplaintCounter = 0;
    }
};
User Database[100]; //5

void LoadAccFromFile()
{
    ifstream fin("UserDatabase.txt");
    string line;
    getline(fin, line);
    UserDatabaseCounter = stoi(line);
    for (int i = 0; i < UserDatabaseCounter; i++)
    {
        getline(fin, line);
        Database[i].LoadOne(line);
    }
    fin.close();
    cout << " All Accounts Loaded :" << UserDatabaseCounter << endl;
}
void UpdateFile()
{
    ofstream fout("UserDatabase.txt");
    fout << UserDatabaseCounter << endl;
    for (int i = 0; i < UserDatabaseCounter; i++)
    {
        Database[i].UploadOne(fout);
    }
    fout.close();
}

#endif // USERCLASS_H
