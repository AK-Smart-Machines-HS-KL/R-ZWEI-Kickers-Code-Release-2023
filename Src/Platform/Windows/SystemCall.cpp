#include "Platform/BHAssert.h"
#include "Platform/File.h"
#include "Platform/SystemCall.h"

#include <Windows.h>

void SystemCall::getLoad(float& mem, float load[3])
{
  load[0] = load[1] = load[2] = -1.f; //Not implemented yet
  MEMORYSTATUS memStat;
  memStat.dwLength = sizeof(MEMORYSTATUS);
  GlobalMemoryStatus(&memStat);
  mem = float(memStat.dwMemoryLoad) / 100.f;
}

unsigned long long SystemCall::getFreeDiskSpace(const char* path)
{
  std::string fullPath = File::isAbsolute(path) ? path : std::string(File::getBHDir()) + "/Config/" + path;
  for(std::string::size_type i = 0; i < fullPath.size(); ++i)
    if(fullPath[i] == '/')
      fullPath[i] = '\\';

  // Free space can only be determined for a directory
  DWORD attr = GetFileAttributes(fullPath.c_str());
  if(attr == 0xffffffff || !(attr & FILE_ATTRIBUTE_DIRECTORY))
  {
    std::string::size_type p = fullPath.rfind('\\');
    if(p != std::string::npos)
      fullPath = fullPath.substr(0, p + 1);
    ASSERT(GetFileAttributes(fullPath.c_str()) & FILE_ATTRIBUTE_DIRECTORY);
  }

  // UNC only works for roots
  if(fullPath.size() > 2 && fullPath[0] == '\\' && fullPath[1] == '\\')
  {
    std::string::size_type p = fullPath.find('\\', 2);
    p = fullPath.find('\\', p + 1);
    fullPath = fullPath.substr(0, p);
  }

  // UNC requires a trailing backslash
  if(!fullPath.empty() && fullPath.back() != '\\')
    fullPath += '\\';

  ULARGE_INTEGER freeBytesAvailable;
  if(GetDiskFreeSpaceEx(fullPath.c_str(), &freeBytesAvailable, nullptr, nullptr))
    return freeBytesAvailable.QuadPart;
  else
    return 0;
}

bool SystemCall::usbIsMounted()
{
  return false;
}
