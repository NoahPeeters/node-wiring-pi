#ifndef _WPI_LCD_H_
#define _WPI_LCD_H_

#include "../addon.h"

namespace nodewpi {
  NAN_METHOD(lcdHome);
  NAN_METHOD(lcdClear);
  NAN_METHOD(lcdDisplay);
  NAN_METHOD(lcdCursor);
  NAN_METHOD(lcdCursorBlink);
  NAN_METHOD(lcdSendCommand);
  NAN_METHOD(lcdPosition);
  NAN_METHOD(lcdCharDef);
  NAN_METHOD(lcdPutchar);
  NAN_METHOD(lcdPuts);
  NAN_METHOD(lcdPrintf);
  NAN_METHOD(lcdInit);

  NAN_MODULE_INIT(init_lcd);
}

#endif