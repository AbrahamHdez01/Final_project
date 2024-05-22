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
        cout << "Seleccione una opción: ";
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
            cout << "Opción no válida.\n";
            break;
        }
    } while (option != 5);
}




void Clients::agregarClientes() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Ingrese el ID del cliente: ";
    while (!(cin >> id) || id <= 0) {
        cout << "Error: Debe ingresar un número entero mayor que 0. Intente nuevamente: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ingrese el nombre del cliente: ";
    cin.ignore();
    getline(cin, name);

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Error: Entrada inválida. El nombre del cliente no pudo ser leído correctamente.\n";
        return;
    }

    cout << "Ingrese el RFC del cliente: ";
    getline(cin, RFC);

    cout << "Ingrese el ID del régimen fiscal: ";
    while (!(cin >> fiscal_regimen_id) || fiscal_regimen_id <= 0) {
        cout << "Error: Debe ingresar un número entero mayor que 0. Intente nuevamente: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ingrese el código del régimen fiscal: ";
    while (!(cin >> fiscal_regimen_code) || fiscal_regimen_code <= 0) {
        cout << "Error: Debe ingresar un número entero mayor que 0. Intente nuevamente: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ingrese el nombre del régimen fiscal: ";
    cin.ignore();
    getline(cin, fiscal_regimen_name);

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Error: Entrada inválida. El nombre del régimen fiscal no pudo ser leído correctamente.\n";
        return;
    }

    cout << "Ingrese la dirección del cliente: ";
    getline(cin, address);

    cout << "Ingrese la ciudad del cliente: ";
    getline(cin, city);

    cout << "Ingrese el estado del cliente: ";
    getline(cin, state);

    cout << "Ingrese el código postal del cliente: ";
    cin >> zip_code;
}

void Clients::mostrarClientes() const {
    cout << "ID: " << id << endl;
    cout << "Nombre: " << name << endl;
    cout << "RFC: " << RFC << endl;
    cout << "ID Régimen Fiscal: " << fiscal_regimen_id << endl;
    cout << "Código Régimen Fiscal: " << fiscal_regimen_code << endl;
    cout << "Nombre Régimen Fiscal: " << fiscal_regimen_name << endl;
    cout << "Dirección: " << address << endl;
    cout << "Ciudad: " << city << endl;
    cout << "Estado: " << state << endl;
    cout << "Código Postal: " << zip_code << endl;
}

void Clients::modificarClientes() {
    int option;
    cout << "Seleccione el campo a editar:\n";
    cout << "1. Nombre\n";
    cout << "2. RFC\n";
    cout << "3. ID Régimen Fiscal\n";
    cout << "4. Código Régimen Fiscal\n";
    cout << "5. Nombre Régimen Fiscal\n";
    cout << "6. Dirección\n";
    cout << "7. Ciudad\n";
    cout << "8. Estado\n";
    cout << "9. Código Postal\n";
    cout << "Opción: ";
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
        cout << "Ingrese el nuevo ID del régimen fiscal: ";
        cin >> fiscal_regimen_id;
        break;
    case 4:
        cout << "Ingrese el nuevo código del régimen fiscal: ";
        cin >> fiscal_regimen_code;
        break;
    case 5:
        cout << "Ingrese el nuevo nombre del régimen fiscal: ";
        cin.ignore();
        getline(cin, fiscal_regimen_name);
        break;
    case 6:
        cout << "Ingrese la nueva dirección: ";
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
        cout << "Ingrese el nuevo código postal: ";
        cin >> zip_code;
        break;
    default:
        cout << "Opción no válida.\n";
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

