#ifndef CARCLASS_H
#define CARCLASS_H
#include <iostream>
#include "Utility.h"
// #include "ClassAndFuncsForReservation.h"
int CarsEntryCounter = 0;
int IDCounter = 23021519;
class NumberPlate
{
    string Alphas;
    int Nums;
    int Mod;

public:
    // Member Functions
    void SetNumPlate()
    {
        cout << "-- Registration Details --\n";
        cout << " Alphabets (XYZ) : ";
        Alphas = getAlphasOnly(3);
        Alphas = toUpperCase(Alphas);
        cout << " Numbers (0000) : ";
        Nums = getNumsOnly(4);
        cout << " Model Year (00) : ";
        Mod = getNumsOnly(2);
        Alphas = toUpperCase(Alphas);
    }
    void SetNumPlate(string alpha, int noma, int moda)
    {
        Alphas = alpha;
        Nums = noma;
        Mod = moda;
    }
    void SetNull()
    {
        Alphas = "NoAlpha";
        Nums = -1;
        Mod = -1;
    }
    void DisplayNumberPlate()
    {
        cout << "| " << Alphas << " | " << Nums << " | " << Mod << " | \n";
    }
    string getAlpha()
    {
        return Alphas;
    }
    string getNums()
    {
        return to_string(Nums);
    }
    string getMod()
    {
        return to_string(Mod);
    }
    int getMod(int IntegerCheckVarOverLoadDataType)
    {
        return Mod;
    }
    // Constructors
    NumberPlate()
    {
        Alphas = "NAS";
        Nums = 7421;
        Mod = 12;
    }
    NumberPlate(string alpha, int num, int mod)
    {
        Alphas = alpha;
        Nums = num;
        Mod = mod;
    }
};

// we Could have used Vehicles in place of cars but i don't think
// we've to inherit cars from vehicles cause both contain almost same properties
class Cars
{
    int ID;
    string Make;
    string Model;
    string color;
    NumberPlate OfCar;

public:
    // Member Functions
    string getMake()
    {
        return Make;
    }
    string getModel()
    {
        return Model;
    }
    string getColor()
    {
        return color;
    }
    int getRegistrationYear()
    {
        int Res = OfCar.getMod(-1);
        return Res;
    }
    void AddCar()
    {
        system("cls");
        ID = IDCounter + CarsEntryCounter;
        cout << " Enter Car Make (Compnay Name) : ";
        getline(cin, Make);
        // cin >> Make;
        cout << " Enter Car Model : ";
        getline(cin, Model);
        // cin >> Model;
        OfCar.SetNumPlate();
        cout << " What's It's Color : ";
        getline(cin, color);
        // cin >> color;
        color = toUpperCase(color);
    }
    void DisplayOne()
    {
        cout << "==========|\n";
        cout << " ===============================================>\n";
        cout << " Registration Number ----> ";
        OfCar.DisplayNumberPlate();
        cout << " ===============================================>\n";
        cout << " Details ---->";
        cout << " ID : " << ID << "\n Company : " << Make << " | ";
        cout << " Model : " << Model << "(" << color << ")" << endl;
        cout << " ===============================================>\n";
        // cout << " ===============================================>\n";

        cout << "==========|\n";
    }
    void DownloadOne(string line)
    {
        int pos;
        string token;
        pos = line.find(',');
        token = line.substr(0, pos);
        ID = atoi(token.c_str());
        line.erase(0, pos + 1);
        pos = line.find(',');
        token = line.substr(0, pos);
        Make = token;
        line.erase(0, pos + 1);
        pos = line.find(',');
        token = line.substr(0, pos);
        Model = token;
        line.erase(0, pos + 1);

        string alpha;
        int num;
        int mod;

        pos = line.find(',');
        token = line.substr(0, pos);
        alpha = token;
        line.erase(0, pos + 1);

        pos = line.find(',');
        token = line.substr(0, pos);
        num = atoi(token.c_str());
        line.erase(0, pos + 1);

        pos = line.find(',');
        token = line.substr(0, pos);
        mod = atoi(token.c_str());
        line.erase(0, pos + 1);
        OfCar.SetNumPlate(alpha, num, mod);

        pos = line.find(',');
        token = line.substr(0, pos);
        color = token;
        line.erase(0, pos + 1);
    }
    void UploadOne()
    {
        ofstream fout("Cars.txt", ios::app);
        fout << ID << "," << Make << "," << Model << "," << OfCar.getAlpha() << "," << OfCar.getNums() << "," << OfCar.getMod() << "," << color << endl;
    }
    // For Reservations
    // void UploadOne(ofstream &fout)
    // {
    //     ofstream fout("ReservedCars.txt", ios::app);
    //     fout << ID << "," << Make << "," << Model << "," << OfCar.getAlpha() << "," << OfCar.getNums() << "," << OfCar.getMod() << "," << color << endl;
    //     fout.close();
    // }
    void UploadOne(ofstream &fout)
    {
        fout << ID << "," << Make << "," << Model << "," << OfCar.getAlpha() << "," << OfCar.getNums() << "," << OfCar.getMod() << "," << color << endl;
    }
    void setNull()
    {
        ID = -1;
        Make = "NoCompany";
        Model = "NoModel ";
        color = "NoColor";
    }
    // Constructors#
    Cars()
    {
        ID = -1;
        Make = "NoCompany";
        Model = "NoModel ";
        color = "NoColor";
        // OfCar.SetNull();
    }
};
Cars AvailabeCars[100];
Cars ReservedCars[100];
int ReservedCarsCounter = 0;

// Functions For This Array
void LoadAvailableCars()
{
    string line;
    ifstream fin("Cars.txt");
    getline(fin, line);
    CarsEntryCounter = atoi(line.c_str());
    cout << " Total : " << CarsEntryCounter << " : Cars are there \n And Have been Loaded" << endl;
    if (CarsEntryCounter > 0)
    {

        for (int i = 0; i < CarsEntryCounter; i++)
        {
            getline(fin, line);
            AvailabeCars[i].DownloadOne(line);
        }
    }
    fin.close();
}
void LoadReservedCars()
{
    string line;
    ifstream fin("ReservedCars.txt");
    getline(fin, line);
    ReservedCarsCounter = atoi(line.c_str());
    cout << " Total : " << ReservedCarsCounter << " : Cars are there \n And Have been Loaded" << endl;
    if (ReservedCarsCounter > 0)
    {

        for (int i = 0; i < ReservedCarsCounter; i++)
        {
            getline(fin, line);
            ReservedCars[i].DownloadOne(line);
        }
    }

    fin.close();
}
// Loading Functions is Integrated
// I'll not integreat the UpdateCars Functions cause it's access is to Admin only

void UpdateCarsFile()
{
    ofstream fout("Cars.txt");
    fout << CarsEntryCounter << endl;
    // cout << " CECounter is : " << CarsEntryCounter << endl;
    for (int i = 0; i < CarsEntryCounter; i++)
    {
        AvailabeCars[i].UploadOne();
    }
    // cout << " Reserved Car Update loop Ended \n";
    fout.close();
}

void UpdateReservedCarsFile()
{
    ofstream fout("ReservedCars.txt");
    fout << ReservedCarsCounter << endl;
    // cout << ReservedCarsCounter << " RCC Counter is : This " << endl;
    for (int i = 0; i < ReservedCarsCounter; i++)
    {
        ReservedCars[i].UploadOne(fout);
    }
    // cout << " Reserved Car Update loop Ended \n";
    fout.close();
}

void SortAvailableCarsAfterReservation(int CarIndex)
{
    for (int i = CarIndex; i < CarsEntryCounter; i++)
    {
        AvailabeCars[i] = AvailabeCars[i + 1];
    }
}
#endif