/*
 * =====================================================================================
 *
 *       Filename:  CIntArray.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2008ǯ07��31�� 19��57ʬ39��
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH S���dwestfalen, Iserlohn
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

