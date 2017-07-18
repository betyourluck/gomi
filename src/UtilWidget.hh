//
// Created by conan on 17/07/18.
//
#ifndef GIMAGE_UTILWIDGET_HH
#define GIMAGE_UTILWIDGET_HH

#include <gtkmm.h>
#include <glibmm.h>

class UtilWidget
{
public:
    template<class Widget>
    static Glib::RefPtr<Widget>
    concreteWidget(const Glib::RefPtr<Gtk::Builder>& refBuilder, const Glib::ustring& name)
    {
        Widget* pWidget(nullptr);
        refBuilder->get_widget(name, pWidget);
        return Glib::RefPtr<Widget>(pWidget);
    }
};

#endif //GIMAGE_UTILWIDGET_HH
