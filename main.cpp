// Type your code here, or load an example.
// Gaussian_RiskNeutral_Kernel_Pamplona2025.cpp
// First C++17 salvo fired by Víctor Manuel Gómez Gelvez
// From a Berlinas bus, escaping corruption, chasing RenTech dreams
// Zero Blood On The P&L ™ 2026

#include <iostream>
#include <cmath>
#include <random>
#include <vector>

using namespace std;

double girsanov_radon_nikodym(double t, double lambda) {
    return exp(-lambda * t - 0.5 * lambda * lambda * t);
}

vector<double> simulate_risk_neutral_path(int steps = 1000, double T = 1.0, double lambda = 0.5) {
    vector<double> path(steps + 1);
    double dt = T / steps;
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<double> Z(0.0, 1.0);
    
    path[0] = 0.0;  // log-price starts at 0
    for (int i = 1; i <= steps; ++i) {
        double dW = sqrt(dt) * Z(gen);
        double drift = -lambda * sqrt(dt) * Z(gen);  // Girsanov adjustment
        path[i] = path[i-1] + drift + dW;
    }
    return path;
}

int main() {
    cout << "=== ZERO BLOOD ON THE P&L ™ ===" << endl;
    cout << "Risk-Neutral Kernel – Girsanov Measure Change" << endl;
    cout << "Fired from Berlinas Civil Transport WiFi – Pamplona, Colombia" << endl;
    cout << "C++17 compiled on godbolt.org – Dec 2025" << endl << endl;

    auto path = simulate_risk_neutral_path();
    cout << "First 10 points under risk-neutral measure (Girsanov λ=0.5):" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "t=" << i*0.001 << " → log(S_t/S_0) = " << path[i] << endl;
    }
    cout << "\n¡ADELANTE, GUERRERO DE LUZ!" << endl;
    return 0;
}