#include "UIFileList.hpp"

namespace Packer
{
   UIFileList::UIFileList(QWidget *parent)
      : QTableView(parent)
   {
   }

   UIFileList::~UIFileList()
   {
      printf("Hello  bye bye\n");
   }

   void UIFileList::startDrag(Qt::DropActions supportedActions)
   {
   }
}

