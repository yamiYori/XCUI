#include "xui.h"

namespace XCUI
{
    int WidgetBase::Refresh(byte **canvas){
        OnShow();
        Print_to_display_buffer(canvas);
    }
}
