//
// Created by conan on 17/07/08.
//
#include "UtilWidget.hh"
#include "MainWindow.hh"

MainWindow::MainWindow(BaseObjectType* base, const Glib::RefPtr<Gtk::Builder>& refBuilder)
        : Gtk::Window(base),
          builder(refBuilder),
          imageFilesView(nullptr),
          openButton(nullptr),
          saveButton(nullptr),
          fullscreenButton(nullptr),
          closeButton(nullptr),
          hScale(nullptr)
{
    imageFilesView   = UtilWidget::concreteWidget<Gtk::TreeView>(builder, "MainTreeView");
    openButton       = UtilWidget::concreteWidget<Gtk::ToolButton>(builder, "OpenButton");
    saveButton       = UtilWidget::concreteWidget<Gtk::ToolButton>(builder, "SaveButton");
    fullscreenButton = UtilWidget::concreteWidget<Gtk::ToolButton>(builder, "FullScreenButton");
    closeButton      = UtilWidget::concreteWidget<Gtk::ToolButton>(builder, "CloseButton");
    hScale           = UtilWidget::concreteWidget<Gtk::Scale>(builder, "HScale");

    // 範囲をセット
    hScale->set_range(1,5);
    // 変化量をセット
    hScale->set_increments( 1, 1 );
    // 初期値をセット
    hScale->set_value(1);

    createTreeView();

    openButton->signal_clicked().connect(
            sigc::mem_fun(*this, &MainWindow::on_button1_clicked));
    saveButton->signal_clicked().connect(
            sigc::mem_fun(*this, &MainWindow::on_button2_clicked));
    fullscreenButton->signal_clicked().connect(
            sigc::mem_fun(*this, &MainWindow::on_button3_clicked));
    closeButton->signal_clicked().connect(
            sigc::mem_fun(*this, &MainWindow::on_button4_clicked));

    show_all_children();
}

MainWindow::~MainWindow()
{
    Gtk::MessageDialog dlg( *this, "end");
    dlg.run();
}

void MainWindow::createTreeView()
{
    listStore = Gtk::ListStore::create(record);
    imageFilesView->set_model(listStore);

    imageFilesView->append_column("No", record.fileNo);
    imageFilesView->append_column("File Name", record.fileName);

    for(auto col: imageFilesView->get_columns())
    {
        col->set_resizable(true);
        col->set_expand(true);
    }

    Gtk::TreeModel::Row row;
    for( int i = 0; i < 10; ++i )
    {
        row = *(listStore->append());
        row[record.fileNo] = i;
        row[record.fileName] = "あああ";
    }
}

void MainWindow::on_button1_clicked()
{
    Gtk::MessageDialog dlg( *this, "4");
    dlg.run();
}

void MainWindow::on_button2_clicked()
{
    Gtk::MessageDialog dlg( *this, "4");
    dlg.run();
}

void MainWindow::on_button3_clicked()
{
    Gtk::MessageDialog dlg( *this, "4");
    dlg.run();
}

void MainWindow::on_button4_clicked()
{
    Gtk::MessageDialog dlg( *this, "Close OK?");
    dlg.run();
    close();
}


