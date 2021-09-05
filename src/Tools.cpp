#include "Engine.h"

using namespace MoldEngine;

static char bufferOne[21];
const char* Tools::toString(int num) {
    sprintf(bufferOne,"%d",num);
    return bufferOne;
}

static char bufferTwo[21];
const char* Tools::toString(float num) {
    sprintf(bufferTwo,"%f",num);
    return bufferTwo;
}