#include "FNameValidator.hpp"

namespace EditorCommon
{
   FNameValidator::FNameValidator(QObject *parent)
      :QValidator(parent)
   {

   }
   FNameValidator::~FNameValidator()
   {

   }
   void FNameValidator::fixup(QString &input) const
   {
      for(int i = 0; i < input.length(); i++)
      {
         if(!isValidChar(input[i].toAscii()))
         {
            input[i] = QChar('_');
         }
      }
   }
   QValidator::State FNameValidator::validate(QString &input, int &pos) const
   {
      bool valid = true;

      for(auto c : input)
      {
         valid = isValidChar(c.toAscii());
         if(!valid) { break; }
      }

      return valid ? QValidator::Acceptable : QValidator::Invalid;
   }
   bool FNameValidator::isValidChar(char v) const
   {
      auto isAlpha = [](char c)->bool
      {
         return ('A'<=c && 'Z'>=c) || ('a'<=c && 'z'>=c);
      };
      auto isOther = [](char c)->bool
      {
         return ('.'==c)||(' '==c)||('('==c)||(')'==c)||('['==c)||(']'==c)
                ||('{'==c)||('}'==c)||('_'==c)||('-'==c)||('+'==c);
      };
      auto isNum = [](char c)->bool
      {
         return ('0'<=c && '9'>=c);
      };

      return isAlpha(v) || isOther(v) || isNum(v);
   }
}
