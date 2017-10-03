#pragma once
#ifndef UI_FOLDER_NODE_H
#define UI_FOLDER_NODE_H

#include <QTreeWidget>
class QDrag;
class QDropEvent;

namespace Packer
{
   using namespace std;

   class UIFolderList : public QTreeWidget
   {
      Q_OBJECT

   public:
      UIFolderList(QWidget *parent = 0);
      virtual ~UIFolderList();

   protected:
      virtual void startDrag(Qt::DropActions supportedActions);
      virtual void dragEnterEvent(QDragEnterEvent *event);
      virtual void dragMoveEvent(QDragMoveEvent *event);
      virtual void dropEvent(QDropEvent *event);

   protected slots:
      void rebuildTree();

   private:
      QDrag *mDrag;
      QPoint mDragStart;
   };
}

#endif
