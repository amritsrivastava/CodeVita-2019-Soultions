#include<bits/stdc++.h>
using namespace std;

void calcLead(int *lead, int *count, int n) {
    int max = lead[0];
    for(int i=0; i<n ; i++) {
        if(max < lead[i]) {
            max = lead[i];
        }        
    }

    for(int i=0; i<n; i++) {
        if(lead[i] == max) {
            count[i]++;
        }
    }
}

int main() {
    int n, T;
    cin >> n >> T;
    int players[n][T];
    int lead[n], count[n], distance[n];

    memset(lead, 0, sizeof lead);
    memset(count, 0, sizeof lead);

    for(int i=0; i<n; i++) {
        for(int j=0; j<T; j++) {
            cin >> players[i][j];
        }
        cin >> distance[i];
    }

    if(T%2 != 0) {
        T--;
    }

    for(int i=0; i<T; i=i+2) {
        for(int j=0; j<n; j++) {
            lead[j] += (players[j][i]+players[j][i+1])*distance[j];
        }
        calcLead(lead, count, n);
    }

    int maxLeadCount = count[0];
    for(int i=0; i<n; i++) {
        if(count[i] >= maxLeadCount) {
            maxLeadCount = count[i];
        }
    }

    for(int i=0; i<n; i++) {
        if(count[i] == maxLeadCount) {
            cout << i+1;
            break;
        }
    }
    return 0;
}
