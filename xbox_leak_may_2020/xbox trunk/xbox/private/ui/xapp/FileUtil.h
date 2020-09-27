#pragma once

bool DoesFileExist(const TCHAR* szFileName);

void MakePath(TCHAR* szBuf, const TCHAR* szDir, const TCHAR* szFile);

int GetDirectoryBlocks(const TCHAR* szDirPath, int nBlockSize, bool bRecursive, HANDLE hCancelEvent);
int GetFileBlocks(const TCHAR* szFilePath, int nBlockSize);

void CleanFilePath(char* szPath, const TCHAR* szSrcPath);
#ifdef _UNICODE
void CleanFilePath(TCHAR* szPath, const TCHAR* szSrcPath);
#endif

void UpdateCurDirFromFile(const TCHAR* szURL);
void MakeAbsoluteURL2(TCHAR* szBuf, const TCHAR* szBase, const TCHAR* szURL);
void MakeAbsoluteURL(TCHAR* szBuf, const TCHAR* szBase, const TCHAR* szURL);
void MakeAbsoluteURL(TCHAR* szBuf, const TCHAR* szURL);

DWORD GetUniqueFile(const TCHAR* szBase, TCHAR* szPath/*=NULL*/);
DWORD CreateUniqueDir(const TCHAR* szBase);

bool DeleteDirectory(const TCHAR* szPath);
bool CopyDirectory(const TCHAR* szSrcPath, const TCHAR* szDestPath);

void FindFilePath(TCHAR* szFullPath/*[MAX_PATH]*/, const TCHAR* szFile);

int GetFileSize(const TCHAR* szFilePath);
