#include <iostream>
#include "Company.h"
#include "LoadData.h"

using namespace std;

int main(){
    Company company;
    string d= "drivers.txt";
    string n = "normalDel.txt";
    string e = "expressDel.txt";
    LoadData loadData(company, d, n, e);
    company = loadData.getCompany();
    company.scenery1();
    cout << "HEllo" << endl;
}