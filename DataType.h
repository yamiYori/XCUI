#ifndef _DATATYPE_H_
#define _DATATYPE_H_

#include "config.h"

namespace XCUI
{
    struct rect{
        int x;
        int y;

        rect(int ax,int ay):x(ax),y(ay){};
    };
    typedef rect point;

#ifndef XCUI_DISABLE_POPULAR_TYPEDEF
    typedef unsigned char byte;
    typedef unsigned short word;
    typedef unsigned long dword;
    typedef unsigned long long qword;
#endif  //XCUI_DISABLE_POPULAR_TYPEDEF

}
#endif  //_DATATYPE_H_
