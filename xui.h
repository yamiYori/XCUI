#ifndef __XUI_H_
#define __XUI_H_

#include<string>
#include"XCUI.h"

namespace XCUI
{

	class WidgetBase{
	public:
		std::string wgtName;            //Must be unique below one parent
		bool enable;
		bool visble;
        const bool operatable;

		point pos;
        rect size;

		int _event OnLoad(){};
		int _event OnShow(){};
		int _event OnHide(){};
		int _event OnRefresh(){};

		virtual int Print_to_display_buffer(byte **canvas){};
		virtual void* Widgetctl(WidgetBase& activesrc, std::string& info){};   //for widget interactive
		virtual int Widgetctl(WidgetBase& activesrc, dword optname, const void *optval){};   //unix style widget interactive

		virtual int Refresh(byte **canvas) final;

	};




}
#endif
