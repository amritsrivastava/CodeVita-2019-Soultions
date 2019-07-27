#include<bits/stdc++.h>
using namespace std;

float getAngle(int hourHand, float minuteHand) {
    if (minuteHand == 60) {
        minuteHand = 0;   
    }
    if( hourHand == 12) {
        hourHand = 0;  
    }
    float hourAngle = (hourHand * 60 + minuteHand) * 0.5;
    float minuteAngle = minuteHand * 6;  
    float clockAngle = abs(hourAngle - minuteAngle);  
    clockAngle = min(clockAngle, 360 - clockAngle);  
    return clockAngle;  
}

int main() {
    int period;
    float longitude;
    cin >> period >> longitude;
    float timeDiff = (period/360.0)*longitude;
    int hourHand = timeDiff;
    float minuteHand = (timeDiff - hourHand)*60;
    cout << setprecision(2)<< fixed << getAngle((hourHand % 12), minuteHand);
    return 0;
}
