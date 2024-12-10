#include <iostream>
using namespace std;

#include <chrono>
using namespace std::chrono;

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
    }
};

string name[50] = {

};
string drink[50] ={

};



int main(int argc, char const *argv[])
{
    int round = 0;

    time_point start = high_resolution_clock::now();
    time_point now = high_resolution_clock::now();
    CoffeeBooth cafe;

    while (round <= 10){
        time_point now = high_resolution_clock::now();

        milliseconds duration = duration_cast<milliseconds>(now-start);

        if(duration.count() > 1000){
            // ACTUAL SIMULATION CODE HERE 
            cafe.push("asdf", "erth");
            cafe.push("asdf", "erth");
            cafe.push("asdf", "erth");
            



            now = high_resolution_clock::now();
            round++;
        }

    }
    
    
    return 0;
}
