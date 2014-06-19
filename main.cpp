/* 
 * File:   main.cpp
 * Author: skuarch
 *
 * Created on May 29, 2014, 5:58 PM
 */

#include <stdio.h>
#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

bool salir_systema = false;
bool ver_datos_cliente = false;
bool vendio = false;
string rfc;
string nombre;
string domicilio;
int opcion_vender;
int vasos = 5;
int refractarios = 100;
int bateria_cocina = 500;
int vajilla = 600;
int sartenes = 150;
int cacerolas = 100;
int manteles = 200;
int cubiertos = 5;
int utensilios = 15;
int moldes_pasteles = 250;
int moldes_gelatinas = 250;
float total = 0;
float total_venta = 0;
float iva = 16;
float descuento = 0;
int cantidad = 0;
string factura_texto = "";
ostringstream convert;

void limpiar_pantalla() {
    system("clear");
}

void mostrar_datos_cliente() {

    cout << "RFC: ";
    cout << rfc << endl;

    cout << "Nombre: ";
    cout << nombre << endl;

    cout << "RFC: ";
    cout << rfc << endl;

    cout << "Domicilio: ";
    cout << domicilio << endl;

}

void descontar() {

    cout << "introduce el procentaje a descontar:";
    cin>>descuento;

}

void imprimir_factura() {

    float iva = 0;
    float total = 0;

    cout << "------------------------------------------------" << endl;
    mostrar_datos_cliente();
    cout << "------------------------------------------------" << endl;
    cout << "factura" << endl;
    cout << factura_texto << endl;

    if (descuento > 0) {
        cout << "descuento:" << descuento;
        cout << " %" << endl;
        float d = 0;
        d = total_venta * descuento / 100;
        total_venta = total_venta - d;
        cout << "descuento en pesos: $";
        cout << d << endl;
    }


    cout << "sub total:$" << total_venta;
    cout << " pesos" << endl;
    cout << "iva: ";
    iva = total_venta * .16;
    cout << iva << endl;
    total = iva + total_venta;
    cout << "total $";
    cout << total;
    cout << " pesos" << endl;
    cout << "------------------------------------------------" << endl;

}

void datos_cliente() {

    cout << "------------------------------------------------" << endl;
    cout << "datos cliente" << endl;

    cout << "RFC: ";
    cin>>rfc;

    cout << "Nombre: ";
    cin>>nombre;

    cout << "Domicilio: ";
    cin>>domicilio;

    ver_datos_cliente = true;

}

int crea_factura(string articulo, int cantidad, float total) {

    ostringstream convert;
    ostringstream convert1;

    factura_texto += "- articulo: " + articulo + "\tcantidad: ";
    convert << cantidad;
    factura_texto += convert.str();
    convert1 << total;
    factura_texto += "\t$" + convert1.str() + " pesos \n";

}

int menu_venta(int opcion_vender, int cantidad) {

    ostringstream convert;
    ostringstream convert1;
    vendio = true;

    switch (opcion_vender) {
        case 0:
            break;
        case 1:
            total = vasos * cantidad;
            crea_factura("vasos", cantidad, total);
            break;
        case 2:
            total = refractarios * cantidad;
            crea_factura("refractarios", cantidad, total);
            break;
        case 3:
            total = bateria_cocina * cantidad;
            crea_factura("bateria cocina", cantidad, total);
            break;
        case 4:
            total = vajilla * cantidad;
            crea_factura("vajilla", cantidad, total);
            break;
        case 5:
            total = sartenes * cantidad;
            crea_factura("sartenes", cantidad, total);
            break;
        case 6:
            total = cacerolas * cantidad;
            crea_factura("cacerolas", cantidad, total);
            break;
        case 7:
            total = manteles * cantidad;
            crea_factura("manteles", cantidad, total);
            break;
        case 8:
            total = cubiertos * cantidad;
            crea_factura("cubiertos", cantidad, total);
            break;
        case 9:
            total = utensilios * cantidad;
            crea_factura("utensilios", cantidad, total);
            break;
        case 10:
            total = moldes_pasteles * cantidad;
            crea_factura("moldes para pasteles", cantidad, total);
            break;
        case 11:
            total = moldes_gelatinas * cantidad;
            crea_factura("moldes para gelatinas", cantidad, total);
            break;
    }

    total_venta = (total_venta + total);
    return total;

}

void vender_productos() {

    bool vender = true;
    string continuar;

    while (vender == true) {

        limpiar_pantalla();
        cout << "------------------------------------------------" << endl;
        cout << "vender productos" << endl;
        cout << "seleccione que producto va a vender" << endl;
        cout << "1.-  vasos" << endl;
        cout << "2.-  refractarios" << endl;
        cout << "3.-  baterias de cocina" << endl;
        cout << "4.-  vajilla" << endl;
        cout << "5.-  sartenes" << endl;
        cout << "6.-  cacerolas" << endl;
        cout << "7.-  manteles" << endl;
        cout << "8.-  cubiertos" << endl;
        cout << "9.-  utencilios de cocina" << endl;
        cout << "10.- moldes para pasteles" << endl;
        cout << "11.- moldes para gelatinas" << endl;
        cout << "0.- salir del menu de ventas" << endl;

        cin>>opcion_vender;

        if (opcion_vender == 0) {
            vender = false;
            limpiar_pantalla();
            return;
        }

        cout << "Cantidad: ";
        cin>>cantidad;

        total = menu_venta(opcion_vender, cantidad);

        cout << "desea continuar vendiendo si/no:";
        cin>>continuar;

        if (continuar == "no") {
            break;
        }

    }

    limpiar_pantalla();

}

void salir() {

    limpiar_pantalla();
    salir_systema = true;
    cout << "adios o_o" << endl;

}

void finalizar_venta() {
    vendio = false;
    total = 0;
    total_venta = 0;
    cout << "la venta se finalizo correctamente\n\n" << endl;
}

void tecla_continuar() {
    string t;
    cin>>t;
}

int elige_opcion(int opcion) {

    switch (opcion) {
        case 0:
            salir();
            break;
        case 1:
            limpiar_pantalla();
            vender_productos();
            break;
        case 2:
            limpiar_pantalla();
            datos_cliente();
            break;
        case 3:
            limpiar_pantalla();
            mostrar_datos_cliente();
            break;
        case 4:
            limpiar_pantalla();
            imprimir_factura();
            break;
        case 5:
            limpiar_pantalla();
            imprimir_factura();
            finalizar_venta();
            break;
        case 6:
            limpiar_pantalla();
            descontar();
            break;
        default:
            limpiar_pantalla();
            break;
    }

}

int main() {

    int opcion;

    cout << "*******************************************" << endl;
    cout << "*************  Cocina Store  **************" << endl;
    cout << "*******************************************" << endl;

    while (salir_systema == false) {

        cout << "seleccione una opcion del menu\n" << endl;

        cout << "1.- vender productos" << endl;
        cout << "2.- introducir datos del cliente" << endl;

        if (ver_datos_cliente == true) {

            cout << "3.- mostrar datos cliente" << endl;

        }

        if (vendio == true) {
            cout << "4.- ver factura" << endl;
        }

        if (vendio == true) {
            cout << "5.- finalizar venta" << endl;
        }

        if (vendio == true) {
            cout << "6.- aplicar un descuento" << endl;
        }

        cout << "0.- salir del sistema" << endl;

        cin>>opcion;
        elige_opcion(opcion);

    }

    return 0;

}

