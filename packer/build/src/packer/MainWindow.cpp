#include "MainWindow.hpp"
#include <QMenuBar>
#include <QMenu>
#include <QTreeWidget>
#include <stdio.h>
#include <QLabel>
#include <QTreeWidgetItem>
#include "ui_PMainWindow.h"
#include "Util.hpp"
#include <QIcon>
//#include "UIFolderNode.hpp"

namespace Packer
{

   MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
   {
      Ui::UIMainWindow ui; 
      ui.setupUi(this);
      
      mTree = UIUtil::findAndAssert<QTreeWidget>("UITree", this);
      mTree->setDefaultDropAction(Qt::CopyAction);
      mRoot = new QTreeWidgetItem(mTree);
      mRoot->setText(0, "/");
      mRoot->setIcon(0, QIcon(":/folder.xpm"));
      mRoot->setFlags(mRoot->flags() | Qt::ItemIsDropEnabled);
      


      QTreeWidgetItem *x = new QTreeWidgetItem(mRoot);
      x->setText(0,"Test");
      x->setFlags(x->flags() | Qt::ItemIsDropEnabled);
      x->setIcon(0, QIcon(":/folder.xpm"));
      //x->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
      mRoot->addChild(x);
 /*  
      x = new QTreeWidgetItem(mTree);
      x->setText(0,"z");
      x->setFlags(x->flags() | Qt::ItemIsDropEnabled);
      //x->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
      //mRoot->addChild(x);

      QTreeWidgetItem *r = new QTreeWidgetItem(x);
      r->setText(0,"r");
      r->setFlags(r->flags() | Qt::ItemIsDropEnabled);
      //r->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsDragEnabled);
      //r->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
      r->setIcon(0, QIcon(":/folder.xpm"));
      x->addChild(r);*/
   }

   void MainWindow::addFolder()
   {
      
      printf("ping\n");
   }
   void MainWindow::addFile()
   {
      printf("ping1\n");
   }
   void MainWindow::removeFolder()
   {
      printf("ping2\n");
   }
   void MainWindow::removeFile()
   {
      printf("ping3\n");
   }
   void MainWindow::extractFile()
   {
      printf("pingr\n");
   }
   void MainWindow::openFile()
   {
      printf("ping3e\n");
   }
   void MainWindow::saveFile()
   {
      printf("pingre\n");
   }
   void MainWindow::unpackFile()
   {

   }
}
