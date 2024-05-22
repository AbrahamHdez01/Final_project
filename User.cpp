#include "User.h"

User::User() : id(0), date_joined(time(nullptr)) {}

User::~User() {}

int User::getId() const {
    return id;
}

string User::getUsername() const {
    return username;
}

string User::getPassword() const {
    return password;
}

string User::getRole() const {
    return role;
}

string User::getName() const {
    return name;
}

string User::getLastname() const {
    return lastname;
}

time_t User::getDateJoined() const {
    return date_joined;
}

void User::setId(int id) {
    this->id = id;
}

void User::setUsername(const string& username) {
    this->username = username;
}

void User::setPassword(const string& password) {
    this->password = password;
}

void User::setRole(const string& role) {
    this->role = role;
}

void User::setName(const string& name) {
    this->name = name;
}

void User::setLastname(const string& lastname) {
    this->lastname = lastname;
}

void User::setDateJoined(time_t date_joined) {
    this->date_joined = date_joined;
}

void User::addUser() {
    cout << "Ingrese el ID del usuario: ";
    cin >> id;

    while (cin.fail() || id < 0) {
        cout << "Entrada inválida. Ingrese un ID válido: ";
        cin.clear(); // Limpiar el indicador de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> id;
    }

    int roleOption;
    do {
        cout << "Ingrese el rol del usuario (1 para admin, 2 para cliente): ";
        cin >> roleOption;

        if (roleOption == 1) {
            role = "admin";
            username = "admin";
            password = "admin";
            cout << "Se ha asignado automáticamente el nombre de usuario 'admin' y la contraseña 'admin' para el rol de administrador.\n";
        }
        else if (roleOption == 2) {
            role = "cliente";
            cout << "Ingrese el nombre de usuario: ";
            cin >> username;
            while (cin.fail() || username.length() < 3) {
                cout << "Entrada inválida. El nombre de usuario debe tener al menos 3 caracteres: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> username;
            }
            cout << "Ingrese la contraseña: ";
            cin >> password;
        }
        else {
            cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (roleOption != 1 && roleOption != 2);

    cout << "Ingrese el nombre: ";
    cin >> name;

    cout << "Ingrese el apellido: ";
    cin >> lastname;

    date_joined = time(nullptr);

    saveUserToFile(*this);
}

void User::editUser() {
    int option;
    cout << "Seleccione el campo a editar:\n";
    cout << "1. Nombre de usuario\n";
    cout << "2. Contraseña\n";
    cout << "3. Rol\n";
    cout << "4. Nombre\n";
    cout << "5. Apellido\n";
    cout << "Opción: ";
    cin >> option;

    switch (option) {
    case 1:
        cout << "Ingrese el nuevo nombre de usuario: ";
        cin >> username;
        break;
    case 2:
        cout << "Ingrese la nueva contraseña: ";
        cin >> password;
        break;
    case 3:
        cout << "Ingrese el nuevo rol: ";
        cin >> role;
        break;
    case 4:
        cout << "Ingrese el nuevo nombre: ";
        cin >> name;
        break;
    case 5:
        cout << "Ingrese el nuevo apellido: ";
        cin >> lastname;
        break;
    default:
        cout << "Opción no válida.\n";
        break;
    }

    saveUserToFile(*this);
}

void User::viewUser() const {
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &date_joined);

    cout << "ID: " << id << endl;
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;
    cout << "Role: " << role << endl;
    cout << "Name: " << name << endl;
    cout << "Lastname: " << lastname << endl;
    cout << "Date Joined: " << buffer;
}

void User::deleteUser() {
    string filename = username + ".txt";
    if (remove(filename.c_str()) != 0) {
        cerr << "Error al eliminar el archivo del usuario.\n";
    }
    else {
        cout << "Usuario eliminado.\n";
    }
}

void User::displayMenu() {
    int option;
    do {
        cout << "1. Agregar usuario\n";
        cout << "2. Editar usuario\n";
        cout << "3. Ver usuario\n";
        cout << "4. Eliminar usuario\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> option;

        switch (option) {
        case 1:
            addUser();
            break;
        case 2:
            editUser();
            break;
        case 3:
            viewUser();
            break;
        case 4:
            deleteUser();
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

bool User::isAdmin() const {
    return role == "admin";
}

bool User::loadUserFromFile(User& user, const string& username) {
    ifstream file(username + ".txt");
    if (!file.is_open()) {
        return false;
    }

    file >> user.id >> user.username >> user.password >> user.role >> user.name >> user.lastname >> user.date_joined;
    file.close();
    return true;
}

void User::saveUserToFile(const User& user) {
    string directory = "data";
    string filepath = directory + "/" + user.username + ".txt";

    ofstream file(filepath);
    if (!file.is_open()) {
        cout << "No se pudo guardar el usuario en el archivo." << endl;
        return;
    }

    file << user.id << " " << user.username << " " << user.password << " " << user.role << " "
        << user.name << " " << user.lastname << " " << user.date_joined;
    file.close();
}

void User::initializeDefaultAdmin() {
    if (!usersExist()) {
        User admin;
        admin.setUsername("admin");
        admin.setPassword("admin");
        admin.setRole("admin");
        admin.setName("Administrator");
        admin.setLastname("Admin");
        admin.setDateJoined(time(nullptr));
        saveUserToFile(admin);
    }
}

bool User::usersExist() {
    ifstream file("user.txt");
    if (!file.is_open()) {
        ofstream newFile("user.txt");
        if (newFile.is_open()) {
            cout << "Se creó el archivo 'user.txt'." << endl;
            newFile.close();
            return true;
        }
        else {
            cerr << "No se pudo crear el archivo 'user.txt'." << endl;
            return false;
        }
    }

    file.close();
    return true;
}
