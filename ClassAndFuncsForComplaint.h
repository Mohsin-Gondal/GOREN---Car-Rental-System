#ifndef COMPLAINTCLASS_H
#define COMPLAINTCLASS_H
#include <fstream>
#include "Utility.h"
using namespace std;
class Complaint
{
private:
    string Title;
    string Details;
    string ResponseFromAdmin;

public:
    // Member Functions
    void AddComplaint()
    {
        cout << " Give Title (Max 20 Characters): ";

        // getline(cin, Title);
        Title = getAlphasOnly(20, "WithSpaces");
        cout << " Enter Details : ";
        Details = getAlphasOnly(2000, "WithSpaces");
        // getline(cin, Details);
    }
    void DisplayComplaint()
    {
        cout << "\t\t\t -- " << Title << " -- \n";
        cout << Details << endl;
        cout << "\t\t\t -- Response -- \n";
        cout << ResponseFromAdmin << endl;
    }
    void UploadComplaint(ofstream &fout)
    {
        fout << Title << "," << Details << "," << ResponseFromAdmin << endl;
    }
    void DownloadComplaint(string line)
    {
        int pos;
        string token;
        pos = line.find(',');
        token = line.substr(0, pos);
        Title = token;
        line.erase(0, pos + 1);

        pos = line.find(',');
        token = line.substr(0, pos);
        Details = token;
        line.erase(0, pos + 1);

        pos = line.find(',');
        token = line.substr(0, pos);
        ResponseFromAdmin = token;
        line.erase(0, pos + 1);
    }
    // Constructors
    Complaint()
    {
        Title = "NoTitle";
        Details = "NoDetails";
        ResponseFromAdmin = "NoResponseYet";
    }
};

#endif // USERCLASS_H
