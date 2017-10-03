#pragma once
#ifndef FNAME_VALIDATOR_H
#define FNAME_VALIDATOR_H

#include <QValidator>

namespace EditorCommon
{
   class FNameValidator : public QValidator
   {
      Q_OBJECT

   public:
      FNameValidator(QObject * parent = 0);
      virtual ~FNameValidator();
      virtual void fixup(QString &input) const;
      virtual QValidator::State validate(QString &input, int &pos) const;
   protected:
      bool isValidChar(char v) const;
   };
}

#endif
