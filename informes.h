#pragma once
#include "informeRecaudacion.h"
#include "informeStock.h"

 class Informes
 {
   private:
    InformeRecaudacion SubMenuRecaudacion;
    InformeStock subMenuReponerStock;

   public:
    void MenuInforme();

 };
