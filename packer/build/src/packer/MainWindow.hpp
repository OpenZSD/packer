#pragma once
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

class QMenuBar;
class QMenu;
class QTreeWidget;
class QTreeWidgetItem;

namespace Packer
{
   class MainWindow : public QMainWindow
   {
      Q_OBJECT
     
   public:
      MainWindow(QWidget *parent = 0);

   signals:
      void hasFile(bool hasIt);

   private slots:
      void addFolder();
      void addFile();
      void removeFolder();
      void removeFile();
      void extractFile();
      void saveFile();
      void openFile();
      void unpackFile();

   private:
      QTreeWidget *mTree;
      QTreeWidgetItem *mRoot;
/*      QMenuBar *mBar;
      QMenu *mFile;
      QMenu *mSettings;*/
   };
}
#endif
