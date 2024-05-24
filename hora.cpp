#include <iostream>
using namespace std;
#include "hora.h"
#include <ctime>

 Hora::Hora()
 {
   time_t now = time(0);
   tm* tmPtr = localtime(&now);
   _min=tmPtr->tm_min;
   _hora=tmPtr->tm_hour;
 }

 void Hora::Mostrar()
 {
   cout << (_hora <= 9 ? "0" : "" ) << _hora << ":";
   cout << (_min <= 9 ? "0" : "" ) << _min << ":";
 }

 string Hora::toString()
 {
   return to_string(_hora) + ":" + to_string (_min);
 }
