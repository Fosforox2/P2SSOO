#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

mutex saldoMutex;
int saldoCuenta = 10000;

void retirarDinero(int cantidad) {
    saldoMutex.lock();
    if(saldoCuenta >= cantidad) {
        saldoCuenta -= cantidad;
        cout << "Retiro exitoso de " << cantidad << "€" << endl;
    } else {
        cout << "No hay suficiente saldo para retirar " << cantidad << "€" << endl;
    }
    saldoMutex.unlock();
    this_thread::sleep_for(chrono::seconds(2));
}

void depositarDinero(int cantidad) {
    saldoMutex.lock();
    saldoCuenta += cantidad;
    cout << "Depósito exitoso de " << cantidad << "€" << endl;
    saldoMutex.unlock();
    this_thread::sleep_for(chrono::seconds(2));
}

void monitorSaldo(bool* finalizar) {
    while(!(*finalizar)) {
        saldoMutex.lock();
        cout << "[Monitor] Saldo actual: " << saldoCuenta << "€" << endl;
        saldoMutex.unlock();
        this_thread::sleep_for(chrono::seconds(2));
    }
}

int main() {
    bool finalizarMonitor = false;
    thread hiloMonitor(monitorSaldo, &finalizarMonitor);

    for(int i = 0; i < 5; i++) {
        thread hiloRetiro(retirarDinero, 500);
        thread hiloDeposito(depositarDinero, 1000);

        hiloRetiro.join();
        hiloDeposito.join();
    }

    finalizarMonitor = true;
    hiloMonitor.join();

    cout << "\nSaldo final de la cuenta: " << saldoCuenta << "€" << endl;
}
