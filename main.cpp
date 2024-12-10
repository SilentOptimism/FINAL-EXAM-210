#include <iostream>
#include <chrono>
#include <deque>
#include <vector>

using namespace std;
using namespace std::chrono;


// Used chatgpt to generate the random people names
string names[50] = {
    "Alice", "Bob", "Charlie", "David", "Emily",
    "Frank", "Grace", "Henry", "Iris", "Jack",
    "Kelly", "Liam", "Mia", "Noah", "Olivia",
    "Penelope", "Quentin", "Riley", "Sophia", "Thomas",
    "Uma", "Victor", "Wendy", "Xavier", "Yara",
    "Zachary", "Abigail", "Benjamin", "Chloe", "Daniel",
    "Eleanor", "Finn", "Georgia", "Harper", "Isaac",
    "Jasmine", "Kai", "Lena", "Mason", "Nora",
    "Oscar", "Piper", "Quinn", "Riley", "Samuel", "Peter",
    "Hunter", "Alexandra", "Michelle", "Mark" 
};

// Used chatgpt to generate the drink types
string drinks[10] = {
        "Coffee", "Tea", "Water", "Juice", "Soda",
        "Milk", "Wine", "Beer", "Cocktail", "Hot Chocolate"
};

// Used chatgpt to generate the muffin types
string muffins[10] = {
        "Blueberry", "Chocolate Chip", "Banana Nut", "Cranberry Orange", "Lemon Poppy Seed",
        "Pumpkin Spice", "Double Chocolate", "Rainbow", "Bran", "Apple Cinnamon"
};

// Used chatgpt to generate the friendship bracelet types
string bracelets[10] = {
        "Chevron bracelet", "Friendship bracelet", "Shamballa bracelet", "Chainmaille bracelet", "Beaded bracelet", 
        "Knotted bracelet", "Embroidered bracelet", "Woven bracelet", "Macrame bracelet", "Sennit bracelet"
};

struct Node{
    string customerName;
    string product;
    Node* next;

    Node(string name, string item){
        customerName = name;
        product = item;
        next = NULL;
    }
    
};

class CoffeeBooth{
private:
    Node* head = NULL;

public:
    void pop_front(){
        if(head != NULL){
            cout << head->customerName << " was served " << head->product << endl;
            Node* temp = head->next;
            delete head;
            head = temp;
        }
    }

    void push_back(string customerName, string product){
        if(!head ){
            head = new Node(customerName,product);
        }
        else{
            Node* curr = head;

            while (curr->next != NULL ){
                curr = curr->next;
            }
            curr->next = new Node(customerName, product);
        }
    }

    void push_back_rand(){
        string randName = names[rand() % 50];
        string randDrink = drinks[rand() % 10];

        push_back(randName, randDrink);
    }

    void display(){
        if(head!=NULL){
            Node* curr = head;

            while(curr!= NULL){
                cout << curr->customerName << " wants " << curr->product << endl;
                curr = curr->next;
            }
        }
        else{
            cout << "Cafe is Empty" << endl;
        }
    }

};

class MuffinBooth{
private:
    deque<string> Customer;
    deque<string> Order;

public:
    void push_back_rand(){
        Customer.push_back(names[rand()%50]);
        Order.push_back(muffins[rand()%10]);
    }

    void pop_front(){
        if(!Customer.empty()){
            cout << Customer.front() << " was served " << Order.front() << endl;
            Customer.pop_front();
            Order.pop_front();
        }
    }

    void display(){
        if(!Customer.empty()){
            deque<string>::iterator currOrder = Order.begin();

            for(string name: Customer){
                cout << name << " wants " << (*currOrder) << endl;
            }
        }
        else{
            cout << "Muffin Store Empty" << endl;
        }
    }

};

class BraceletBooth{
private:
    vector<string> Customer;
    vector<string> Order;

public:
    void push_back_rand(){
        Customer.push_back(names[rand()%50]);
        Order.push_back(bracelets[rand()%10]);
    }

    void pop_front(){
        if(!Customer.empty()){
            cout << Customer.front() << " was served " << Order.front() << endl;
            Customer.erase(Customer.begin());
            Order.erase(Order.begin());
        }
    }

    void display(){
        if(!Customer.empty()){
            vector<string>::iterator currOrder = Order.begin();

            for(string name: Customer){
                cout << name << " wants " << (*currOrder) << endl;
            }
        }
        else{
            cout << "Bracelet Store Empty" << endl;
        }
    }

};

int main(int argc, char const *argv[]){
    srand(time(NULL)); // Seeds random number
    int round = 0; // Indicates our rounds
    CoffeeBooth cafe;
    MuffinBooth muffinStore;
    BraceletBooth braceletStore;

    cout << "Started" << endl;
    // Initializes our cafe
    cafe.push_back_rand();
    cafe.push_back_rand();
    cafe.push_back_rand();

    // Initializes our muffin store
    muffinStore.push_back_rand();
    muffinStore.push_back_rand();
    muffinStore.push_back_rand();

    // Initializes our bracelet store
    braceletStore.push_back_rand();
    braceletStore.push_back_rand();
    braceletStore.push_back_rand();

    time_point start = high_resolution_clock::now();
    time_point now = high_resolution_clock::now();

    while (round < 10){
        time_point now = high_resolution_clock::now();

        milliseconds duration = duration_cast<milliseconds>(now-start);

        if(duration.count() >= 200){
            // ACTUAL SIMULATION CODE HERE
            int newCustomerChance = 50;
            int cafeEvent = rand() % 100;
            int muffinEvent = rand() % 100;
            int braceletEvent = rand() % 100;

            cout << "Round: " << round + 1 << endl;
            cafe.pop_front();
            cafe.display();
            
            cout << endl;

            muffinStore.pop_front();
            muffinStore.display();

            cout << endl;

            braceletStore.pop_front();
            braceletStore.display();

            cout << endl;

            if(cafeEvent < newCustomerChance) {cafe.push_back_rand();}
            if(muffinEvent < newCustomerChance) {muffinStore.push_back_rand();}
            if(braceletEvent < newCustomerChance) {braceletStore.push_back_rand();}

            start = high_resolution_clock::now();
            round++;
        }

    }
    
    return 0;
}
