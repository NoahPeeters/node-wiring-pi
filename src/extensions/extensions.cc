#include "extensions.h"

#include "drcSerial.h"
#include "max5322.h"
#include "max31855.h"
#include "mcp23s08.h"
#include "mcp23s17.h"
#include "mcp3002.h"
#include "mcp3004.h"
#include "mcp3422.h"
#include "mcp4802.h"
#include "mcp23008.h"
#include "mcp23016.h"
#include "mcp23017.h"
#include "pcf8574.h"
#include "pcf8591.h"
#include "sn3218.h"
#include "sr595.h"

namespace nodewpi {
    NAN_MODULE_INIT(init_extensions) {
            nodewpi::init_drcSerial(target);
            nodewpi::init_max5322(target);
            nodewpi::init_max31855(target);
            nodewpi::init_mcp23s08(target);
            nodewpi::init_mcp23s17(target);
            nodewpi::init_mcp3002(target);
            nodewpi::init_mcp3004(target);
            nodewpi::init_mcp3422(target);
            nodewpi::init_mcp4802(target);
            nodewpi::init_mcp23008(target);
            nodewpi::init_mcp23016(target);
            nodewpi::init_mcp23017(target);
            nodewpi::init_pcf8574(target);
            nodewpi::init_pcf8591(target);
            nodewpi::init_sn3218(target);
            nodewpi::init_sr595(target);
    }
}
