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
    Node* next = NULL;

    Node(string name, string item) : customerName(name), product(item) {}
    
};

class CoffeeBooth{
private:
    Node* head = NULL;

public:
    void push(string customerName, string product){
        Node* curr = head;

        while (curr != NULL){
            curr = curr->next;
        }

        curr = new Node(customerName, product);
        cout << head->customerName << endl;
    }

    void pushRand(){
        string randName = names[rand() % 50];
        string randDrink = drinks[rand() % 50];

        push(randName, randDrink);
    }

    void display(){
        Node* curr = head;

        while(curr != NULL){
            cout << "Name: " << curr->customerName << " Drink: " << curr->product << endl;
        }

    }

};


int main(int argc, char const *argv[]){
    srand(time(NULL)); // Seeds random number
    int round = 0; // Indicates our rounds
    CoffeeBooth cafe;

    cafe.pushRand();
    cafe.pushRand();
    cafe.pushRand();

    cafe.display();

    time_point start = high_resolution_clock::now();
    time_point now = high_resolution_clock::now();

    while (round <= 10){
        time_point now = high_resolution_clock::now();

        milliseconds duration = duration_cast<milliseconds>(now-start);

        if(duration.count() > 1000){
            // ACTUAL SIMULATION CODE HERE 

            // Creates/Pushes 3 random people

            now = high_resolution_clock::now();
            round++;
        }

    }
    
    
    return 0;
}
