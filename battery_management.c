#include <stdio.h>
#include "battery_management.h"

int isValueOutOfRange(float value, ParameterLimits limits) {
    return (value < limits.min || value > limits.max);
}

void printWarningIfNeeded(float value, ParameterLimits limits) {
    if (value < limits.min + limits.warningTolerance) {
        printf("%s\n", limits.approachingMinWarning);
    } else if (value > limits.max - limits.warningTolerance) {
        printf("%s\n", limits.approachingMaxWarning);
    }
}

int isParameterWithinRange(float value, ParameterLimits limits) {
    if (isValueOutOfRange(value, limits)) {
        printf("%s\n", limits.outOfRangeMessage);
        return 0;
    }
    printWarningIfNeeded(value, limits);
    return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    ParameterLimits temperatureLimits = {0, 45, 2.25, "Temperature out of range!", "Warning: Approaching low temperature", "Warning: Approaching high temperature"};
    ParameterLimits socLimits = {20, 80, 4, "State of Charge out of range!", "Warning: Approaching low charge", "Warning: Approaching high charge"};
    ParameterLimits chargeRateLimits = {0, 0.8, 0.04, "Charge Rate out of range!", "Warning: Approaching low charge rate", "Warning: Approaching high charge rate"};

    int isTemperatureOk = isParameterWithinRange(temperature, temperatureLimits);
    int isSocOk = isParameterWithinRange(soc, socLimits);
    int isChargeRateOk = isParameterWithinRange(chargeRate, chargeRateLimits);

    return isTemperatureOk && isSocOk && isChargeRateOk;
}
