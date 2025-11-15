#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

using namespace std;


void func1(string texto, int &contador1) {    
char caracter;
ifstream archivo(texto);
while (archivo.get(caracter)) {
if (caracter == 'a') {
    contador1++;
}
else if (caracter == 'A'){
    contador1++;
}
}/*else if (caracter == 'á'){
    contador1++;
}else if (caracter == 'Á'){
    contador1++;
}*/
archivo.close();
}


void func2(string texto, int &contador2) {    
char caracter;
ifstream archivo(texto);
while (archivo.get(caracter)) {
if (caracter == 'b') {
    contador2++;
}else if (caracter == 'B'){
    contador2++;
}
}
archivo.close();
}



int main() {
char caracter;
int contador1 = 0;
int contador2= 0;
string texto;
cout << "Introduce el nombre del archivo que desea scanear: ";
cin >> texto;
texto = texto + ".txt";


thread thread_1(func1, texto, ref(contador1));
thread thread_2(func2, texto, ref(contador2));



thread_1.join(); //espera a que termine thread_1
thread_2.join(); //espera a que termine thread_2







std::cout << "El caracter 'a' en todas sus formas ha salido " << contador1 << " veces en el fichero, mientras que el caracter 'b' en todas sus ha salido " << contador2 << " veces en el fichero " << texto << std::endl;

return 0;
}