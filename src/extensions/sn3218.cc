#include "sn3218.h"
#include <sn3218.h>

// Func : int sn3128Setup(int pinBase)

namespace nodewpi {
  NAN_METHOD(sn3218Setup) {
      SET_ARGUMENT_NAME(0, pinBase);

      CHECK_ARGUMENTS_LENGTH_EQUAL(1);

      CHECK_ARGUMENT_TYPE_INT32(0);

      int pinBase = GET_ARGUMENT_AS_INT32(0);

      int res =::sn3218Setup(pinBase);

      info.GetReturnValue().Set(res);
  }

  NAN_MODULE_INIT(init_sn3218) {
      NAN_EXPORT(target, sn3218Setup);
  }
}