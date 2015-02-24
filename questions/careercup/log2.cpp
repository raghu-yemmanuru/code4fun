#include <iostream>
#include <cmath>
using namespace std;

double mylog2(double d) {
    unsigned long mask = 1;
    int count = 0;
    while(mask < d) {
        mask <<= 1;
        count++;
    }
    double logLow,logHigh,logMid;
    double Low,High,Mid;

    logLow = count-1;
    logHigh = count;

    Low = (1 << (count-1));
    High = (1 << count);

    //cout << "logLow " << logLow << " " << "logHigh " << logHigh << endl;
    //cout << "Low " << Low << " " << "High " << High << endl;

    while(logLow <= logHigh) {
        logMid = logLow + (logHigh-logLow)/2;
        Mid = sqrt(Low*High);
        if (fabs(Mid-d) <= 0.0001) {
            return logMid;
        } else if (Mid > d) {
            High = Mid;
            logHigh = logMid;
        } else {
            Low = Mid;
            logLow = logMid;
        }
    }
    return logLow;
}

int main() {
    double d;
    cin >> d;
    cout << log2(d) << endl;
    cout << mylog2(d) << endl;
}
