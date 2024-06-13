#include <iostream>
using namespace std;
#include "informeStock.h"
#include "venta.h"
#include "ventaArchivo.h"
#include "producto.h"
#include "productoArchivo.h"
#include "funcionesGlobales.h"

 void InformeStock::faltantesDeStock()
 {
   Producto regP;
   ProductoArchivo archiP("producto.dat");
   int cantP = archiP.contarRegistros();

   Venta regV;
   VentaArchivo archiV("venta.dat");
   int cantV = archiV.contarRegistros();

   bool reponer = false;

   for (int i=0; i<cantP; i++)
   {
     bool esta = false;
     regP = archiP.leer(i);

     for (int j=0; j<cantV; j++)
     {
       regV = archiV.leer(j);
       {
         if (regP.getStock() <= 10 && regP.getEstado())
         {
           esta = true;
           reponer = true;
         }
       }
     }
     if (esta)
     {
       cout << "ID MEDICAMENTO: " << regP.getId() << endl;
       cout << "MARCA: " << regP.getMarca() << endl;
       cout << "DROGA: " << regP.getDroga() << endl;
       cout << "STOCK ACTUAL: " << regP.getStock() << endl;
       cout << endl;
       cout << "- - - - - - - - - - - -" << endl;
       cout << endl;
     }
   }

   if (!reponer)
   {
     cout << "NINGUN MEDICAMENTO NECESITA REPONER STOCK" << endl;
   }
   pausa();
 }

