#include "orderio.h"

using namespace std;

// This class is gonna handle reading and writing for 3 different files
// but since the data is always the same, it's always the Order class
// that's getting written, I'll just declare these file name constants
// and use functions to swap between which files to read and write from

const string ORDERED_FILE = "./data/ordered.dat";
const string READY_FILE = "./data/ready.dat";
const string ORDER_HISTORY_FILE = "./data/history.dat";

OrderIO::OrderIO() {
    // It makes the most sense to initialize file with the order file
    file = ORDERED_FILE;
    ifstream fin;
    ofstream fout;
}

vector<Order> OrderIO::read_file() {
    vector<Order> orders;
    file = ORDERED_FILE;
    if (!file_exists()) {
        // If the file doesn't exist, throw an exception
        throw FileExistsException();

    }
    fin.open(file, ios::binary);
    if (fin.is_open()) {
        fin.clear(); // Clear any flags that fin may have set last run
        fin.seekg(0, fin.end);
        int end_position = fin.tellg();
        fin.seekg(0); // Go to the beginning of the file
        int current_position = fin.tellg();
        while (current_position != end_position) {
            // Start with the order details, so we can construct the object
            OrderDetails deets;
            fin.read((char*)(&deets), sizeof(OrderDetails));
            Order order(deets);
            // Next we read the pizzas
            vector<Pizza> pizzas = read_pizzas();
            for (unsigned int i = 0; i < pizzas.size(); i++) {
                order.add_pizza(pizzas[i]);
            }
            int product_count;
            fin.read((char*)(&product_count), sizeof(int));
            Product p;
            for (int i = 0; i < product_count; i++) {
                fin.read((char*)(&p), sizeof(Product));
                order.add_product(p);
            }
            bool priority;
            bool paid;

            fin.read((char*)(&priority), sizeof(bool));
            fin.read((char*)(&paid), sizeof(bool));

            order.set_paid(paid);
            order.set_priority(priority);
            orders.push_back(order);
            current_position = fin.tellg();
        }
        fin.close();
    }
    else {
        throw FileReadException();
    }
    return orders;
}


void OrderIO::write_to_file(Order& order) {
    append(order);
}

void OrderIO::append(Order& order) {
    fout.open(file, ios::binary | ios::app);
    if (fout.is_open()) {
        vector<Pizza> pizzas = order.get_pizzas();
        vector<Product> products = order.get_products();
        OrderDetails details = order.get_details();
        bool priority = order.get_priority();
        bool paid = order.get_paid();

        int n = (int)pizzas.size();
        int m = (int)products.size();

        // Order details written
        fout.write((char*)(&details), sizeof(OrderDetails));
        // How many pizzas are in the order
        fout.write((char*)(&n), sizeof(int));
        for (int i = 0; i < n; i++) {
            write_pizza(pizzas[i]);
        }
        // Next we write the products
        fout.write((char*)(&m), sizeof(int));
        fout.write((char*)(&products[0]), sizeof(Product) * m);
        // Status written
        fout.write((char*)(&priority), sizeof(bool));
        fout.write((char*)(&paid), sizeof(bool));

        fout.close();
    }
    else {
        throw FileWriteException();
    }
}

void OrderIO::write_pizza(Pizza& pizza) {
    // Append a single Pizza class to some file
    char name[128];
    vector<Topping> toppings = pizza.get_toppings();
    int topping_count = toppings.size();
    Base base = pizza.get_base();
    string s = pizza.get_name();
    strcpy(name, s.c_str());
    // Write the name of the pizza
    fout.write((char*)(&name), sizeof(name));
    // Next we write the base
    fout.write((char*)(&base), sizeof(Base));
    // Number of toppings written
    fout.write((char*)(&topping_count), sizeof(int));
    // Write the contents of the toppings vector inside pizza
    fout.write((char*)(&toppings[0]), sizeof(Topping) * topping_count);
}

vector<Pizza> OrderIO::read_pizzas() {
    vector<Pizza> v;
    int number_of_pizzas;
    fin.read((char*)(&number_of_pizzas), sizeof(int));
    for (int i = 0; i < number_of_pizzas; i++) {
        char name[128];
        int topping_count;
        vector<Topping> toppings;
        Topping t;
        Base base;

        fin.read((char*)(&name), sizeof(name)); // Read the name of the pizza
        fin.read((char*)(&base), sizeof(Base)); // Read what base the pizza has

        string s = name;
        Pizza p(s, base);

        fin.read((char*)&topping_count, sizeof(int)); // Read how many toppings to expect
        // TODO: do this in one IO operation
        for (int i = 0; i < topping_count; i++) {
            fin.read((char*)(&t), sizeof(Topping));
            p.add_topping(t);
        }
        v.push_back(p);
    }
    return v;
}
void OrderIO::set_ordered() {
    file = ORDERED_FILE;
}
void OrderIO::set_ready() {
    file = READY_FILE;
}
void OrderIO::set_history() {
    file = ORDER_HISTORY_FILE;;
}

void OrderIO::truncate_file() {
    // Be VERY careful with this function
    if (file == ORDER_HISTORY_FILE) {
        // Truncating the history file is a TERRIBLE idea
        // and should NEVER be done
        return;
    }
    fout.open(file, ios::binary | ios::trunc);
    fout.close();
}

bool OrderIO::file_exists() {
    //Check if the file exists
    ifstream infile(file);
    return infile.good();
}
