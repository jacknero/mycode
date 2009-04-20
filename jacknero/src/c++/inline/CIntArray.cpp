/*
 * =====================================================================================
 *
 *       Filename:  CIntArray.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2008年07月31日 19時57分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include <stddef.h>

class CIntArray
{
  private:
    int* m_pnum;
    int  m_nNumOf;

  public:
    bool Success();
    int NumOf();
    int SizeOf();

};

bool CIntArray::Success()
{
  return m_pnum != NULL;
}

int CIntArray::NumOf()
{
  return m_nNumOf;
}

int CIntArray::SizeOf()
{
  return m_nNumOf * sizeof * m_pnum;
}

