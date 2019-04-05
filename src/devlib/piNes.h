#ifndef _WPI_PI_NES_H_
#define _WPI_PI_NES_H_

#include "../addon.h"

namespace nodewpi {
    NAN_METHOD(setupNesJoystick);
    NAN_METHOD(readNesJoystick);

    NAN_MODULE_INIT(init_piNes);
}

#endif