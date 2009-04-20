/*
 * =====================================================================================
 *
 *       Filename:  IntArray.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2008年07月31日 19時01分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include <iostream>
#include <memory>
//#include <process.h>
using namespace std;


#include "IntArray.h"

CIntArray::CIntArray(const int nNumOf)
{
  m_pnum = new int[nNumOf];
  if(m_pnum == NULL)
    m_nNumOf = 0;
  else
  {
    m_nNumOf = nNumOf;
    memset(m_pnum, 0, nNumOf * sizeof * m_pnum);
  }

  cout << "call constructor"
    << "nNumOf:" << m_nNumOf << endl;
}

CIntArray::~CIntArray()
{
  if(m_pnum != NULL)
    delete [] m_pnum;


  cout << "call deconstructor"
    << "nNumOf:" << m_nNumOf << endl;
}


int CIntArray::Get(const int index)
{
  CheckIndex(index);
  return m_pnum[index];
}

void CIntArray::Set(const int index, const int value)
{
  CheckIndex(index);
  m_pnum[index] = value;
}

void CIntArray::CheckIndex(const int index)
{
  if((unsigned int)index < (unsigned) m_nNumOf)
      return;

  cout << "error index" << endl
       << "value: " << index << endl;
       exit(1);
}
      
CIntArray::CIntArray(CIntArray& rother)
{
  if(rother.Success()==false)
  {
    m_pnum = NULL;
    m_nNumOf =0;
  }
  else
  {
    m_pnum = new int[rother.NumOf()];
    if(m_pnum == NULL)
    {
      m_nNumOf = 0;
      return;
    }


    memcpy(m_pnum, rother.m_pnum, rother.SizeOf());
    m_nNumOf = rother.m_nNumOf;
  }

  cout << "call copy constructor " << endl;
}


