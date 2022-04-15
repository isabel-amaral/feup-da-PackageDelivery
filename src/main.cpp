#include <iostream>
#include "Company.h"
#include "LoadData.h"
#include "Scenario1.h"

using namespace std;

int main(){
    Company company;
    string d= "drivers.txt";
    string n = "normalDel.txt";
    string e = "expressDel.txt";
    LoadData loadData(company, d, n, e);
    company = loadData.getCompany();
    Scenario1 s1(company);
    cout << "HEllo" << endl;
}