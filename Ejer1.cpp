#include <iostream>
#include <thread>
#include <chrono>


using namespace std;

thread thread_1; //definición del primer hilo
thread thread_2; //definición del segundo hilo



void func1(int num, int &resultado) {    
    resultado = 1;
    for (int i = 1; i <= num; i++) {
        resultado *= i;
    }
    cout << "Soy el thread_1 y estoy ejecutando func1" << endl;
}


void func2(int num, int &resultado) {    
    
    resultado = 1;
    for (int i = 1; i <= num; i++) {
        resultado *= i;
    }
    cout << "Soy el thread_1 y estoy ejecutando func1" << endl;

}


int main() {
int num1,num2;
int resultado1,resultado2;
cout << "Introduce dos numeros enteros para calcular sus factoriales: " <<  endl;
cout << "Primer numero: ";
cin>> num1;
cout << "Segundo numero: ";
cin>> num2;

thread thread_1(func1, num1, ref(resultado1));
thread thread_2(func2, num2, ref(resultado2));

thread_1.join(); //espera a que termine thread_1
thread_2.join(); //espera a que termine thread_2

cout << "Soy main. Ambos hilos han terminado." << endl;
cout << "Factorial de " << num1 << " = " << resultado1 << endl;
cout << "Factorial de " << num2 << " = " << resultado2 << endl;
return 0;
}








//thread_1.join(); //espera a que termine thread_1
