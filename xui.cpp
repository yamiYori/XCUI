#include "xui.h"

namespace XCUI
{
    int WidgetBase::Enable(bool op){
        if(op && !enable){

        }else if(!op && enable){

        }
        enable=op;
    }
    bool WidgetBase::Enable(){
        return enable;
    }
    int WidgetBase::Visble(bool op){
        if(op && !visble){

        }else if(!op && visble){

        }
        visble=op;
    }
    bool WidgetBase::Visble(){
        return visble;
    }

    int WidgetBase::Refresh(byte **canvas){
        if(enable){
            if(!shown&&visble){
                OnShow();
                shown=true;
            }else if(shown&&!visble){
                OnHide();
                shown=false;
            }
            if(visble){
                OnRefresh();
                Print_to_display_buffer(canvas);
            }
        }else{
            if(shown){
                OnHide();
                shown=false;
            }
        }
    }

    int WidgetBase::OnLoad(){
        if(enable){
            if(OnLoadHandler!=NULL){
                OnLoadHandler();
            }
        }
    }

    int WidgetBase::OnShow(){
        if(enable){
            if(OnShowHandler!=NULL){
                OnShowHandler();
            }
        }
    }

    int WidgetBase::OnHide(){
        if(enable){
            if(OnHideHandler!=NULL){
                OnHideHandler();
            }
        }
    }

    int WidgetBase::OnRefresh(){
        if(enable){
            if(OnRefreshHandler!=NULL){
                OnRefreshHandler();
            }
        }
    }

//FIXME: a widget shouldn't become its parent or child, directly or indirectly
    WidgetBase* WidgetBase::GetParent(){
        if(parentWidget!=NULL){
            return parentWidget;
        }else{
            return NULL;
        }
    }
    int WidgetBase::SetParent(WidgetBase* src){
        if(parentWidget!=NULL){
            parentWidget->DelChild(this->wgtName);
        }
        parentWidget=src;
        if(parentWidget!=NULL){
            parentWidget->AddChild(this);
        }
    }
    template<typename T>
    T WidgetBase::GetChild(std::string name){
        auto z=childWidgets.end();
        for(auto i = childWidgets.begin(); i!=z; i++){
            if(i->wgtName==name){
                return (T)(*i);
            }
        }
    }
    int WidgetBase::AddChild(WidgetBase *src){
        auto z=childWidgets.end();
        for(auto i=childWidgets.begin(); i!=z; i++){
            if(i->wgtName==src->wgtName){
                return -1;
            }
        }
        src->parentWidget=this;
        return 0;
    }
    int WidgetBase::DelChild(std::string name){
        auto z=childWidgets.end();
        for(auto i = childWidgets.begin(); i!=z; i++){
            if(i->wgtName==name){
                i->parentWidget=this;
                childWidgets.erase(i);
                return 0;
            }
        }
        return -1;
    }
}
