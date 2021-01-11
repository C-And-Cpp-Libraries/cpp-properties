#include <iostream>

#include <QApplication>
#include <QWidget>

#include "cppproperties/properties.hpp"
#include "cppproperties/qt_widgets/factory.hpp"

struct shape :
    tct::properties::properties
{
    MAKE_PROPERTY(enabled, bool);
    MAKE_PROPERTY(x, int);
    MAKE_PROPERTY(y, int);
};

struct circle :
    shape
{
    MAKE_PROPERTY(radius, int);
};

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    circle s;

    // Set some property values
    s.x = 24;
    s.y = 48;
    s.radius = 14;

    // Create widget
    auto w = tct::properties::qt_widgets::factory::build_form(s);
    if (w)
        w->show();

    return a.exec();
}
