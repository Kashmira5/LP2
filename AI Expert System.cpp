#include <iostream>
#include <string>
using namespace std;
int main() {
    string fever, cough, headache, stomachPain;
    cout << "Welcome to Simple Medical Expert System!\n";
    cout << "Please answer the following questions.\n\n";
    cout << "Do you have a fever (yes/no): ";
    cin >> fever;
    cout << "Do you have a cough (yes/no): ";
    cin >> cough;
    cout << "Do you have a headache (yes/no): ";
    cin >> headache;
    cout << "Do you have stomach pain (yes/no): ";
    cin >> stomachPain;
    cout << "=================================\n";
    cout << " Diagnosis Result\n";
    cout << "=================================\n";

    if (fever == "yes" && cough == "yes" && headache == "yes") {
        cout << "You might have the Flu.\n";
    }
    else if (fever == "yes" && stomachPain == "yes") {
        cout << "You might have Food Poisoning.\n";
    }
    else if (cough == "yes" && fever == "no") {
        cout << "You might have a Common Cold.\n";
    }
    else if (stomachPain == "yes" && fever == "no") {
        cout << "You might have a Stomach Infection.\n";
    }
    else if (fever == "yes" && headache == "yes") {
    cout << "You might have Malaria.\n";
    }
    else {
        cout << "Your symptoms are unclear. Please consult a doctor.\n";
    }

    cout << "\nThank you for using the Medical Expert System.\n";
    return 0;
}
