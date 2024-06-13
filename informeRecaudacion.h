#pragma once
using namespace std;
#include "fecha.h"
#include "ventaManager.h"
#include "ventaArchivo.h"
#include "empleado.h"
#include "empleadoManager.h"
#include "empleadoArchivo.h"

 class InformeRecaudacion
 {
   public:
    void porAnio();
    void porMes();
    void porEmpleado();
    void porProducto();
    void menuInformeRecaudacion();
 };
