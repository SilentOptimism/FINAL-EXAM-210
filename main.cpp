#include <iostream>
using namespace std;

#include <chrono>
using namespace std::chrono;

struct node{
    string customerName;
    string product;
};

class linkedList(){
private:
    Node* head = NULL;

};




int main(int argc, char const *argv[])
{
    int round = 0;

    time_point start = high_resolution_clock::now();
    time_point now = high_resolution_clock::now();

    while (round <= 10){
        time_point now = high_resolution_clock::now();

        milliseconds duration = duration_cast<milliseconds>(now-start);

        if(duration.count() >1000){

            now = high_resolution_clock::now();
            round++;
        }

    }
    
    
    return 0;
}
