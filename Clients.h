#pragma once
#include <string>
#include <iostream>
#include <limits> 

using namespace std;

class Clients {
public:
    Clients();
    Clients(int id, const string& name, const string& RFC, int fiscal_regimen_id, int fiscal_regimen_code, const string& fiscal_regimen_name, const string& address, const string& city, const string& state, const string& zip_code);

    void agregarClientes();
    void mostrarClientes() const;
    void modificarClientes();
    void eliminarClientes();
    void displayMenu();

    
    int getId() const { return id; }
    void setId(int id) { this->id = id; }

    const string& getName() const { return name; }
    void setName(const string& name) { this->name = name; }

    const string& getRFC() const { return RFC; }
    void setRFC(const string& RFC) { this->RFC = RFC; }

    int getFiscalRegimenId() const { return fiscal_regimen_id; }
    void setFiscalRegimenId(int fiscal_regimen_id) { this->fiscal_regimen_id = fiscal_regimen_id; }

    int getFiscalRegimenCode() const { return fiscal_regimen_code; }
    void setFiscalRegimenCode(int fiscal_regimen_code) { this->fiscal_regimen_code = fiscal_regimen_code; }

    const string& getFiscalRegimenName() const { return fiscal_regimen_name; }
    void setFiscalRegimenName(const string& fiscal_regimen_name) { this->fiscal_regimen_name = fiscal_regimen_name; }

    const string& getAddress() const { return address; }
    void setAddress(const string& address) { this->address = address; }

    const string& getCity() const { return city; }
    void setCity(const string& city) { this->city = city; }

    const string& getState() const { return state; }
    void setState(const string& state) { this->state = state; }

    const string& getZipCode() const { return zip_code; }
    void setZipCode(const string& zip_code) { this->zip_code = zip_code; }

private:
    // Variables miembro
    int id;
    string name;
    string RFC;
    int fiscal_regimen_id;
    int fiscal_regimen_code;
    string fiscal_regimen_name;
    string address;
    string city;
    string state;
    string zip_code;
};
