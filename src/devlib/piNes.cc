#include "piNes.h"
#include <piNes.h>

namespace nodewpi {
  NAN_METHOD(setupNesJoystick) {
      SET_ARGUMENT_NAME(0, dPin);
      SET_ARGUMENT_NAME(1, cPin);
      SET_ARGUMENT_NAME(2, lPin);

      CHECK_ARGUMENTS_LENGTH_EQUAL(3);

      CHECK_ARGUMENT_TYPE_INT32(0);
      CHECK_ARGUMENT_TYPE_INT32(1);
      CHECK_ARGUMENT_TYPE_INT32(2);

      int dPin = GET_ARGUMENT_AS_INT32(0);
      int cPin = GET_ARGUMENT_AS_INT32(1);
      int lPin = GET_ARGUMENT_AS_INT32(2);

      int res =::setupNesJoystick(dPin, cPin, lPin);

      info.GetReturnValue().Set(res);
  }

  NAN_METHOD(readNesJoystick) {
      SET_ARGUMENT_NAME(0, joystick);

      CHECK_ARGUMENTS_LENGTH_EQUAL(1);

      CHECK_ARGUMENT_TYPE_INT32(0);

      int joystick = GET_ARGUMENT_AS_INT32(0);

      unsigned int res =::readNesJoystick(joystick);

      info.GetReturnValue().Set(res);
  }

  NAN_MODULE_INIT(init_piNes) {
      NAN_EXPORT(target, setupNesJoystick);
      NAN_EXPORT(target, readNesJoystick);

      EXPORT_CONSTANT_INT(MAX_NES_JOYSTICKS);
      EXPORT_CONSTANT_INT(NES_RIGHT);
      EXPORT_CONSTANT_INT(NES_LEFT);
      EXPORT_CONSTANT_INT(NES_DOWN);
      EXPORT_CONSTANT_INT(NES_UP);
      EXPORT_CONSTANT_INT(NES_START);
      EXPORT_CONSTANT_INT(NES_SELECT);
      EXPORT_CONSTANT_INT(NES_A);
      EXPORT_CONSTANT_INT(NES_B);
  }
}