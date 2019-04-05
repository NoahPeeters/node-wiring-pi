#ifndef _WPI_MCP23S17_H_
#define _WPI_MCP23S17_H_

#include "../addon.h"

namespace nodewpi {
  NAN_METHOD(mcp23s17Setup);

  NAN_MODULE_INIT(init_mcp23s17);
}

#endif