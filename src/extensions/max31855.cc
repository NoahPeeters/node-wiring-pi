#include "max31855.h"
#include <max31855.h>

// Func : int max31855Setup(int pinBase, int spiChannel)

namespace nodewpi {
    NAN_METHOD(max31855Setup) {
            SET_ARGUMENT_NAME(0, pinBase);
            SET_ARGUMENT_NAME(1, spiChannel);

            CHECK_ARGUMENTS_LENGTH_EQUAL(2);

            CHECK_ARGUMENT_TYPE_INT32(0);
            CHECK_ARGUMENT_TYPE_INT32(1);

            int pinBase = GET_ARGUMENT_AS_INT32(0);
            int spiChannel = GET_ARGUMENT_AS_INT32(1);

            const std::vector<int> validSpiChannel = { 0, 1 };

            if (find_int(spiChannel, validSpiChannel)) {
              int res =::max31855Setup(pinBase, spiChannel);

              info.GetReturnValue().Set(res);
            } else {
              //throw error
            }
    }

    NAN_MODULE_INIT(init_max31855) {
            NAN_EXPORT(target, max31855Setup);
    }
}