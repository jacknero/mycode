/*
 * =====================================================================================
 *
 *       Filename:  File.h
 *
 *    Description:  file
 *
 *        Version:  1.0
 *        Created:  2008年08月01日 13時30分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#ifdef __FILE_H__INCLUDED__
#define __FILE_H__INCLUDED__

#include <stdio.h>

class CFile
{
  private:
    FILE* m_pfile;
    bool m_bCopy;

  public:
    CFile();
    CFile(const CFile& rother);
    ~CFile();

  public:
    bool Open(const char* pszFile, const char* pszFlags);
    void Close();

  private:
    bool ModifyFlags(const char* pszSource, char* pszDest, int nSize);

  public:
    size_t Read(void* pData, size_t nSize);
    size_t Write(const void* pData, size_t nSize);

  public:
    bool lsValid() const;
    bool Eof();
};

intline bool CFile::IsValid() const
{
  return (m_pfile != NULL)
}

#endif
