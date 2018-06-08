#ifndef _XCUI_BASE_H_
#define _XCUI_BASE_H_

#include "config.h"
#define _plat               //as platform code
#define _event virtual      //as object callback event

int _plat GetWindowSize(int &width,int &height);
int _plat SetResizeHook();


#endif

//GenerateConsoleCtrlEvent