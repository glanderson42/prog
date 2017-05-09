#include "function.h"

using namespace std;

void echoTask() {
    cout << right << setw(13) << "Madarak eletenek kutatasaval foglalkozo szakemberek n kulonbozo telepulesen m" << endl;
    cout << right << setw(13) << "kulonbozo madarfaj elofordulasat tanulmanyozzak. Egy adott idoszakban megszamoltak," << endl;
    cout << right << setw(13) << "hogy az egyes telepulesen egy madarfajnak hany egyedevel talalkoztak. Volt-e olyan " << endl;
    cout << right << setw(13) << "telepules, ahol mindegyik madarfaj elofordul?" << endl;
}

void readFromFile(vector<vector<int> > &data) {
    try {
        loadFromFile(data);
        if(existsVillageWithAllBirds(data)) {
            cout << data;
            cout << "Van" << endl;
        }else {
            cout << data;
            cout << "Nincs" << endl;
        }
    }catch(Exception e) {
        switch(e) {
            case NC: {
                cout << "Negative Count" << endl;
                break;
            }
            case WI: {
                cout << "Wrong Input" << endl;
                break;
            }
            case WV: {
            cout << "Wrong Value" << endl;
            break;
            }
        }
    }
}

void readFromStandardInput(vector<vector<int> > &data) {
    try{
        standardInput(data);
        if(existsVillageWithAllBirds(data)) {
            cout << "Van" << endl;
        }else {
            cout << "Nincs" << endl;
        }
    }catch(Exception e) {
        switch(e) {
            case NC: {
                cout << "Negative Count" << endl;
                break;
            }
            case WI: {
                cout << "Wrong Input" << endl;
                break;
            }
            case WV: {
            cout << "Wrong Value" << endl;
            break;
            }
        }
    }
}
