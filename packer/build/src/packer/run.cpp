#include <stdio.h>
#include <cstdint>
#include <memory>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <functional>
#include <set>
#include <unordered_set>
#include <array>
#include <string>
#include <png++/png.hpp>

#include <QApplication>
#include <QWidget>
#include "MainWindow.hpp"


//#include "../core/util/FileUtil.hpp"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   Packer::MainWindow window;

   //window.resize(950, 750);
   window.setWindowTitle("Packer");
 
   window.show();

   return app.exec();
}
