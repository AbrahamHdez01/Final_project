#include "Clients.h"

Clients::Clients() : id(0), fiscal_regimen_id(0), fiscal_regimen_code(0) {}

Clients::Clients(int id, const string& name, const string& RFC, int fiscal_regimen_id, int fiscal_regimen_code, const string& fiscal_regimen_name,
    const string& address, const string& city, const string& state, const string& zip_code)
    : id(id), name(name), RFC(RFC), fiscal_regimen_id(fiscal_regimen_id), fiscal_regimen_code(fiscal_regimen_code), fiscal_regimen_name(fiscal_regimen_name), 
    address(address), city(city), state(state), zip_code(zip_code) {}



void Clients::displayMenu() {
    int option = 0;

    do {
        cout << "1. Agregar cliente\n";
        cout << "2. Editar cliente\n";
        cout << "3. Ver cliente\n";
        cout << "4. Eliminar cliente\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opci�n: ";
        cin >> option;

        switch (option) {
        case 1:
            agregarClientes();
            break;
        case 2:
            modificarClientes();
            break;
        case 3:
            mostrarClientes();
            break;
        case 4:
            eliminarClientes();
            break;
        case 5:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opci�n no v�lida.\n";
            break;
        }
    } while (option != 5);
}




void Clients::agregarClientes() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Ingrese el ID del cliente: ";
    while (!(cin >> id) || id <= 0) {
        cout << "Error: Debe ingresar un n�mero entero mayor que 0. Intente nuevamente: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ingrese el nombre del cliente: ";
    cin.ignore();
    getline(cin, name);

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Error: Entrada inv�lida. El nombre del cliente no pudo ser le�do correctamente.\n";
        return;
    }

    cout << "Ingrese el RFC del cliente: ";
    getline(cin, RFC);

    cout << "Ingrese el ID del r�gimen fiscal: ";
    while (!(cin >> fiscal_regimen_id) || fiscal_regimen_id <= 0) {
        cout << "Error: Debe ingresar un n�mero entero mayor que 0. Intente nuevamente: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ingrese el c�digo del r�gimen fiscal: ";
    while (!(cin >> fiscal_regimen_code) || fiscal_regimen_code <= 0) {
        cout << "Error: Debe ingresar un n�mero entero mayor que 0. Intente nuevamente: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ingrese el nombre del r�gimen fiscal: ";
    cin.ignore();
    getline(cin, fiscal_regimen_name);

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Error: Entrada inv�lida. El nombre del r�gimen fiscal no pudo ser le�do correctamente.\n";
        return;
    }

    cout << "Ingrese la direcci�n del cliente: ";
    getline(cin, address);

    cout << "Ingrese la ciudad del cliente: ";
    getline(cin, city);

    cout << "Ingrese el estado del cliente: ";
    getline(cin, state);

    cout << "Ingrese el c�digo postal del cliente: ";
    cin >> zip_code;
}

void Clients::mostrarClientes() const {
    cout << "ID: " << id << endl;
    cout << "Nombre: " << name << endl;
    cout << "RFC: " << RFC << endl;
    cout << "ID R�gimen Fiscal: " << fiscal_regimen_id << endl;
    cout << "C�digo R�gimen Fiscal: " << fiscal_regimen_code << endl;
    cout << "Nombre R�gimen Fiscal: " << fiscal_regimen_name << endl;
    cout << "Direcci�n: " << address << endl;
    cout << "Ciudad: " << city << endl;
    cout << "Estado: " << state << endl;
    cout << "C�digo Postal: " << zip_code << endl;
}

void Clients::modificarClientes() {
    int option;
    cout << "Seleccione el campo a editar:\n";
    cout << "1. Nombre\n";
    cout << "2. RFC\n";
    cout << "3. ID R�gimen Fiscal\n";
    cout << "4. C�digo R�gimen Fiscal\n";
    cout << "5. Nombre R�gimen Fiscal\n";
    cout << "6. Direcci�n\n";
    cout << "7. Ciudad\n";
    cout << "8. Estado\n";
    cout << "9. C�digo Postal\n";
    cout << "Opci�n: ";
    cin >> option;

    cin.ignore();
    switch (option) {
    case 1:
        cout << "Ingrese el nuevo nombre: ";
        getline(cin, name);
        break;
    case 2:
        cout << "Ingrese el nuevo RFC: ";
        cin >> RFC;
        break;
    case 3:
        cout << "Ingrese el nuevo ID del r�gimen fiscal: ";
        cin >> fiscal_regimen_id;
        break;
    case 4:
        cout << "Ingrese el nuevo c�digo del r�gimen fiscal: ";
        cin >> fiscal_regimen_code;
        break;
    case 5:
        cout << "Ingrese el nuevo nombre del r�gimen fiscal: ";
        cin.ignore();
        getline(cin, fiscal_regimen_name);
        break;
    case 6:
        cout << "Ingrese la nueva direcci�n: ";
        getline(cin, address);
        break;
    case 7:
        cout << "Ingrese la nueva ciudad: ";
        getline(cin, city);
        break;
    case 8:
        cout << "Ingrese el nuevo estado: ";
        getline(cin, state);
        break;
    case 9:
        cout << "Ingrese el nuevo c�digo postal: ";
        cin >> zip_code;
        break;
    default:
        cout << "Opci�n no v�lida.\n";
        break;
    }
}


void Clients::eliminarClientes() {
    id = 0;
    name = "";
    RFC = "";
    fiscal_regimen_id = 0;
    fiscal_regimen_code = 0;
    fiscal_regimen_name = "";
    address = "";
    city = "";
    state = "";
    zip_code = "";
    std::cout << "Cliente eliminado.\n";
}

