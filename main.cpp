#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


int funcion_cassette()

/*Funcion para crea un Conjunto Potencia (posibles combinaciones) de las
canciones introducidas en el imput. Basado en el algoritmo de 
http://juanpinzon-1992.blogspot.com/2013/10/conjunto-potencia-c.html*/
vector< vector<int> > conj(vector<int> x){
    int cant_salida = 1, h, i, j;

    //Contamos la cantidad de elementos el vector potencia
    for(h=1;h<=x.size();h++){
        cant_salida = cant_salida *2;
    }

    //Generamos el conjunto potencia
    vector< vector<int> > salida(cant_salida, vector<int>(x.size()));
    for(i=0; i<cant_salida; i++){
        for(j=0;j<x.size();j++){
            if(i & (1<<j)){
                salida[i][j] = x[j];
            }
        }
    }
    return salida;
}

int main(){

    string datos;

    cout << "Ingrese datos: ";
    getline(cin, datos);

    istringstream ss(datos);
    string token;
    vector<string> datos_separados;
    // Split en C++ http://stackoverflow.com/questions/236129/split-a-string-in-c
    while(getline(ss, token, ' ')) {
        datos_separados.push_back(token);
    }
    vector<int> datos_enteros;


    int cassette = atoi(datos_separados[0].c_str());
    for (int i = 1; i < datos_separados.size(); i++){
        // Funcion convertir a entero http://stackoverflow.com/questions/7663709/convert-string-to-int-c
        int numero = atoi(datos_separados[i].c_str());
        datos_enteros.push_back(numero);
    }


    vector < vector<int> > conjuntos;
    conjuntos = conj(datos_enteros);
    int var;
    for(int i=0; i<conjuntos.size(); i++){
        for(int j=0; j<datos_enteros.size(); j++){
            var = conjuntos[i][j];
            cout << var << " ";
        }
        cout<<endl;
    }
    return 0;
}
