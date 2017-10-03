#include "StrUtil.hpp"
#include <cctype>

namespace APUtil
{
   using namespace std;

   void tokenize(string str, string del, vector<string> &tok, bool trimTok)
   {
      long int pos = -1;
      while((pos=str.find(del, 0)) != string::npos)
      {
         tok.push_back(trimTok ? trim(str.substr(0, pos)) : str.substr(0, pos));
         str = trimTok ? trim(str.substr(pos+1)) : str.substr(pos+1);
      }
      if(str.length()) { tok.push_back(str); }
   }
   string trim(string str)
   {
      auto isBlank = [](char c) -> bool { return (c==' ')||(c=='\r')||(c=='\n')||(c=='\t')||(c=='\v'); };
      int fClip = 0;
      int bClip = 0;
      int len = str.length();

      while((fClip < len) && isBlank(str[fClip])) { fClip++; }
      while((bClip < len) && isBlank(str[len-1-bClip])) { bClip++; }
      return str.substr(fClip, len-fClip-bClip);
   }
   bool hasSpace(string &str)
   {
      for(char c : str) { if(isspace(c)) { return true; } }

      return false;
   }
   unsigned long int firstSpace(string &str, unsigned long int start)
   {
      for(start; start < str.length(); start++) { if(isspace(str[start])) { return start; } }
      return start;
   }
   long int getLong(string &str, long int defaultMin)
   {
      long int val;

      try
      {
         val = (val=stol(str)) >= defaultMin ? val : defaultMin;
      }
      catch(...)
      {
         val = defaultMin;
      }
      return val;
   }
   string toLower(string &str)
   {
      string out;
      for(char c : str) { out += tolower(c); }
      return out;
   }
}
