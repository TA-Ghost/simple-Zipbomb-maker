
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {

    long long start = 0;
    long long cycle;

    ofstream outFile("bomb.txt");

    if (!outFile.is_open()) {
        cerr << "Error: Could not open the file!\n";
        return 1;
    }

    cout << "How many GB do you want the file to have? : ";
    cin >> cycle;


    cycle *= 1000000000LL;

    const long long chunk = 10000;

    while (start < cycle) {

        long long remaining = cycle - start;
        long long amount = min(chunk, remaining);

        outFile << string(amount, '0');

        start += amount;

        int average = (start * 100) / cycle;

        cout << "\r[";

        int progress = average / 10;

        for (int i = 0; i < 10; i++) {
            cout << (i < progress ? "=" : " ");
        }

        cout << "] " << average << "%";
        cout.flush();
    }

    outFile.close();

    cout << "\nFile created successfully!\n";

    int result = system("zip -q svt.zip bomb.txt");

    if (result == 0) {
        cout << "File compressed successfully!\n";
    } else {
        cerr << "Compression failed!\n";
        return 1;
    }

    return 0;
}


/*
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main (){
    
    int start = 0;

    long cycle ;
    int output;
    std::ofstream outFile("bomb.txt");

    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }

    std::cout << "how many gb you want the bomb to have ? :";
    std::cin >> cycle ;
    cycle = cycle * 1024000000;


    while (start != cycle){
        outFile << "0";
        start++;
        int average = (start * 100)/cycle;
        cout << average;
        if(average == 10){
            cout << "[=>";
        }
        else if (average == 20){
            cout << "[==>";
        }
        else if (average == 30){
            cout << "[===>";
        }
        else if (average == 40){
            cout << "[====>";
        }
        else if (average == 50){
            cout << "[=====>";
        }
        else if (average == 60){
            cout << "[======>";
        }
    }
    std::cout << "done" << std::endl;

    outFile.close();

    int result = std::system("zip -r svt.zip bomb.txt");
    
    if (result == 0) {
        std::cout << "File compressed successfully!\n";
    } else {
        std::cerr << "Compression failed!\n";
        std::system("rm svt.zip");
        int result = std::system("zip -r svt.zip bomb.txt");
    }

    return 0;
}
    */