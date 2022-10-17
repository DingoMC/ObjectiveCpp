#include <iostream>
#include "employee.h"
#include "developer.h"
#include "teamleader.h"
using namespace std;
void whoWorkForMoreThan5Years (Employee **E, int n) {
    for (int i = 0; i < n; i++) {
        if (E[i]->getExperience() > 5) E[i]->show();
    }
}
int howManyEarnLessThanMeanBonus (Employee **E, int n) {
    float avg = 0.0;
    for (int i = 0; i < n; i++) avg += E[i]->calculateBonus(1);
    avg /= n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (E[i]->calculateBonus(1) < avg) cnt++;
    }
    return cnt;
}
int main () {
    Employee **E;
    E = new Employee*[4];
    E[0] = new Developer("Adamczyk", 21, 3, 6000);
    E[1] = new Developer("Baran", 21, 6, 6200);
    E[2] = new TeamLeader("Basak", 22, 7, 12000);
    E[3] = new TeamLeader("Czarek", 22, 5, 13000);
    whoWorkForMoreThan5Years(E, 3);
    cout<<howManyEarnLessThanMeanBonus(E, 3)<<endl;
    cin.ignore();
    cin.get();
    return 0;
}