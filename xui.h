#ifndef __XUI_H_
#define __XUI_H_

#include<string>
#include"XCUI.h"

namespace XCUI
{


	class WidgetBase{
	public:
		std::string wgtName;            //Must be unique below one parent
		bool active;
		bool enable;
		bool visble;
        bool operatable;

		point pos;
        rect size;

		int _event OnLoad()={};
		int _event OnShow()={};
		int _event On

		virtual int  DrawBuf()={};
		virtual void* Widgetctl(WidgetBase& src,std::string& info)={};   //for widget interactive

	};




}
#endif
