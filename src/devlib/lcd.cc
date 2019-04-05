#include "lcd.h"
#include <lcd.h>

namespace nodewpi {
  NAN_METHOD(lcdHome) {
      SET_ARGUMENT_NAME(0, fd);

      CHECK_ARGUMENTS_LENGTH_EQUAL(1);

      CHECK_ARGUMENT_TYPE_INT32(0);

      int fd = GET_ARGUMENT_AS_INT32(0);

      ::lcdHome(fd);
  }

  NAN_METHOD(lcdClear) {
      SET_ARGUMENT_NAME(0, fd);

      CHECK_ARGUMENTS_LENGTH_EQUAL(1);

      CHECK_ARGUMENT_TYPE_INT32(0);

      int fd = GET_ARGUMENT_AS_INT32(0);

      ::lcdClear(fd);
  }

  NAN_METHOD(lcdDisplay) {
      SET_ARGUMENT_NAME(0, fd);
      SET_ARGUMENT_NAME(1, state);

      CHECK_ARGUMENTS_LENGTH_EQUAL(2);

      CHECK_ARGUMENT_TYPE_INT32(0);
      CHECK_ARGUMENT_TYPE_INT32(1);

      int fd = GET_ARGUMENT_AS_INT32(0);
      int state = GET_ARGUMENT_AS_INT32(1);

      ::lcdDisplay(fd, state);
  }

  NAN_METHOD(lcdCursor) {
      SET_ARGUMENT_NAME(0, fd);
      SET_ARGUMENT_NAME(1, state);

      CHECK_ARGUMENTS_LENGTH_EQUAL(2);

      CHECK_ARGUMENT_TYPE_INT32(0);
      CHECK_ARGUMENT_TYPE_INT32(1);

      int fd = GET_ARGUMENT_AS_INT32(0);
      int state = GET_ARGUMENT_AS_INT32(1);

      ::lcdCursor(fd, state);
  }

  NAN_METHOD(lcdCursorBlink) {
      SET_ARGUMENT_NAME(0, fd);
      SET_ARGUMENT_NAME(1, state);

      CHECK_ARGUMENTS_LENGTH_EQUAL(2);

      CHECK_ARGUMENT_TYPE_INT32(0);
      CHECK_ARGUMENT_TYPE_INT32(1);

      int fd = GET_ARGUMENT_AS_INT32(0);
      int state = GET_ARGUMENT_AS_INT32(1);

      ::lcdCursorBlink(fd, state);
  }

  NAN_METHOD(lcdSendCommand) {
      SET_ARGUMENT_NAME(0, fd);
      SET_ARGUMENT_NAME(1, command);

      CHECK_ARGUMENTS_LENGTH_EQUAL(2);

      CHECK_ARGUMENT_TYPE_INT32(0);
      CHECK_ARGUMENT_TYPE_UINT32(1);

      int fd = GET_ARGUMENT_AS_INT32(0);
      int command = GET_ARGUMENT_AS_UINT32(1);

      ::lcdSendCommand(fd, command);
  }

  NAN_METHOD(lcdPosition) {
      SET_ARGUMENT_NAME(0, fd);
      SET_ARGUMENT_NAME(1, x);
      SET_ARGUMENT_NAME(2, y);

      CHECK_ARGUMENTS_LENGTH_EQUAL(3);

      CHECK_ARGUMENT_TYPE_INT32(0);
      CHECK_ARGUMENT_TYPE_INT32(1);
      CHECK_ARGUMENT_TYPE_INT32(2);

      int fd = GET_ARGUMENT_AS_INT32(0);
      int x = GET_ARGUMENT_AS_INT32(1);
      int y = GET_ARGUMENT_AS_INT32(2);

      ::lcdPosition(fd, x, y);
  }

  NAN_METHOD(lcdCharDef) {
      SET_ARGUMENT_NAME(0, fd);
      SET_ARGUMENT_NAME(1, index);
      SET_ARGUMENT_NAME(2, data);

      CHECK_ARGUMENTS_LENGTH_EQUAL(3);

      CHECK_ARGUMENT_TYPE_INT32(0);
      CHECK_ARGUMENT_TYPE_INT32(1);
      CHECK_ARGUMENT_TYPE_ARRAY(2);
      CHECK_ARGUMENT_ARRAY_LENGTH(2, 8);

      int fd = GET_ARGUMENT_AS_INT32(0);
      int index = GET_ARGUMENT_AS_INT32(1);
      v8::Local<v8::Array> data = v8::Local<v8::Array>::Cast(info[2]);

      unsigned char ar[8];
      for (int i = 0; i < 8; i++) {
          ar[i] = data->Get(i)->Uint32Value() & 0xFF;
      }

      ::lcdCharDef(fd, index, ar);
  }

  NAN_METHOD(lcdPutchar) {
      SET_ARGUMENT_NAME(0, fd);
      SET_ARGUMENT_NAME(1, data);

      CHECK_ARGUMENTS_LENGTH_EQUAL(2);

      CHECK_ARGUMENT_TYPE_INT32(0);
      CHECK_ARGUMENT_TYPE_UINT32(1);

      int fd = GET_ARGUMENT_AS_INT32(0);
      unsigned int data = GET_ARGUMENT_AS_UINT32(1);

      ::lcdPutchar(fd, data);
  }

  NAN_METHOD(lcdPuts) {
      SET_ARGUMENT_NAME(0, fd);
      SET_ARGUMENT_NAME(1, string);

      CHECK_ARGUMENTS_LENGTH_EQUAL(2);

      CHECK_ARGUMENT_TYPE_INT32(0);
      CHECK_ARGUMENT_TYPE_STRING(1);

      int fd = GET_ARGUMENT_AS_INT32(0);
#if NODE_VERSION_AT_LEAST(0, 11, 0)
      v8::String::Utf8Value data(GET_ARGUMENT_AS_STRING(1));
#else
      v8::String::AsciiValue data(GET_ARGUMENT_AS_STRING(1));
#endif

      ::lcdPuts(fd, *data);
  }

  NAN_METHOD(lcdPrintf) {
      lcdPuts(info);
  }

  NAN_METHOD(lcdInit) {
      SET_ARGUMENT_NAME(0, rows);
      SET_ARGUMENT_NAME(1, cols);
      SET_ARGUMENT_NAME(2, bits);
      SET_ARGUMENT_NAME(3, rs);
      SET_ARGUMENT_NAME(4, strb);
      SET_ARGUMENT_NAME(5, d0);
      SET_ARGUMENT_NAME(6, d1);
      SET_ARGUMENT_NAME(7, d2);
      SET_ARGUMENT_NAME(8, d3);
      SET_ARGUMENT_NAME(9, d4);
      SET_ARGUMENT_NAME(10, d5);
      SET_ARGUMENT_NAME(11, d6);
      SET_ARGUMENT_NAME(12, d7);

      CHECK_ARGUMENTS_LENGTH_EQUAL(13);

      CHECK_ARGUMENT_TYPE_INT32(0);
      CHECK_ARGUMENT_TYPE_INT32(1);
      CHECK_ARGUMENT_TYPE_INT32(2);
      CHECK_ARGUMENT_TYPE_INT32(3);
      CHECK_ARGUMENT_TYPE_INT32(4);
      CHECK_ARGUMENT_TYPE_INT32(5);
      CHECK_ARGUMENT_TYPE_INT32(6);
      CHECK_ARGUMENT_TYPE_INT32(7);
      CHECK_ARGUMENT_TYPE_INT32(8);
      CHECK_ARGUMENT_TYPE_INT32(9);
      CHECK_ARGUMENT_TYPE_INT32(10);
      CHECK_ARGUMENT_TYPE_INT32(11);
      CHECK_ARGUMENT_TYPE_INT32(12);

      int rows = GET_ARGUMENT_AS_INT32(0);
      int cols = GET_ARGUMENT_AS_INT32(1);
      int bits = GET_ARGUMENT_AS_INT32(2);
      int rs = GET_ARGUMENT_AS_INT32(3);
      int strb = GET_ARGUMENT_AS_INT32(4);
      int d0 = GET_ARGUMENT_AS_INT32(5);
      int d1 = GET_ARGUMENT_AS_INT32(6);
      int d2 = GET_ARGUMENT_AS_INT32(7);
      int d3 = GET_ARGUMENT_AS_INT32(8);
      int d4 = GET_ARGUMENT_AS_INT32(9);
      int d5 = GET_ARGUMENT_AS_INT32(10);
      int d6 = GET_ARGUMENT_AS_INT32(11);
      int d7 = GET_ARGUMENT_AS_INT32(12);

      int res =::lcdInit(rows, cols, bits, rs, strb, d0, d1, d2, d3, d4, d5, d6, d7);

      info.GetReturnValue().Set(res);
  }

  NAN_MODULE_INIT(init_lcd) {
      NAN_EXPORT(target, lcdHome);
      NAN_EXPORT(target, lcdClear);
      NAN_EXPORT(target, lcdDisplay);
      NAN_EXPORT(target, lcdCursor);
      NAN_EXPORT(target, lcdCursorBlink);
      NAN_EXPORT(target, lcdSendCommand);
      NAN_EXPORT(target, lcdPosition);
      NAN_EXPORT(target, lcdCharDef);
      NAN_EXPORT(target, lcdPutchar);
      NAN_EXPORT(target, lcdPuts);
      NAN_EXPORT(target, lcdPrintf);
      NAN_EXPORT(target, lcdInit);

      EXPORT_CONSTANT_INT(MAX_LCDS);
  }
}