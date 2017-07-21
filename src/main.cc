#include <memory>
#include <gtkmm.h>
#include "MainWindow.hh"

using PWindow = std::shared_ptr<MainWindow>;
int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gnome.gimage");
    auto builder = Gtk::Builder::create_from_resource("/org/gnome/gimage/mainwindow", "MainWindow");

    MainWindow* pWin;
    builder->get_widget_derived("MainWindow", pWin);
    PWindow pWindow = PWindow(pWin);
    return app->run(*pWindow);
}
