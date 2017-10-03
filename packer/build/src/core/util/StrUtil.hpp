#pragma once
#ifndef STR_UTIL_H
#define STR_UTIL_H

#include "../../ExtCommonHeaders.hpp"

namespace APUtil
{
   using namespace std;

   void tokenize(string str, string del, vector<string> &tok, bool trimTok = false);
   string trim(string str);
   bool hasSpace(string &str);
   unsigned long int firstSpace(string &str, unsigned long int start = 0);
   long int getLong(string &str, long int defaultMin = -1);
   string toLower(string &str);
}

#endif
