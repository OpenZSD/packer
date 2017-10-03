#include "UIFolderList.hpp"
#include <QDrag>
#include <QDropEvent>
#include <QPixmap>
#include <QMouseEvent>
#include <QMimeData>
#include <QtGlobal>
#include <QTime>

namespace Packer
{
   using namespace std;

   UIFolderList::UIFolderList(QWidget *parent)
      : QTreeWidget(parent)
   {
      //setText(0, "/");
      //setIcon(0, QIcon(":/folder.xpm"));
      setDragDropMode(QAbstractItemView::DragDrop);
      setDragEnabled(true);
      mDrag = 0;

      qsrand(QTime::currentTime().msec());
   }

   UIFolderList::~UIFolderList()
   {
      printf("Hello  bye bye\n");
   }

   void UIFolderList::startDrag(Qt::DropActions supportedActions)
   {

        mDrag = new QDrag(this);
        QMimeData *mimeData = new QMimeData();

        mimeData->setText("HELLO | Something | something");
        mDrag->setMimeData(mimeData);
        mDrag->setPixmap(QPixmap(":/folder.xpm"));

        Qt::DropAction dropAction = mDrag->exec(Qt::MoveAction | Qt::CopyAction, Qt::MoveAction);
   }

   void UIFolderList::dragEnterEvent(QDragEnterEvent *event)
   {
      event->accept();
   }

   void UIFolderList::dragMoveEvent(QDragMoveEvent *event)
   {
      event->accept();
   }

   void UIFolderList::dropEvent(QDropEvent *event)
   {
      printf(">> %s\n", event->mimeData()->text().toStdString().c_str());
      event->acceptProposedAction();
   }

   void UIFolderList::rebuildTree()
   {
   }
}

