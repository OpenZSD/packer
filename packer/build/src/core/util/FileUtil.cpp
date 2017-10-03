#include "FileUtil.hpp"

namespace GameIO
{
   using namespace std;

   int64_t dumpTxtFile(string path, string &data, uint64_t buffSize)
   {
      char *buff = new char[buffSize+1]();
      FILE *f = fopen(path.c_str(), "r");
      int64_t size;

      if(f == 0)
      {
         return -1;
      }

      data = "";

      while(0 < (size = fread(buff,1,buffSize,f)))
      {
         buff[size] = '\0';
         data = data.append(buff);
      }

      return data.length();
   }

   int64_t dumpBinFile(string path, vector<uint8_t> &data, uint64_t buffSize)
   {
      int64_t dataSize = 0;
      int64_t inputSize = 0;
      data.clear();
      data.resize(100*buffSize);

      FILE *f = fopen(path.c_str(), "rb");

      if(f == 0)
      {
         return -1;
      }

      while(0 < (inputSize = fread(&data[dataSize],1,buffSize,f)))
      {
         dataSize += inputSize;
         if(dataSize+buffSize >= data.size())
         {
            data.resize(data.size()*2);
         }
      }

      return dataSize;
   }

   uint64_t getLInt(FILE *f)
   {
      uint8_t prt = fgetc(f);
      uint64_t num = prt;
      
      for(int i = 0; i < 7; i++)
      {
         prt = fgetc(f);
         num *= 256;
         num += prt;
      }
   }

   void writeLInt(FILE *f, uint64_t val)
   {
      uint8_t parts[8];
      for(int i = 0; i < 8; i++)
      {
         parts[i] = val % 256;
         val /= 256;
      }
      for(int i = 7; i >= 0; i--) { fputc(parts[i], f); }
   }

   string getStr(FILE *f)
   {
      char buff[257];
      int64_t inputSize = 0;
      bool hasTerm = false;
      string str;
      

      while(!hasTerm || (0 < (inputSize = fread(buff,1,256,f))))
      {
         buff[inputSize] = '\0';
         str = str.append(buff);

         for(int i = 0; i < inputSize; i++)
         {
            if(hasTerm = (buff[i] == '\0')) { break; }
         }
      }

      return str;
   }
}
