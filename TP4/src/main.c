/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "michis.h"

int main(void)
{
    LinkedList* michis = ll_newLinkedList();
    eMichi* primero = newMichiStr("1","Pelusa","Ruso Azul","4.5");
    eMichi* segundo = newMichiStr("2","Garfield","Red Tabby","4.5");
    eMichi* tercero = newMichiStr("3","Lupe","Ruso Azul","4.5");
    eMichi* cuarto = newMichiStr("4","Feli","Carey","4.5");

    //------ Agrego a la lista de gatos y ordeno por su campo nombre
    ll_add(michis,primero);
    ll_add(michis,segundo);
    ll_add(michis,tercero);
    ll_add(michis,cuarto);

    ll_sort(michis,michiCompareNombre,1);
    mostrarMichis(michis);
    printf("---------------------\n\n");

    //------ Elimino un gato de la lista y muestro
    printf("-------- Michi eliminado -------\n");
    ll_remove(michis,1);
    mostrarMichis(michis);
    printf("----------------------\n\n");

    //------ Muestro la cantidad de gatos cargados
    printf("----------------------\n");
    printf(" - Hay cargados %d michis - \n",ll_len(michis));
    printf("----------------------\n\n");

    //------ Muestro donde esta mi querida Pelusa
    int index = ll_indexOf(michis,primero);
    if(index >= 0){
            printf(" - Pelusa esta cargada en la posicion: %d \n",index);
            eMichi* pelusa = ll_get(michis,index);
            mostrarMichi(pelusa);
    }
    printf("----------------------\n\n");

    //----- Uso el set para cambiar el gato que ya no esta
    eMichi* nuevo = newMichiStr("5","Ron","Blanco","6.5");
    ll_set(michis,2,nuevo);
    printf("--- Michi agregado en la posicion de Pelusa ---\n");
    mostrarMichis(michis);
    printf("\n\n");

    // ------ Michi devuelto y borrado y me guardo una copia de la lista antes de borrar
    LinkedList* michisCopia = ll_clone(michis);
    eMichi* michiPop = ll_pop(michis,2);
    if(michiPop != NULL){
        printf("--- Michi popeado ---\n");
        mostrarMichi(michiPop);
    }
    printf("-----------------------\n\n");

    // ------ Michi pusheado a la lista
    eMichi* nuevoPush = newMichiStr("6","Lulu","Negro","3.5");
    if(nuevoPush != NULL) ll_push(michis,2,nuevoPush);
    printf("--- Michi Lulu pusheado ---\n");
    mostrarMichis(michis);

    //---- Contiene la lista al gato pusheado
    if( ll_contains(michis,nuevoPush) ){
        printf("\n-- Lulu esta en la lista --\n\n");
    }

    //--- Chequeo si las listas son iguales, no van a serlo porque se agregaron michis a la lista original
    printf("\n------ Chequeo contenido de listas -------");
    if( ll_containsAll(michis,michisCopia) ){
        printf("\n - Tienen los mismos elementos ambas listas ---\n\n");
    }else{
        printf("\n - No tienen los mismos elementos ambas listas ---\n\n");
    }

    //--- Chequeo si las listas son iguales, no van a serlo porque se agregaron michis a la lista original
    printf("\n------ Gatos que son hermanos -------");
    LinkedList* gatosHermanos = ll_subList(michis,0,2);
    if( gatosHermanos != NULL){
        mostrarMichis(gatosHermanos);
    }
    printf("\n\n");

    //----- Vacio la lista
    if( !ll_isEmpty(michis) )    ll_clear(michis);
    printf("\n--- Lista Vaciada ---\n");

    //----- Elimino y libero la lista
    ll_deleteLinkedList(michis);
    printf("--- Lista Borrada ---");
    printf("\n");

    //startTesting(1);  // ll_newLinkedList
    //startTesting(2);  // ll_len
    //startTesting(3);  // getNode - test_getNode
    //startTesting(4);  // addNode - test_addNode
    //startTesting(5);  // ll_add
    //startTesting(6);  // ll_get
    //startTesting(7);  // ll_set
    //startTesting(8);  // ll_remove
    //startTesting(9);  // ll_clear
    //startTesting(10); // ll_deleteLinkedList
    //startTesting(11); // ll_indexOf
    //startTesting(12); // ll_isEmpty
    //startTesting(13); // ll_push
    //startTesting(14); // ll_pop
    //startTesting(15); // ll_contains
    //startTesting(16); // ll_containsAll
    //startTesting(17); // ll_subList
    //startTesting(18); // ll_clone
    //startTesting(19); // ll_sort */

    return 0;
}

































