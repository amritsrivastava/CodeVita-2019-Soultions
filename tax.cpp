#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<unsigned int> taxSlabs;
    vector<unsigned int> taxRate;
    vector<unsigned int> empTax;
    vector<unsigned int> taxDiff;
    unsigned int rebate;
    unsigned int buffer, tempDiff=0;
    char temp;
    do {
        scanf("%d%c", &buffer, &temp);
        taxSlabs.push_back(buffer - tempDiff);
        tempDiff = buffer;
    } while(temp != '\n');

    taxRate.push_back(0);
    for(unsigned int i=1; i<=taxSlabs.size(); i++) {
        cin>> buffer;
        taxRate.push_back(buffer);
    }

    cin >> rebate;
    
    do {
        scanf("%d%c", &buffer, &temp);
        empTax.push_back(buffer);
    } while(temp != '\n');

    for(unsigned int i=0; i<taxSlabs.size(); i++) {
        taxDiff.push_back((taxSlabs[i]*taxRate[i])/100);
    }

    unsigned int totalSalaryToPay = 0;
    for(unsigned int i=0; i<empTax.size(); i++) {
        unsigned int totalTax = 0, salary = 0, taxRemain = empTax[i]; 
        for(unsigned int j=0; j<taxDiff.size(); j++) {
            if(empTax[i]>=taxDiff[j]) {
                totalTax += taxDiff[j];
                salary += taxSlabs[j]; 
                taxRemain -= taxDiff[j];
            } else {
                break;
            }
        }
        if(taxRemain>0) {
            salary += ((taxRemain)*100)/taxRate[taxRate.size()-1]; 
        }
        totalSalaryToPay += salary + rebate;
    }
    cout << totalSalaryToPay;
    return 0;
}