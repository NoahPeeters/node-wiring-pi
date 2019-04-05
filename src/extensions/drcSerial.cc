#include "drcSerial.h"
#include <wiringPi.h>
#include <drcSerial.h>

// Func : int drcSetupSerial(const int pinBase, const int numPins, const char* device, const int baud)
// Description : https://projects.drogon.net/drogon-remote-control/drc-protocol-arduino/

namespace nodewpi {
    NAN_METHOD(drcSetupSerial) {
            SET_ARGUMENT_NAME(0, pinBase);
            SET_ARGUMENT_NAME(1, numPins);
            SET_ARGUMENT_NAME(2, device);
            SET_ARGUMENT_NAME(3, baudrate);

            CHECK_ARGUMENTS_LENGTH_EQUAL(4);

            CHECK_ARGUMENT_TYPE_INT32(0);
            CHECK_ARGUMENT_TYPE_INT32(1);
            CHECK_ARGUMENT_TYPE_STRING(2);
            CHECK_ARGUMENT_TYPE_INT32(3);

            int pinBase = GET_ARGUMENT_AS_INT32(0);
            int numPins = GET_ARGUMENT_AS_INT32(1);
#if NODE_VERSION_AT_LEAST(0, 11, 0)
            String::Utf8Value device(GET_ARGUMENT_AS_STRING(2));
#else
            String::AsciiValue device(GET_ARGUMENT_AS_STRING(2));
#endif
            int baudrate = GET_ARGUMENT_AS_INT32(3);

            int res =::drcSetupSerial(pinBase, numPins, *device, baudrate);

            info.GetReturnValue().Set(res);
    }

    NAN_MODULE_INIT(init_drcSerial) {
            NAN_EXPORT(target, drcSetupSerial);
    }
}