#include "mcp23016.h"
#include <mcp23016.h>

// Func : int mcp23016Setup(int pinBase, int i2cAddress)

namespace nodewpi {
    NAN_METHOD(mcp23016Setup) {
            SET_ARGUMENT_NAME(0, pinBase);
            SET_ARGUMENT_NAME(1, i2cAddress);

            CHECK_ARGUMENTS_LENGTH_EQUAL(2);

            CHECK_ARGUMENT_TYPE_INT32(0);
            CHECK_ARGUMENT_TYPE_INT32(1);

            int pinBase = GET_ARGUMENT_AS_INT32(0);
            int i2cAddress = GET_ARGUMENT_AS_INT32(1);

            int res =::mcp23016Setup(pinBase, i2cAddress);

            info.GetReturnValue().Set(res);
    }

    NAN_MODULE_INIT(init_mcp23016) {
            NAN_EXPORT(target, mcp23016Setup);
    }
}