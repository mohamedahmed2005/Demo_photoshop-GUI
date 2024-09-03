#ifndef DEMO_PHOTOSHOP_H
#define DEMO_PHOTOSHOP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class demo_photoshop;
}
QT_END_NAMESPACE

class demo_photoshop : public QMainWindow
{
    Q_OBJECT

public:
    demo_photoshop(QWidget *parent = nullptr);
    ~demo_photoshop();

private:
    Ui::demo_photoshop *ui;
};
#endif // DEMO_PHOTOSHOP_H
