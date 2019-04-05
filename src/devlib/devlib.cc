#include "devlib.h"

#include "ds1302.h"
#include "gertboard.h"
#include "lcd.h"
#include "lcd128x64.h"
#include "maxdetect.h"
#include "piFace.h"
#include "piGlow.h"
#include "piNes.h"

namespace nodewpi {
  NAN_MODULE_INIT(init_devlib) {
      init_ds1302(target);
      init_gertboard(target);
      init_lcd(target);
      init_lcd128x64(target);
      init_maxdetect(target);
      init_piFace(target);
      init_piGlow(target);
      init_piNes(target);
  }
}
