#include "gertboard.h"
#include <gertboard.h>

namespace nodewpi {
  NAN_METHOD(gertboardAnalogSetup) {
      SET_ARGUMENT_NAME(0, pinBase);

      CHECK_ARGUMENTS_LENGTH_EQUAL(1);

      CHECK_ARGUMENT_TYPE_INT32(0);

      int pinBase = GET_ARGUMENT_AS_INT32(0);

      int res =::gertboardAnalogSetup(pinBase);

      info.GetReturnValue().Set(res);
  }

  NAN_MODULE_INIT(init_gertboard) {
      NAN_EXPORT(target, gertboardAnalogSetup);
  }
}