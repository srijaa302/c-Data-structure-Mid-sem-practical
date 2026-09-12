#include <iostream>
#include <iomanip>
using namespace std;
class Product {
public:
    string id, name;
    float price;
    int qty;
};
int main() {
    Product p[40];
    int n = 0, choice;
    float revenue = 0;
    do {
        cout<<"\n===== Inventory Tracker =====\n";
        cout<<"1. Add Product\n";
        cout<<"2. Restock Product\n";
        cout<<"3. Sell Product\n";
        cout<<"4. Low Stock\n";
        cout<<"5. Revenue\n";
        cout<<"6. Display All\n";
        cout<<"7. Exit\n";
        cout<<"Enter choice: ";
        cin>> choice;
        switch (choice) {

        case 1: {
            string id;
            cout << "ID: ";
            cin >> id;
            bool exists = false;
            for (int i = 0; i < n; i++) {
                if (p[i].id == id)
                    exists = true;
            }
            if (exists) {
                cout << "Product ID already exists\n";
                break;
			}
            p[n].id = id;
            cout << "Name: ";
            cin >> p[n].name;
            cout << "Price: ";
            cin >> p[n].price;
            cout << "Quantity: ";
            cin >> p[n].qty;
            n++;
            cout << "Product added.\n";
            break;
        }

        case 2: {
            string id;
            int q;
            cout << "Product ID: ";
            cin >> id;

            for (int i = 0; i < n; i++) {
                if (p[i].id == id) {
                    cout << "Quantity to restock: ";
                    cin >> q;
                    p[i].qty += q;
                    cout << "Product restocked.\n";
                }
            }
            break;
        }

        case 3: {
            string id;
            int q;
            cout << "Product ID: ";
            cin >> id;
            for (int i = 0; i < n; i++) {
                if (p[i].id == id) {
                    cout << "Quantity to sell: ";
                    cin >> q;

                    if (q > p[i].qty) {
                        cout << "Not enough stock\n";
                    } else {
                        p[i].qty -= q;
                        revenue += p[i].price * q;

                        cout << fixed << setprecision(2);
                        cout << "Sold. Revenue from this sale: "
                             << p[i].price * q << endl;
                    }
                }
            }
            break;
        }

        case 4: {
            bool found = false;

            for (int i = 0; i < n; i++) {
                if (p[i].qty < 5) {
                    cout << p[i].id << " "
                         << p[i].name << " "
                         << p[i].price << " "
                         << p[i].qty << endl;
                    found = true;
                }
            }

            if (!found)
                cout << "No low-stock products\n";
            break;
        }

        case 5:
            cout << fixed << setprecision(2);
            cout << "Total Revenue: " << revenue << endl;
            break;

        case 6:
            for (int i = 0; i < n; i++) {
                cout << p[i].id << " "
                     << p[i].name << " "
                     << p[i].price << " "
                     << p[i].qty << endl;
            }
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 7);

    return 0;
}
