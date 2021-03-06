//
// Created by conan on 17/07/08.
//
#ifndef GIMAGE_MAINWINDOW_HH
#define GIMAGE_MAINWINDOW_HH

#include <gtkmm.h>
#include <glibmm.h>

class MainWindow : public Gtk::Window
{
private:
    Glib::RefPtr<Gtk::Builder>    builder;
    Glib::RefPtr<Gtk::TreeView>   imageFilesView;
    Glib::RefPtr<Gtk::ToolButton> openButton;
    Glib::RefPtr<Gtk::ToolButton> saveButton;
    Glib::RefPtr<Gtk::ToolButton> fullscreenButton;
    Glib::RefPtr<Gtk::ToolButton> closeButton;
    Glib::RefPtr<Gtk::Scale>      hScale;
    Glib::RefPtr<Gtk::ListStore>  listStore;

    /**
     * @class TreeViewRecord
     * @details
     */
    class TreeViewRecord : public Gtk::TreeModel::ColumnRecord
    {
    public:
        TreeViewRecord() { add(fileNo); add(fileName);}

        Gtk::TreeModelColumn<int> fileNo;
        Gtk::TreeModelColumn<Glib::ustring> fileName;
    };

    TreeViewRecord record;

protected:
    void createTreeView();

public:
    MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);
    virtual ~MainWindow();

public:
    //Signal
    void on_open_button_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_close_button_clicked();

};


#endif //GIMAGE_MAINWINDOW_HH
