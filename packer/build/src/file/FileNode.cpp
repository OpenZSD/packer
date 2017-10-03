#include "FileNode.hpp"
#include <tuple>
#include <queue>

namespace GameIO
{
   using namespace std;

   FileNodePtr FileNode::createFile(FileStat &fileInfo, FileNodePtr parentFolder)
   {
      FileNodePtr node = nullptr;
      if((parentFolder != nullptr) && parentFolder->mIsFolder)
      {
         node = make_shared<FileNode>(_SharedPtrOnly_FNode());
         node->mIsFolder = false;
         node->mSize = fileInfo.mSize;
         node->mOff = fileInfo.mOffset;
         node->mName = fileInfo.mName;
         node->mParent = parentFolder;
      }
      return node;
   }
   FileNodePtr FileNode::createFolder(string name, FileNodePtr parentFolder)
   {
      FileNodePtr node = nullptr;
      if(parentFolder->mIsFolder)
      {
         node = make_shared<FileNode>(_SharedPtrOnly_FNode());
         node->mIsFolder = true;
         node->mName = name;
         node->mSize = 0;
         node->mOff = 0;
         node->mParent = parentFolder;
      }
      return node;
   }
   FileNodePtr FileNode::createFolder()
   {
      FileNodePtr node = make_shared<FileNode>(_SharedPtrOnly_FNode());
      node->mName = "/";
      node->mIsFolder = true;
      node->mSize = 0;
      node->mOff = 0;   

      return node;   
   }

   FileNodePtr FileNode::create(string &jsonData)
   {
      uint64_t nodeCnt = 0;
      tuple<FileNodePtr, Json::Value> current;
      queue<tuple<FileNodePtr, Json::Value>> next;

      FileNodePtr root = get<0>(current) = FileNode::createFolder();

      Json::Reader r;
      r.parse(jsonData, get<1>(current));

      next.push(current); //prime loop

      while(!next.empty())
      {
         current = next.front();
         next.pop();
//TODO: add char check for names
         //load stats
         if(!get<0>(current)->isRoot())
         {
            get<0>(current)->mName = get<1>(current)["name"].asString();
         }
//TODO: complete BFS tree population
break;

         //populate files

         //add child folders to queue
      }

      return root;
   }

   void FileNode::remove(FileNodePtr node)
   {

   }
   bool FileNode::moveTo(FileNodePtr newParent)
   {

   }
   bool FileNode::containsLocal(string &name)
   {
      for(FileNodePtr &node : mFiles)
      {
         if(node->mName == name) { return true; }
      }
      for(FileNodePtr &node : mFolders)
      {
         if(node->mName == name) { return true; }
      }
      return false;
   }
   bool FileNode::contains(FileNodePtr &node)
   {
      FileNodePtr check = node;

      while(check != nullptr)
      {
         if(check.get() != this)
         {
            check = check->mParent.expired() ? nullptr : check->mParent.lock();
         }
      }
      return false;
   }

   string FileNode::toString()
   {
      return "";
   }
   string FileNode::toJson()
   {
      return "";
   }

   Json::Value FileNode::getJSonNode()
   {
      Json::Value v;
      return v;
   }
}

