#include "mcp3004.h"
#include <mcp3004.h>

// Func : int mcp3004Setup(int pinBase, int spiChannel)

namespace nodewpi {
  NAN_METHOD(mcp3004Setup) {
      SET_ARGUMENT_NAME(0, pinBase);
      SET_ARGUMENT_NAME(1, spiChannel);

      CHECK_ARGUMENTS_LENGTH_EQUAL(2);

      CHECK_ARGUMENT_TYPE_INT32(0);
      CHECK_ARGUMENT_TYPE_INT32(1);

      int pinBase = GET_ARGUMENT_AS_INT32(0);
      int spiChannel = GET_ARGUMENT_AS_INT32(1);

      const std::vector<int> validSpiChannel = { 0, 1 };

      if (find_int(spiChannel, validSpiChannel)) {
        int res =::mcp3004Setup(pinBase, spiChannel);

        info.GetReturnValue().Set(res);
      } else {
        //throw error
      }
  }

  NAN_MODULE_INIT(init_mcp3004) {
      NAN_EXPORT(target, mcp3004Setup);
  }
}