#include<iostream>
#include<fstream>
#include<string>
template <typename T>
void printArray(T arr[], const int S) {
    for (int i = 0; i < S; i++) {
        std::cout << "Index " << i + 1 << " equals: " << arr[i] << std::endl;
    }
}
void setPB(double arr[], std::ifstream& input);
void setFighters(std::string arr[], std::ifstream& input);
void setSplits(double arr[], int& F);
void runInput(double PBarr[], double inputArr[], std::string nameArr[], const int &S);
void splitsPace(double PB[], double Live[], double &P, int& F);
void liveDelta(double currentSeg[], int& flag, double& time);

int main() {
    std::cout << "Enter times in seconds (for now)" << std::endl;
    std::ifstream fin;
    std::ifstream names;
    fin.open("tyson.txt");
    names.open("fighternames.txt");
    const int SIZE = 14;
    double PBtimes[SIZE];
    double liveSplits[SIZE];
    std::string InGameName[SIZE];
    setPB(PBtimes, fin);
    setFighters(InGameName, names);
    runInput(PBtimes, liveSplits, InGameName, SIZE);
}

void setPB(double arr[], std::ifstream& input) {
    for (int i = 0; i < 14; i++) {
        if (!input.fail()) {
            input >> arr[i];
        }
        else {
            std::cout << "Opening failed!" << std::endl;
        }
    }
}

void setSplits(double arr[], int& F) {
        std::cin >> arr[F];
}

void setFighters(std::string arr[], std::ifstream& input) {
    int MAX_LENGTH = 40;
    for (int i = 0; i < 14; i++) {
        if (!input.fail()) {
            std::getline(input, arr[i]);
        }
        else {
            std::cout << "Opening failed!" << std::endl;
        }
    }
}

void runInput(double PBarr[], double inputArr[], std::string nameArr[], const int &S) {
    int flag = 0;
    double totalTime = 0;
    double pace = 0;
    for (int i = 0; i < S; i++) {
        std::cout << nameArr[i] << " ";
        setSplits(inputArr, flag);
        liveDelta(inputArr, flag, totalTime);
        splitsPace(PBarr, inputArr, pace, flag);
        std::cout << "Pace is " << pace << ", total time now is " << totalTime << std::endl;
        flag++;
    }
}

void splitsPace(double PB[], double Live[], double& P, int &F) {
    P += (Live[F] - PB[F]);
}

void liveDelta(double currentSeg[], int& flag, double& time) {
    time += currentSeg[flag];
}
