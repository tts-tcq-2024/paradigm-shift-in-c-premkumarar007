#include <assert.h>
#include "battery_management.h"

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    assert(batteryIsOk(21, 75, 0.77));  // should print warnings
    assert(!batteryIsOk(19, 81, 0.85)); // should print out of range messages

    return 0;
}
