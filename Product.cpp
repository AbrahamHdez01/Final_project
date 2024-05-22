#include "Product.h"
#include <iostream>


Presentation::Presentation() {
    id = 0;
    name = "";
}

void Presentation::set_id(int _id) {
    id = _id;
}

int Presentation::get_id() {
    return id;
}

void Presentation::set_name(string _name) {
    name = _name;
}

string Presentation::get_name() {
    return name;
}


Product::Product() {
    id = 0;
    UPC = "";
    name = "";
    price = 0.0f;
    cost = 0.0f;
    has_iva = false;
    stock = 0;
}

void Product::set_id(int _id) {
    id = _id;
}

int Product::get_id() {
    return id;
}

void Product::set_UPC(string _UPC) {
    UPC = _UPC;
}

string Product::get_UPC() {
    return UPC;
}

void Product::set_name(string _name) {
    name = _name;
}

string Product::get_name() {
    return name;
}

void Product::set_presentation(const Presentation& _presentation) {
    presentation = _presentation;
}

Presentation Product::get_presentation() {
    return presentation;
}

void Product::set_price(float _price) {
    price = _price;
}

float Product::get_price() {
    return price;
}

void Product::set_cost(float _cost) {
    cost = _cost;
}

float Product::get_cost() {
    return cost;
}

void Product::set_has_iva(bool _has_iva) {
    has_iva = _has_iva;
}

bool Product::get_has_iva() {
    return has_iva;
}

void Product::set_stock(int _stock) {
    stock = _stock;
}

int Product::get_stock() {
    return stock;
}

void Product::add_product() {
    cout << "Ingrese el ID del producto: ";
    cin >> id;

    cout << "Ingrese el UPC del producto: ";
    cin >> UPC;

    cout << "Ingrese el nombre del producto: ";
    cin.ignore();
    getline(cin, name);

    cout << "Ingrese el ID de la presentación asociada: ";
    cin >> presentation_id;

    cout << "Ingrese el precio del producto: ";
    cin >> price;

    cout << "Ingrese el costo por unidad del producto: ";
    cin >> cost;

    cout << "¿El precio del producto incluye IVA? (1 para Sí, 0 para No): ";
    cin >> has_iva;

    cout << "Ingrese la cantidad disponible del producto: ";
    cin >> stock;

    cout << "Producto agregado exitosamente.\n";
}

void Product::see_product() {
    cout << "ID del producto: " << id << "\n";
    cout << "UPC del producto: " << UPC << "\n";
    cout << "Nombre del producto: " << name << "\n";
    cout << "ID de la presentación asociada: " << presentation_id << "\n";
    cout << "Precio del producto: " << price << "\n";
    cout << "Costo por unidad del producto: " << cost << "\n";
    cout << "¿El precio del producto incluye IVA? " << (has_iva ? "Sí" : "No") << "\n";
    cout << "Cantidad disponible del producto: " << stock << "\n";
}

void Product::edit_product() {
    cout << "Ingrese el nuevo nombre del producto: ";
    cin.ignore();
    getline(cin, name);

    cout << "Ingrese el nuevo precio del producto: ";
    cin >> price;

    cout << "Ingrese el nuevo costo por unidad del producto: ";
    cin >> cost;

    cout << "¿El precio del producto incluye IVA? (1 para Sí, 0 para No): ";
    cin >> has_iva;

    cout << "Ingrese la nueva cantidad disponible del producto: ";
    cin >> stock;

    cout << "Producto editado exitosamente.\n";
}
