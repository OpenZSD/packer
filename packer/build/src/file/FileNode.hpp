#pragma once
#ifndef FILE_NODE_H
#define FILE_NODE_H

#include <stdio.h>
#include <cstdint>
#include <memory>
#include <vector>
#include <string>
#include <jsoncpp/json/json.h>

namespace GameIO
{
   using namespace std;

   typedef shared_ptr<class FileNode> FileNodePtr;
   typedef weak_ptr<class FileNode> FileNodeWPtr;

   struct FileStat
   {
      string mName;
      uint64_t mOffset;
      uint64_t mSize;
   };

   class FileNode
   {
   protected:
      class _SharedPtrOnly_FNode { public: _SharedPtrOnly_FNode() {} };

   public:
      FileNode() = delete;
      FileNode(_SharedPtrOnly_FNode closed) { }

      FileNodePtr createFile(FileStat &fileInfo, FileNodePtr parentFolder);
      FileNodePtr createFolder(string name, FileNodePtr parentFolder);
      FileNodePtr createFolder();

      FileNodePtr create(string &jsonData);

      void remove(FileNodePtr node);
      bool moveTo(FileNodePtr newParent);
      bool containsLocal(string &name);
      bool contains(FileNodePtr &node);

      bool isRoot() { return mParent.expired(); }
      bool isFile() { return !mIsFolder; }
      string name() { return mName; }
      string toString();
      string toJson();

   protected:
      Json::Value getJSonNode();
      
      bool mIsFolder;
      uint64_t mSize;
      uint64_t mOff;
      string mName;
      FileNodeWPtr mParent;
      vector<FileNodePtr> mFiles;
      vector<FileNodePtr> mFolders;
   };
}

#endif
