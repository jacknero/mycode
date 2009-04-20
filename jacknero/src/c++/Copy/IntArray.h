/*
 * =====================================================================================
 *
 *       Filename:  IntArray.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2008年07月31日 18時56分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#ifndef __INTARRAY_H_INCLUDED__
#define __INTARRAY_H_INCLUDED__

class CIntArray
{
  private:      
    int* m_pnum;
    int  m_nNumOf;

 public:
    CIntArray(const int nNumOf);
    ~CIntArray();
    CIntArray(CIntArray& rother);

  public:
    int Get(const int index);
    void  Set(const int index, const int value);

    bool Success()
    {
      return m_pnum != NULL;
    }

    int NumOf()
    {
      return m_nNumOf;
    }

    int SizeOf()
    {
      return m_nNumOf * sizeof *m_pnum;
    }
    

    private:
    void CheckIndex(const int index);
};
#endif

