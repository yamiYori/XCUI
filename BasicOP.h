#ifndef __BASICOP_H_
#define __BASICOP_H_

#include "config.h"
#include "XCUI.h"
#define _plat               //as platform code
#define _event virtual      //as object callback event

namespace XCUI
{
    int _plat GetWindowSize(int &width,int &height);
    int _plat SetResizeHook();

}
#endif
