#include "pcf8591.h"
#include <pcf8591.h>

// Func : int pcf8591Setup(const int pinBase, const int i2cAddress)

namespace nodewpi {
    NAN_METHOD(pcf8591Setup) {
            SET_ARGUMENT_NAME(0, pinBase);
            SET_ARGUMENT_NAME(1, i2cAddress);

            CHECK_ARGUMENTS_LENGTH_EQUAL(2);

            CHECK_ARGUMENT_TYPE_INT32(0);
            CHECK_ARGUMENT_TYPE_INT32(1);

            int pinBase = GET_ARGUMENT_AS_INT32(0);
            int i2cAddress = GET_ARGUMENT_AS_INT32(1);

            int res =::pcf8591Setup(pinBase, i2cAddress);

            info.GetReturnValue().Set(res);
    }

    NAN_MODULE_INIT(init_pcf8591) {
            NAN_EXPORT(target, pcf8591Setup);
    }
}