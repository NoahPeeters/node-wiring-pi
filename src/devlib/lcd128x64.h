#ifndef _WPI_LCD128X64_H_
#define _WPI_LCD128X64_H_

#include "../addon.h"

namespace nodewpi {
    NAN_METHOD(lcd128x64setOrigin);
    NAN_METHOD(lcd128x64setOrientation);
    NAN_METHOD(lcd128x64orientCoordinates);
    NAN_METHOD(lcd128x64getScreenSize);
    NAN_METHOD(lcd128x64point);
    NAN_METHOD(lcd128x64line);
    NAN_METHOD(lcd128x64lineTo);
    NAN_METHOD(lcd128x64rectangle);
    NAN_METHOD(lcd128x64circle);
    NAN_METHOD(lcd128x64ellipse);
    NAN_METHOD(lcd128x64putchar);
    NAN_METHOD(lcd128x64puts);
    NAN_METHOD(lcd128x64update);
    NAN_METHOD(lcd128x64clear);
    NAN_METHOD(lcd128x64setup);

    NAN_MODULE_INIT(init_lcd128x64);
}

#endif