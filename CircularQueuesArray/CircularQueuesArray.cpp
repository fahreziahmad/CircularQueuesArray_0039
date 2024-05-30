#include <iostream>
using namespace std;

class Queues {
    int FRONT, REAR, max = 5;
    int queue_array[5];

public:
    Queues() {
        FRONT = -1;
        REAR = -1;
    }
    void insert() {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        //Cek apakah antrian penuh atau tidak
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
            cout << "\nQueue overflow\n";
            return;
        }

        //Cek apakah antrian kosong
        if (FRONT == -1) {
            FRONT = 0;
            REAR = 0;
        }
        else {
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }

    void remove() {
        //Cek apakkah antrian kosong
        if (FRONT == -1) {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

        if (FRONT == REAR) {
            FRONT = -1;
            REAR = -1;
        }
        else {
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }

    void display() {
        int FRONT_position = FRONT;
        int REAR_position = REAR;

        if (FRONT == -1) {
            cout << "Queuenis empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        if (FRONT_position <= REAR_position) {
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << "   ";
                FRONT_position++;
            }
            cout << endl;
        }
        else {
            while (FRONT_position <= max - 1) {
                cout << queue_array[FRONT_position] << "   ";
                FRONT_position++;
            }
            FRONT_position = 0;

            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << "   ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};

int main() {
    Queues q;
    char ch;

    while (true) {
        try {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

