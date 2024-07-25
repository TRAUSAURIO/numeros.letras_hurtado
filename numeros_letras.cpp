#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string unidades[] = {"", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
string decenas[] = {"", "diez", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
string centenas[] = {"", "cien", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"};
string especiales[] = {"diez", "once", "doce", "trece", "catorce", "quince", "dieciseis", "diecisiete", "dieciocho", "diecinueve"};

string numeroALetras(int numero) {
    if (numero == 0) return "cero";
    
    string resultado = "";
    
    if (numero >= 100000000) {
        int cientosMillones = numero / 100000000;
        resultado += unidades[cientosMillones] + " cientos ";
        numero %= 100000000;
    }

    if (numero >= 1000000) {
        int millones = numero / 1000000;
        resultado += numeroALetras(millones) + " millones ";
        numero %= 1000000;
    }

    if (numero >= 1000) {
        int miles = numero / 1000;
        if (miles == 1) {
            resultado += "mil ";
        } else {
            resultado += numeroALetras(miles) + " mil ";
        }
        numero %= 1000;
    }

    if (numero >= 100) {
        int cientos = numero / 100;
        if (cientos == 1 && numero % 100 == 0) {
            resultado += "cien";
        } else {
            resultado += centenas[cientos] + " ";
        }
        numero %= 100;
    }

    if (numero >= 20) {
        int decena = numero / 10;
        resultado += decenas[decena] + " ";
        numero %= 10;
    } else if (numero >= 10) {
        resultado += especiales[numero - 10];
        return resultado;
    }

    resultado += unidades[numero];

    return resultado;
}

void generarNumerosAleatorios() {
    srand(time(0));
    for (int i = 0; i < 100; i++) {
        int numero = rand() % 999999999 + 1;
        cout << numero << " - " << numeroALetras(numero) << endl;
    }
}

int main() {
    // Prueba de la función de conversión
    cout << "999,999,999 en letras: " << numeroALetras(999999999) << endl;

    // Generar 100 números aleatorios y mostrarlos con su equivalente en letras
    generarNumerosAleatorios();

    return 0;
}
