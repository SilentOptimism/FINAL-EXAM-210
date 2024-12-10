#include <iostream>
using namespace std;

#include <chrono>
using namespace std::chrono;

// Used chat gpt to generate the random people names
string names[50] = {
    "Alice", "Bob", "Charlie", "David", "Emily",
    "Frank", "Grace", "Henry", "Iris", "Jack",
    "Kelly", "Liam", "Mia", "Noah", "Olivia",
    "Penelope", "Quentin", "Riley", "Sophia", "Thomas",
    "Uma", "Victor", "Wendy", "Xavier", "Yara",
    "Zachary", "Abigail", "Benjamin", "Chloe", "Daniel",
    "Eleanor", "Finn", "Georgia", "Harper", "Isaac",
    "Jasmine", "Kai", "Lena", "Mason", "Nora",
    "Oscar", "Piper", "Quinn", "Riley", "Samuel"
};

// Used chat gpt to generate the drink names
string drinks[10] = {
        "Coffee", "Tea", "Water", "Juice", "Soda",
        "Milk", "Wine", "Beer", "Cocktail", "Hot Chocolate"
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

    void pushRand(){
        string randName = names[rand() % 50];
        string randDrink = drinks[rand() % 10];

        push_back(randName, randDrink);
    }

    void display(){
        Node* curr = head;

        while(curr!= NULL){
            cout << "Name: " << curr->customerName << " Drink: " << curr->product << endl;
            curr = curr->next;
        }
    }

};


int main(int argc, char const *argv[]){
    srand(time(NULL)); // Seeds random number
    int round = 0; // Indicates our rounds
    CoffeeBooth cafe;

    // Initializes our cafe
    cafe.pushRand();
    cafe.pushRand();
    cafe.pushRand();

    cafe.display();

    time_point start = high_resolution_clock::now();
    time_point now = high_resolution_clock::now();

    while (round <= 10){
        time_point now = high_resolution_clock::now();

        milliseconds duration = duration_cast<milliseconds>(now-start);

        if(duration.count() >= 1000){

            // ACTUAL SIMULATION CODE HERE 
            cafe.pop_front();
            cafe.display();
            cout << round << endl;

            // Creates/Pushes 3 random people

            now = high_resolution_clock::now();
            round++;
        }

    }
    
    
    return 0;
}
