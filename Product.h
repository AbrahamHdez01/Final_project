#pragma once
#include <iostream>
#include <string>

using namespace std;

class Presentation {
public:
    Presentation();
    void set_id(int _id);
    int get_id();
    void set_name(string _name);
    string get_name();

private:
    int id;
    string name;
};

class Product {
public:
    Product();
    void set_id(int _id);
    int get_id();
    void set_UPC(string _UPC);
    string get_UPC();
    void set_name(string _name);
    string get_name();
    void set_presentation(const Presentation& _presentation);
    Presentation get_presentation();
    void set_price(float _price);
    float get_price();
    void set_cost(float _cost);
    float get_cost();
    void set_has_iva(bool _has_iva);
    bool get_has_iva();
    void set_stock(int _stock);
    int get_stock();

    void add_product();
    void see_product();
    void edit_product();
    void delete_product();

private:
    int id;
    string UPC;
    string name;
    Presentation presentation;
    float price;
    float cost;
    bool has_iva;
    int stock;
    int presentation_id;
};
