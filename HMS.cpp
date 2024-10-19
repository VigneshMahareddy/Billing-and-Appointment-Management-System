#include <bits/stdc++.h>
using namespace std;
class Appointment {
public:
    int appointmentID;
    int patientID;
    string date;
    string time;
    Appointment(int appointmentID, int patientID, string date, string time)
        : appointmentID(appointmentID), patientID(patientID), date(date), time(time) {}
    Appointment() : appointmentID(0), patientID(0), date(""), time("") {}
};
class Bill {
public:
    int billID;
    int patientID;
    double amount;
    Bill(int billID, int patientID, double amount)
        : billID(billID), patientID(patientID), amount(amount) {}
    Bill() : billID(0), patientID(0), amount(0.0) {}
};
class Medicine {
public:
    int medID;
    string name;
    int quantity;
    Medicine(int medID, string name, int quantity)
        : medID(medID), name(name), quantity(quantity) {}

    Medicine() : medID(0), name(""), quantity(0) {}
};
class BillingManagement {
public:
    map<int, Appointment> appointments;
    map<int, Bill> bills;
    map<int, Medicine> medicines;
};
void manageAppointments(BillingManagement& bm) {
    int choice;
    do {
        cout << "\nManage Appointments\n";
        cout << "1. Add Appointment" << endl;
        cout << "2. View Appointments" << endl;
        cout << "3. Return to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int appointmentID, patientID;
                string date, time;
                cout << "Enter Appointment ID: ";
                cin >> appointmentID;
                cout << "Enter Patient ID: ";
                cin >> patientID;
                cout << "Enter Date (YYYY-MM-DD): ";
                cin >> date;
                cout << "Enter Time (HH:MM): ";
                cin >> time;
                bm.appointments[appointmentID] = Appointment(appointmentID, patientID, date, time);
                cout << "Appointment added successfully." << endl;
                break;
            }
            case 2: {
                if (bm.appointments.empty()) {
                    cout << "No appointments to display." << endl;
                } else {
                    for (const auto& [id, appointment] : bm.appointments) {
                        cout << "Appointment ID: " << appointment.appointmentID
                             << ", Patient ID: " << appointment.patientID
                             << ", Date: " << appointment.date
                             << ", Time: " << appointment.time << endl;
                    }
                }
                break;
            }
            case 3:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 3);
}
void manageBills(BillingManagement& bm) {
    int choice;
    do {
        cout << "\nManage Bills\n";
        cout << "1. Add Bill" << endl;
        cout << "2. View Bills" << endl;
        cout << "3. Return to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int billID, patientID;
                double amount;
                cout << "Enter Bill ID: ";
                cin >> billID;
                cout << "Enter Patient ID: ";
                cin >> patientID;
                cout << "Enter Amount: ";
                cin >> amount;
                bm.bills[billID] = Bill(billID, patientID, amount);
                cout << "Bill added successfully." << endl;
                break;
            }
            case 2: {
                if (bm.bills.empty()) {
                    cout << "No bills to display." << endl;
                } else {
                    for (const auto& [id, bill] : bm.bills) {
                        cout << "Bill ID: " << bill.billID
                             << ", Patient ID: " << bill.patientID
                             << ", Amount: $" << bill.amount << endl;
                    }
                }
                break;
            }
            case 3:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 3);
}
void manageMedicines(BillingManagement& bm) {
    int choice;
    do {
        cout << "\nManage Medicines\n";
        cout << "1. Add Medicine" << endl;
        cout << "2. View Medicines" << endl;
        cout << "3. Return to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int medID, quantity;
                string name;
                cout << "Enter Medicine ID: ";
                cin >> medID;
                cout << "Enter Medicine Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Quantity: ";
                cin >> quantity;
                bm.medicines[medID] = Medicine(medID, name, quantity);
                cout << "Medicine added successfully." << endl;
                break;
            }
            case 2: {
                if (bm.medicines.empty()) {
                    cout << "No medicines to display." << endl;
                } else {
                    for (const auto& [id, medicine] : bm.medicines) {
                        cout << "Medicine ID: " << medicine.medID
                             << ", Name: " << medicine.name
                             << ", Quantity: " << medicine.quantity << endl;
                    }
                }
                break;
            }
            case 3:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 3);
}
void mainMenu(BillingManagement& bm) {
    int choice;
    do {
        cout << "\nMain Menu\n";
        cout << "1. Manage Appointments" << endl;
        cout << "2. Manage Bills" << endl;
        cout << "3. Manage Medicines" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                manageAppointments(bm);
                break;
            case 2:
                manageBills(bm);
                break;
            case 3:
                manageMedicines(bm);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);
}
int main() {
    BillingManagement bm;
    mainMenu(bm);
    return 0;
}