#ifndef _WPI_GERTBOARD_H_
#define _WPI_GERTBOARD_H_

#include "../addon.h"

namespace nodewpi {
    NAN_METHOD(gertboardAnalogSetup);

    NAN_MODULE_INIT(init_gertboard);
}

#endif