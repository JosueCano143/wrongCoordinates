/**
 * @file rectangleAlgorithm.cpp
 * @author Josue Cano (josuesalvador143@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-10-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std; 

void wrongPoint(double coordinates[4][2]) {
    double distance, tempX, tempY, centerX = 0, centerY = 0;
    double arrMin, arrMax, validate[4];
    int iK, countMin = 0, countMax = 0; 

    for (iK = 0; iK < 4; iK++) {
        centerX += coordinates[iK][0];
        centerY += coordinates[iK][1];
    }
    centerX /= 4;
    centerY /= 4; 
    
    cout << centerX << endl; 
    cout << centerY << endl; 

    for (iK = 0; iK < 4; iK++) {
        tempX = coordinates[iK][0];
        tempY = coordinates[iK][1];

        distance = sqrt(pow(tempX - centerX, 2) + pow(tempY - centerY, 2));
        validate[iK] = distance; 
    }

    for(iK = 0; iK < 4; iK++){
        cout << validate[iK] << endl;
    }

    arrMax = validate[0];
    arrMin = validate[0];
    for (iK = 1; iK < 4; iK++) {
        if (validate[iK] > arrMax){ 
            arrMax = validate[iK];
            countMax += 1;
        }
        else if (validate[iK] < arrMin) {
            arrMin = validate[iK];
            countMin += 1;
        }
    }

    int wrongX, wrongY; 
    if (countMax == countMin)
        cout << "El rectangulo es correcto" << endl; 

/// de aquí en adelante hace falta corregir 
    else if (countMin > countMax) {
        for (iK = 0; iK < 4; iK++) {
            tempX = coordinates[iK][0];
            tempY = coordinates[iK][1];

            distance = sqrt(pow(tempX - centerX, 2) + pow(tempY - centerY, 2));
            if (distance == arrMax) {
                wrongX = tempX;
                wrongY = tempY;  
            }
        }
        cout << "El rectangulo incorrecto tiene coordenadas: x = " << wrongX << ", y = " << wrongY << endl; 
    }
    else if (countMax > countMin) {
        for (iK = 0; iK < 4; iK++) {
            tempX = coordinates[iK][0];
            tempY = coordinates[iK][1];

            distance = sqrt(pow(tempX - centerX, 2) + pow(tempY - centerY, 2));
            if (distance == arrMin) {
                wrongX = tempX;
                wrongY = tempY;  
            }
        }
        cout << "El rectangulo incorrecto tiene coordenadas: x = " << wrongX << ", y = " << wrongY << endl; 
    }   
}

int main() {
    //double coordinates[4] [2] = {{2,7}, {8,7}, {2,4}, {8,4}};
    double coordinates[4] [2] = {{2,7}, {2,4}, {8,4}, {13,9}};
    wrongPoint(coordinates);

    return 0; 
}
