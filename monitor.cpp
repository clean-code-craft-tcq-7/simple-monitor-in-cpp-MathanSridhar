#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

void  showAlert(const std::string& message) {
  cout << message;
  for (int i = 0; i < 6; i++) {
    cout << "\r* " << flush;
    sleep_for(seconds(1));
    cout << "\r *" << flush;
    sleep_for(seconds(1));
  }
}

bool checkTemperature(float temp) {
    if (temp < 95 || temp > 102) {
        showAlert("Temperature is critical!");
        return false;
    }
    return true;
}

bool checkPulse(float pulse) {
    if (pulse < 60 || pulse > 100) {
        showAlert("Pulse Rate is critical!");
        return false;
    }
    return true;
}

bool checkSpo2(float spo2) {
    if (spo2 < 90) {
        showAlert("Oxygen Saturation is critical!");
        return false;
    }
    return true;
}

bool vitalsAreNormal(float temp, float pulse, float spo2) {
    return checkTemperature(temp) && checkPulse(pulse) && checkSpo2(spo2);
}
