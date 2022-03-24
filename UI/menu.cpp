//
// Created by Antonio on 3/24/2022.
//

#include <iostream>
#include "menu.h"
#include "../TriangleRepository/TriangleRepository.h"
#include "../UIModules/IOModules.h"

void showMenu(){
    std::cout << "--Main Menu--\n";
    std::cout << "Selecteaza una dintre urmatoarele:\n";
    std::cout << "1 - Citirea sirului de triunghiuri.\n";
    std::cout << "2 - Afisarea sirului de triunghiuri.\n";
    std::cout << "3 - Afisarea unui triunghiu pentru o pozitie data.\n";
    std::cout << "4 - Afisarea celui mai mare triunghi (in functie de arie). // under work\n";
    std::cout << "5 - Afisarea tuturor triunghiurilor situate in cadranul 1. // under work\n";
    std::cout << "6 - Afisarea celei mai lungi secvente de triunghiuri egale. // under work\n";
    std::cout << "0 - Iesire\n";
    std::cout << "Selectie: ";
}

void runMenu(){
    int choice;
    TriangleRepository tr;
    do{
        showMenu();
        choice = read();
        switch(choice){
            case 1: {
                std::cout << "Introduceti numarul elementelor pe care doriti sa le adaugati: ";
                int length = read();
                readTriangles(tr, length);
                break;
            }
            case 2: {
                std::cout << "Sirul triughirilor este: \n";
                printTriangles(tr);
                break;
            }
            case 3: {
                std::cout << "Dati pozitia triunghiului (0 <= pozitie < " << tr.getLength() << "): "; int position = read();
                printTriangles(tr, position);
                break;
            }
            case 0:
                std::cout << "Iesire..";
                break;
            default:
                std::cout << "Optiune gresita, reincercati. \n";
                break;
        }
    } while(choice !=0);
}