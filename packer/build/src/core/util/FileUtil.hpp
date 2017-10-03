#pragma once
#ifndef FILE_UTIL_H
#define FILE_UTIL_H

#include <stdio.h>
#include <cstdint>
#include <memory>
#include <vector>
#include <string>

namespace GameIO
{
   using namespace std;

   int64_t dumpTxtFile(string path, string &data, uint64_t buffSize = 1024);
   int64_t dumpBinFile(string path, vector<uint8_t> &data, uint64_t buffSize = 1024);
   uint64_t getLInt(FILE *f);
   void writeLInt(FILE *f, uint64_t val);
   string getStr(FILE *f);
}

#endif
