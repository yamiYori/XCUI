#ifndef __XUI_H_
#define __XUI_H_

#include<string>
#include<vector>
#include"XCUI.h"

namespace XCUI
{

	class WidgetBase{
	private:
		bool shown;
		bool enable;
		bool visble;

		WidgetBase* parentWidget;
		std::vector<WidgetBase*> childWidgets;

		virtual int Print_to_display_buffer(byte **canvas){};

	public:
		std::string wgtName;            //Must be unique below one parent
        const bool operatable;

		point pos;
        rect size;

		void (*OnLoadHandler)();
		void (*OnShowHandler)();
		void (*OnHideHandler)();
		void (*OnRefreshHandler)();

		virtual void* Widgetctl(WidgetBase& activesrc, std::string& info){};   //for widget interactive
		virtual void* Widgetctl(WidgetBase& activesrc, dword optname, const void *optval){};   //unix style widget interactive

		virtual int Enable(bool op) final;
		virtual bool Enable() final;
		virtual int Visble(bool op) final;
		virtual bool Visble() final;
		virtual int Refresh(byte **canvas) final;

		int _event OnLoad() final;
		int _event OnShow() final;
		int _event OnHide() final;
		int _event OnRefresh() final;

		WidgetBase* GetParent();
		int SetParent(WidgetBase* src);
		template<typename T>
		T GetChild(std::string name);
		int AddChild(WidgetBase* src);
		int DelChild(std::string name);

		WidgetBase():
			shown(false),enable(true),visble(true),
			parentWidget(NULL),pos(0,0),size(0,0),
			OnLoadHandler(NULL),OnShowHandler(NULL),OnHideHandler(NULL),OnRefreshHandler(NULL){};

	};




}
#endif
