#include "mcp23s08.h"
#include <mcp23s08.h>

// Func int mcp23s08Setup(const int pinBase, const int spiChannel, const int devId)

namespace nodewpi {
    NAN_METHOD(mcp23s08Setup) {
            SET_ARGUMENT_NAME(0, pinBase);
            SET_ARGUMENT_NAME(1, spiChannel);
            SET_ARGUMENT_NAME(2, devId);

            CHECK_ARGUMENTS_LENGTH_EQUAL(3);

            CHECK_ARGUMENT_TYPE_INT32(0);
            CHECK_ARGUMENT_TYPE_INT32(1);
            CHECK_ARGUMENT_TYPE_INT32(2);

            int pinBase = GET_ARGUMENT_AS_INT32(0);
            int spiChannel = GET_ARGUMENT_AS_INT32(1);
            int devId = GET_ARGUMENT_AS_INT32(2);

            const std::vector<int> validSpiChannel = { 0, 1 };

            if (find_int(spiChannel, validSpiChannel)) {
                //MCP23S08 3bits addressing
                if (devId >= 0 && devId <= 7) {
                    int res =::mcp23s08Setup(pinBase, spiChannel, devId);

                    info.GetReturnValue().Set(res);
                } else {
                    //throw error
                }
            } else {
                //throw error
            }
    }

    NAN_MODULE_INIT(init_mcp23s08) {
            NAN_EXPORT(target, mcp23s08Setup);
    }
}