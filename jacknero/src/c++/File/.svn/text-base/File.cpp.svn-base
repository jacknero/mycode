/*
 * =====================================================================================
 *
 *       Filename:  File.cpp
 *
 *    Description:  File
 *
 *        Version:  1.0
 *        Created:  2008年08月01日 13時37分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <string.h>
#include "MainDef.h"
#include "File.h"

CFile::CFile()
{
  m_pfile = NULL;
  m_bCopy = false;
}


CFile::CFile(const CFile& rother)
{
  m_pfile = rother.m_pfile;
  m_bCopy = true;
}

CFile::~CFile()
{
  if(m_bCopy == false)
    Close();
}

bool CFile::Open(const char* pszFile, const char* pszFlags)
{
  Close();

  char bufFlags[8];
  if(ModifyFlags(pszFlags, bufFlags, numof(bufFlags)) == false)
    return false;

  m_pfile = fopen(pszFile, bufFlags);
  return (m_pfile != NULL);
}

void CFile::Close()
{
  if(IsValid() == true)
  {
    fclose(m_pfile);
    m_pfile = 0;
  }
}


bool CFile::ModifyFlags(const char* pszSource, char* pszDest, int nSize)
{
  bool bBinary;

  bBinary = (strchar(pszSource, 'b') != NULL);

  if((int)strlen(pszSource) > nSize -1 -!bBinary)
    return false;

  strcpy(pszDest, pszSource);
  if(bBinary == false)
    strcat(pszDest, "b");
  return true;
}


size_t CFile::Read(void* pData, size_t nSize)
{
  if(IsValid() == false)
    return 0;
  return fread(pData, 1, nSize, m_pfile);
}

size_t CFile::Write(const void* pData, size_t nSize)
{
  if(IsValid() == false)
    return 0;
  return fwrite(pData, 1, nSize, m_pfile);
}

bool CFile::Eof()
{
  if(IsValid() == false)
    return true;
  return (feof(m_pfile) != 0);
}

