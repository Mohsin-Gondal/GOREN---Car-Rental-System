#ifndef RESERVATIONCLASS_H
#define RESERVATIONCLASS_H
#include <iostream>
#include "Utility.h"
#include "ClassAndFuncsForCars.h"

class BankCard
{
    string TempInput;
    string BankName;
    string HolderName;
    long long int CardNumber;
    string TypeOfCard;
    int CVC;
    Date ExpiryDate;

public:
    // Member Functions
    void setNull()
    {
        BankName = "Null";
        HolderName = "Null";
        CardNumber = -1;
        TypeOfCard = "Null";
        CVC = -1;
        ExpiryDate.SetNull();
    }
    void setCard()
    {
        cin.ignore();
        cout << " Enter Holder Name : ";
        getline(cin, HolderName);
        cout << " Enter Bank Bame    : ";
        getline(cin, BankName);
        cout << " Enter Card Number   : ";
        getline(cin, TempInput);
        if (TempInput[1] == '2' || TempInput[1] == '5')
        {
            TypeOfCard = "MASTERCARD";
        }
        else if (TempInput[1] == '4')
        {
            TypeOfCard = "VISA";
        }
        else if (TempInput[1] == '3')
        {
            TypeOfCard = "AMERICAN EXPRESS";
        }
        else if (TempInput[1] == '6')
        {
            TypeOfCard = "DISCOVER";
        }
        else
        {
            TypeOfCard = "UNKNOWN";
        }
        CardNumber = atoll(TempInput.c_str());
        cout << " Enter CVC : ";
        cin >> CVC;
        cout << " Enter Expiry Date --> \n";
        ExpiryDate.SetDate();
    }
    void setCard(string BName, string HName, long CardLumber, string Type, int cvc, Date EXDate)
    {
        BankName = BName;
        HolderName = HName;
        CardNumber = CardLumber;
        TypeOfCard = Type;
        CVC = cvc;
        ExpiryDate = EXDate;
    }
    void DisplayCard()
    {
        cout << "-----------------------------------------\n";
        cout << " Bank Name    : " << BankName << endl;
        cout << " Holder Name  : " << HolderName << endl;
        cout << " Card Number  : " << CardNumber << endl;
        cout << " CVC          : " << CVC << endl;
        cout << " Card Type    : " << TypeOfCard << endl;
        cout << " Expiry Date  : ";
        ExpiryDate.PrintDate();

        // << ExpiryDate.ReturnDate() << endl;
        cout << "-----------------------------------------\n";
    }
    void UploadOne(ofstream &fout)
    {
        fout << BankName << "," << HolderName << "," << CardNumber << "," << TypeOfCard << "," << CVC << "," << ExpiryDate.ReturnDate() << "\n";
    }
    void LoadOne(string line)
    {
        int pos;
        string token;

        pos = line.find(',');
        token = line.substr(0, pos);
        BankName = token;
        line.erase(0, pos + 1);

        pos = line.find(',');
        token = line.substr(0, pos);
        HolderName = token;
        line.erase(0, pos + 1);

        pos = line.find(',');
        token = line.substr(0, pos);
        CardNumber = atoll(token.c_str());
        line.erase(0, pos + 1);

        pos = line.find(',');
        token = line.substr(0, pos);
        TypeOfCard = token;
        line.erase(0, pos + 1);

        pos = line.find(',');
        token = line.substr(0, pos);
        CVC = atoi(token.c_str());
        line.erase(0, pos + 1);

        int dd, mm, yy;

        pos = line.find(',');
        token = line.substr(0, pos);
        dd = atoi(token.c_str());
        line.erase(0, pos + 1);

        pos = line.find(',');
        token = line.substr(0, pos);
        mm = atoi(token.c_str());
        line.erase(0, pos + 1);

        pos = line.find(',');
        token = line.substr(0, pos);
        yy = atoi(token.c_str());
        line.erase(0, pos + 1);

        ExpiryDate.SetDate(dd, mm, yy);
    }
    // Constructors
    BankCard()
    {
        BankName = "Null";
        HolderName = "Null";
        CardNumber = -1;
        TypeOfCard = "Null";
        CVC = -1;
        ExpiryDate.SetNull();
    }
};
class Reservation
{
private:
    string TempInput;
    string ReserverName;
    string ReserverAddress;
    Cars ReservedCar;
    long long int CNIC;
    long long int MobileNumber;
    BankCard CardToBeUsed;
    int PayByCard;
    bool is_payed;
    Date ReservationFromDate;
    Date ReservationTillDate;

public:
    void LoadOne(string line, ifstream &fin)
    {
        getline(fin, line);
        string token;
        int pos;

        pos = line.find(',');
        token = line.substr(0, pos);
        ReserverName = token;
        line.erase(0, pos + 1);

        pos = line.find(',');
        token = line.substr(0, pos);
        ReserverAddress = token;
        line.erase(0, pos + 1);

        getline(fin, line);
        ReservedCar.DownloadOne(line);
        getline(fin, line);

        pos = line.find(',');
        token = line.substr(0, pos);
        CNIC = atoll(token.c_str());
        line.erase(0, pos + 1);

        pos = line.find(',');
        token = line.substr(0, pos);
        MobileNumber = atoll(token.c_str());
        line.erase(0, pos + 1);

        pos = line.find(',');
        token = line.substr(0, pos);
        PayByCard = atoi(token.c_str());
        line.erase(0, pos + 1);

        int dd, mm, yy;
        pos = line.find(',');
        token = line.substr(0, pos);
        dd = atoi(token.c_str());
        line.erase(0, pos + 1);

        pos = line.find(',');
        token = line.substr(0, pos);
        mm = atoi(token.c_str());
        line.erase(0, pos + 1);

        pos = line.find(',');
        token = line.substr(0, pos);
        yy = atoi(token.c_str());
        line.erase(0, pos + 1);

        ReservationFromDate.SetDate(dd, mm, yy);

        pos = line.find(',');
        token = line.substr(0, pos);
        dd = atoi(token.c_str());
        line.erase(0, pos + 1);

        pos = line.find(',');
        token = line.substr(0, pos);
        mm = atoi(token.c_str());
        line.erase(0, pos + 1);

        pos = line.find(',');
        token = line.substr(0, pos);
        yy = atoi(token.c_str());
        line.erase(0, pos + 1);

        ReservationTillDate.SetDate(dd, mm, yy);
        getline(fin, line);
        CardToBeUsed.LoadOne(line);
    }
    // Member Functions
    void UploadOne(ofstream &fout)
    {
        fout << ReserverName << "," << ReserverAddress << "\n";
        ReservedCar.UploadOne(fout);
        fout << CNIC << "," << MobileNumber << "," << PayByCard << "," << ReservationFromDate.ReturnDate() << "," << ReservationTillDate.ReturnDate() << "\n";
        CardToBeUsed.UploadOne(fout);
    }
    void SetReservationExceptCar(int CarIndex)
    {
        ReservedCar = AvailabeCars[CarIndex];
        cout << " Car Has Been Selected Now!!!" << endl;
        cout << " We Could Have Taken Your Name From Our Database but Reserver Maybe Differend So \n Enter Your Name (Max 24 Characters) :";
        ReserverName = getAlphasOnly(24, "WithSpaces");
        ReserverName = toUpperCase(ReserverName);
        // getline(cin, ReserverName);
        cout << " Enter Your Address (Max 30 Characters) : ";
        ReserverAddress = getAlphasOnly(30, "WithSpaces");
        // getline(cin, ReserverAddress);
        replaceCommasWithBackslashes(ReserverAddress);
        cout << " Enter Your CNIC (13 Digits) : ";
        // CNIC = getNumsOnly(13, 1);
        getline(cin, TempInput);
        CNIC = atoll(TempInput.c_str());

        cout << " Enter Your Mobile Number (10 Digits): +92 3";
        MobileNumber = getNumsOnly(9);
        // getline(cin, TempInput);
        // MobileNumber = atoll(TempInput.c_str());

        cout << " Enter Reservation Starting Date --> \n";
        ReservationFromDate.SetDate();
        cout << " Enter Reservation Ending Date --> \n";
        ReservationTillDate.SetDate();
        cout << " Now tell That You'll Pay \n 1:by Card \n 2:On Site ?\n";
        char IMissChoice;
        cin >> IMissChoice;
        // IMissChoice = _getch();
        if (IMissChoice == '1')
        {
            PayByCard = 1;
            CardToBeUsed.setCard();
            cout << " We'll Deduct Amount From This Card if Credentials Came up to be Correct \n You'll be Informed About it " << endl;
        }
        else if (IMissChoice == '2')
        {
            PayByCard = 0;
            cout << " Okay Better!! \n Reservation Created Successfully \n We'll Suggest you to Pay as soon as Possible \n As We Won't Allocate Car Without Payment\n";
        }
        else
        {
            cout << " Wrong Input !! \n No Worries You can Select This Later !! \n In Your Menu After Login \n";
            cout << " By Now \n Reservation Created Successfully \n  We'll Suggest you to Pay as soon as Possible \n As We Won't Allocate Car Without Payment\n";
            PayByCard = -1;
        }
    }
    void DisplayOne()
    {
        cout << " Name : " << ReserverName << endl;
        cout << " Address : " << ReserverAddress << endl;
        cout << " CNIC : " << CNIC << endl;
        cout << " Mobile Number : " << MobileNumber << endl;
        cout << " |========== The Car ";
        ReservedCar.DisplayOne();
        if (PayByCard == 1)
        {
            cout << "\n -- Added Payment Method -- \n";
            CardToBeUsed.DisplayCard();
        }
        else
        {
            cout << " ----------------------------------->\n";
            cout << " No Payment Method Added \n So You'll have to Pay by Visiting Site \n";
            cout << " ----------------------------------->\n";
        }
        Date TempDate;
        cout << " Starts From --> ";
        TempDate = ReservationFromDate;
        TempDate.PrintDate();
        // cout << ReservationFromDate.ReturnDate();
        // cout << endl;
        cout << " Ends At --> ";
        TempDate = ReservationTillDate;
        // cout << ReservationTillDate.ReturnDate();
        TempDate.PrintDate();
        // cout << endl;
    }
    int PayByWhat()
    {
        return PayByCard;
    }
    int PayByWhat(int what)
    {
        PayByCard = what;
    }
    string getReserver()
    {
        return ReserverName;
    }
    bool isPayed()
    {
        return is_payed;
    }
    void AddCardToBeUsed()
    {
        CardToBeUsed.setCard();
    }

    // Constructors
    Reservation()
    {
        ReserverName = "Null";
        ReserverAddress = "Null";
        CNIC = -1;
        MobileNumber = -1;
        CardToBeUsed.setNull();
        is_payed = 0;
        ReservationFromDate.SetNull();
        ReservationTillDate.SetNull();
    }
};

#endif

// Ty photo video Tu enj bhej raha onda Kiday aap development Kiday kuch .
// Bhoojay ich taga nahi ty nahraa day thaikay. Geo zangii tery jiya wi koi nii