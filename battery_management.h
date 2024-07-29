#ifndef BATTERY_MANAGEMENT_H
#define BATTERY_MANAGEMENT_H

typedef struct {
    float min;
    float max;
    float warningTolerance;
    const char* outOfRangeMessage;
    const char* approachingMinWarning;
    const char* approachingMaxWarning;
} ParameterLimits;

int isValueOutOfRange(float value, ParameterLimits limits);
void printWarningIfNeeded(float value, ParameterLimits limits);
int isParameterWithinRange(float value, ParameterLimits limits);
int batteryIsOk(float temperature, float soc, float chargeRate);

#endif
