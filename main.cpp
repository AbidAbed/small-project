#pragma comment(lib, "Urlmon.lib") 
#include <urlmon.h>
#include <cstdio>
#include <iostream>   
#include <string>
#include <json\value.h>
#include <json\json.h>
#include<fstream>
using namespace std;
struct Actors {
private:
     string name, age, bornat, birthday;
public:
    Actors(string name, string age, string bornat, string birthday) {
        Actors::name = name;
        Actors::age = age;
        Actors::bornat = bornat;
        Actors::birthday = birthday;
    }
};
int main()
{
   
    IStream* DATA;
    string jsondata;
    unsigned long bytesRead;
    const char* URL = "https://mqplanet.com/test.json";
    
   
    if (S_OK != URLOpenBlockingStreamA(0, URL, &DATA, 0, 0))
    {
        cout << "ERROR"; 
        return -1;
    }
    char buff[100];

    
    
    while (true) {
        DATA->Read(buff, 100, &bytesRead);
        if (0U == bytesRead)
            break;
        
        jsondata.append(buff, bytesRead);
    };
    DATA->Release();
    //cout << jsondata << endl;
    ofstream jsonfile;
    jsonfile.open("jsondata.json", ios::out);
    jsonfile << jsondata;
    jsonfile.close();

    Json::Reader reader;
    Json::Value root;

    reader.parse(jsondata, root, false);
    auto actors = root["Actors"];
    
        auto el = actors[0];
        string data1 = el["name"].asString();
        string data2 = el["age"].asString();
        string data3 = el["Born At"].asString();
        string data4 = el["Birthdate"].asString();
        auto el2 = actors[1];
        string data11 = el2["name"].asString();
        string data22 = el2["age"].asString();
        string data33 = el2["Born At"].asString();
        string data44 = el2["Birthdate"].asString();
        Actors actor1(data1, data2, data3, data4), actor2(data11, data22, data33, data44);

        cout << "Actor 1\n" << "name :" << data1 << "\nage :" << data2 << "\nBorn At" << data3 << "\nBirthday" << data4 << "\nactor2\n" <<
            "name :" << data11 << "\nage :" << data22 << "\nBorn At" << data33 << "\nBirthday" << data44 << endl;
 
    
    
}