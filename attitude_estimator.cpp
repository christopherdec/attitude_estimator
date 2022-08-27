#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

void readVariables(string);
void calculateAngles();
void writeResult();

ofstream outputFile("result.txt");

double timestamp;
double x;
double y;
double z;
double roll;
double tan_theta;
double pitch;

int main() {

    string line;
    ifstream inputFile("attitude_exam.log");

    cout << "Iniciando a leitura do arquivo de log...";

    while (getline (inputFile, line)) {

        readVariables(line);

        calculateAngles();

        writeResult();
    }

    cout << "\nLeitura concluída! Os resultados estão em result.txt.";

    inputFile.close();
    outputFile.close();
}


// extrai as variáveis da linha lida
void readVariables(string line) {
    
    timestamp = stof(line.substr(0, line.find(";")));
    line.erase(0, line.find(" ") + 1);

    // a multiplicação por 0.001 converte de millig-unit para g-unit
    x = 0.001 * stof(line.substr(0, line.find(";")));
    line.erase(0, line.find(" ") + 1);

    y = 0.001 * stof(line.substr(0, line.find(";")));

    line.erase(0, line.find(" ") + 1);
    z = 0.001 * stof(line.substr(0, line.find(";")));
}

// assume-se sequência de rotação xyz (aerospace rotation)
void calculateAngles() {
    
    // cálculo do ângulo phi (roll) em radianos
    roll = atan2(y, z);

    // cálculo do ângulo thetha (pitch) em radianos
    tan_theta = -x / sqrt(pow(y, 2) + pow(z, 2));
    pitch = atan(tan_theta);
}

void writeResult() {
    outputFile << timestamp << "; " << roll << "; " << pitch << "\n";
}