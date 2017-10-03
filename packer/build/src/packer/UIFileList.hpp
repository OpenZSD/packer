#pragma once
#ifndef UI_FILE_LIST_H
#define UI_FILE_LIST_H

#include <QTableView>
#include "../ExtCommonHeaders.hpp"

namespace Packer
{
   class UIFileList : public QTableView
   {
      Q_OBJECT

   public:
      UIFileList(QWidget *parent = 0);
      virtual ~UIFileList();

   protected:
      virtual void startDrag(Qt::DropActions supportedActions);

   //private:
   };
}

#endif
