#include "User.h"
#include "Clients.h"

int main() {

    setlocale(LC_ALL, "spanish");
    User user;
    Clients client;

    int option;
    do {
        cout << "Menú Principal:\n";
        cout << "1. Administrar Usuarios\n";
        cout << "2. Administrar Clientes\n";
        cout << "3. Administrar Productos\n";
        cout << "4. Administrar Ventas\n";
        cout << "5. Informes\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> option;

        switch (option) {
        case 1:
            user.displayMenu();
            break;
        case 2:
            client.displayMenu();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
			cout << "Saliendo...\n";
			exit (EXIT_SUCCESS);
        default:
            cout << "Opción no válida.\n";
            break;
        }
    } while (option != 6);
}

