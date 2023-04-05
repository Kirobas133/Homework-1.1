// Homework1.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

void mass_output(int masss, int* mass, std::ofstream& outputfile) {
    outputfile << masss << std::endl;
    for (int i = 0; i < masss; i++) {
        if (i == masss - 1) {
            outputfile << mass[i] << std::endl;
        }
        else {
            outputfile << mass[i] << " ";
        }
    }
}


int main()
{

    std::ifstream mass("in.txt");
    if (mass) {
        int mass1s = 0, mass2s = 0, temp = 0;

        mass >> mass1s;
        mass >> temp; //сразу считываем первый элемент массива, который в последствии станет последним
        int* mass1 = new int[mass1s];

        //пишем цикл, с учетом того что последний элемент будет записан вне цикла
        for (int i = 0; i < (mass1s - 1); i++) {
            mass >> mass1[i];
        }
        mass1[mass1s - 1] = temp;

        mass >> mass2s;
        int* mass2 = new int[mass2s];

        //пишем цикл записывая элементы массива начиная со 2-го не используя последний элемент, который будет записан 0-м вне цикла
        for (int i = 0; i < (mass2s - 1); i++) {
            mass >> mass2[i + 1];
        }
        mass >> mass2[0];

        mass.close();

        std::ofstream massout("out.txt");

        mass_output(mass2s, mass2, massout);
        mass_output(mass1s, mass1, massout);

        delete[] mass1;
        delete[] mass2;
    }
    else {
        std::cout << "File not found!\n";
    }
}