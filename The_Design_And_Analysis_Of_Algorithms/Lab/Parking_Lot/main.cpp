#include <iostream>
#include <vector>
using namespace std;

struct Car{
    int id, In, Out;
};

void inputList(int &n, vector<Car> &listCar) {
    cout << "Enter number Car: "; cin >> n;
    for(int i = 0; i < n; i++) {
        Car x;
        x.id = i;
        cout << "Enter in: "; cin >> x.In;
        cout << "Enter out: "; cin >> x.Out;
        cout << endl;
        listCar.push_back(x);
    }
}

void timeMostCar(int n, vector <Car> listCar, int time[]) {
    for(int i = 0; i < n; i++) {
        for(int j = listCar[i].In; j <= listCar[i].Out; j++) {
            time[j]++;
        }
    }

    int Max = 0;
    for(int i = 0; i < 24; i++) {
        if(Max < time[i]) {
            Max = time[i];
        }
    }

    cout << "The maximum number of cars in the parking lot at the hour is: ";
    for(int i = 0; i < 24; i++) {
        if(Max == time[i]) {
            cout << i << " ";
        }
    }
}

void avgTimeParking(int n, vector <Car> listCar) {
    cout << endl;
    double totalTime = 0;
    for(int i = 0; i < n; i++) {
        totalTime += (listCar[i].Out - listCar[i].In);
    }
    cout << "Average parking time: " << totalTime/n*1.0;
}

int main()
{
    int n;
    int time[24] = {0};
    vector <Car> listCar;
    inputList(n, listCar);
    timeMostCar(n, listCar, time);
    avgTimeParking(n, listCar);
    return 0;
}
