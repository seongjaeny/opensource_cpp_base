#include "Notifier.h"

bool Notifier::notify(double result, double threshold) {
    return result > threshold;
}
