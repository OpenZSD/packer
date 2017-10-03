#pragma once

#ifndef UTIL_H
#define UTIL_H

#include <QString>
#include <QWidget>
#include <QMessageBox>

namespace UIUtil
{
   using namespace std;

   template <class T> T *findAndAssert(QString id, QWidget *root)
   {
      T *w = root->findChild<T *>(id);

      if(!w)
      {
         QMessageBox::critical(root , QString("Critical Application Error"), QString("Missing UI element: ") + id);
         exit(EXIT_FAILURE);
      }

      return w;
   }
}

#endif
