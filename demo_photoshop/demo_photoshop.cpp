#include "demo_photoshop.h"
#include "ui_demo_photoshop.h"

demo_photoshop::demo_photoshop(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::demo_photoshop)
{
    ui->setupUi(this);
}

demo_photoshop::~demo_photoshop()
{
    delete ui;
}
