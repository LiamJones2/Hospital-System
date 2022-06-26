// Hospital System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

string patientsName[21][5];
int patientsSpecialization[21][5];
int patientsStatus[21][5];

void newPatient() {
    &patientsName;
    &patientsSpecialization;
    &patientsStatus;
    string name;
    int specialization, status;
    cout << "Please enter specialization(1-21): ";
    cin >> specialization;
    while (true) {
        if (specialization >= 1 && specialization <= 21)
            break;
        cout << "Please make sure to only enter 1-21\n";
        cin >> specialization;
    }
    if (patientsSpecialization[specialization - 1][4] != 0) {
         cout << "Unfortunately we are unable to accept any more patients for that specialist\n";
         return;
    }
    cout << "Please enter your name: ";
    cin >> name;
    cout << "Please enter your status(0 for regular or 1 for urgent): ";
    cin >> status;
    while (true) {
        if (status == 0 || status == 1)
            break;
        cout << "Please make sure to only enter 0 for regular or 1 for urgent\n";
        cin >> status;
    }
    if (status == 1) {
        for (int i = 0; i < 5; i++) {
            if (patientsSpecialization[specialization-1][i] != 0 && patientsStatus[specialization - 1][i] == 0) {
                for (int j = 4; j > i; j--) {
                    patientsName[specialization - 1][j] = patientsName[specialization - 1][j - 1];
                    patientsSpecialization[specialization - 1][j] = patientsSpecialization[specialization - 1][j - 1];
                    patientsStatus[specialization - 1][j] = patientsStatus[specialization - 1][j - 1];
                }
                patientsName[specialization - 1][i] = name;
                patientsSpecialization[specialization - 1][i] = specialization;
                patientsStatus[specialization - 1][i] = status;
                return;
            }
        }
        for (int i = 0; i < 5; i++) {
            if (patientsStatus[specialization-1][i] == 0) {
                patientsStatus[specialization - 1][i] = status;
                patientsName[specialization - 1][i] = name;
                patientsSpecialization[specialization - 1][i] = specialization;
                return;
            }
        }
        
    }
    if (status == 0) {
        for (int i = 0; i < 5; i++) {
            if (patientsSpecialization[specialization - 1][i] == 0) {
                patientsStatus[specialization - 1][i] = status;
                patientsName[specialization - 1][i] = name;
                patientsSpecialization[specialization - 1][i] = specialization;
                return;
            }
        }
    }
    
    
}

void printAllPatients() {
    &patientsName;
    &patientsSpecialization;
    &patientsStatus;    
    for (int i = 0; i < 21; i++) {
        int count = 0;
        for(int j = 0; j < 5; j++)
            if (patientsSpecialization[i][j] != 0) {
                count++;
            }
        if (count > 0) {
            cout << "******************************************\n";
            if (count == 1)
                cout << "There is one patient in specialization " << i + 1 << "\n";
            else
                cout << "There are " << count << " patients in specialization " << i + 1 << "\n";
            int j = 0;
            for (; count > 0; count--) {

                for (; j < count; j++) {
                    cout << patientsName[i][j] << " ";
                    if (patientsStatus[i][j] == 1)
                        cout << "urgent\n";
                    else
                        cout << "regular\n";
                }
            }
        }
    }
}

void getNextPatient() {
    &patientsName;
    &patientsSpecialization;
    &patientsStatus;
    cout << "Welcome Doctor. Please type the specialization\n";
    int specialization;
    cin >> specialization;
    if (patientsSpecialization[specialization - 1][0] != 0) {
        cout << "ANNOUNCEMENT!: Can " << patientsName[specialization - 1][0] << " go with the doctor please\n";
        for (int i = 1; i < 5; i++) {
            patientsSpecialization[specialization - 1][i - 1] = patientsSpecialization[specialization - 1][i];
            patientsName[specialization - 1][i - 1] = patientsName[specialization - 1][i];
            patientsStatus[specialization - 1][i - 1] = patientsStatus[specialization - 1][i];
        }
        patientsSpecialization[specialization - 1][4] = 0;
        patientsName[specialization - 1][4] = "0";
        patientsStatus[specialization - 1][4] = 0;
    }
    else
        cout << "There is no one else waiting under specialization: " << specialization << "\n";
    
}


bool getChoice() {
    cout << "1) Add new patient \n";
    cout << "2) Print all patients \n";
    cout << "3) Get next patient \n";
    cout << "4) Exit \n";
    string choice;
    cin >> choice;
    if (choice == "1")
        newPatient();
    else if (choice == "2")
        printAllPatients();
    else if (choice == "3")
        getNextPatient();
    else if (choice == "4")
        return false;
    else 
        cout << "Sorry we didn't understand that\n";
    
}


int main()
{
    bool run = true;
    while (run)
        run = getChoice();
    cout << "Goodbye! :)";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
