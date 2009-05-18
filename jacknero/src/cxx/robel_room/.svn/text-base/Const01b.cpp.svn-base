/*
 * =====================================================================================
 *
 *       Filename:  Const01b.cpp
 *
 *    Description:  1_45
 *
 *        Version:  1.0
 *        Created:  2008年05月15日 14時07分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include <stdio.h>

int strcnt(const char* psz, int letter)
{
  int num;
  for(num = 0; *psz; psz++)
  {
    if(*psz == letter)
      num++;
  }
  return num;
}

int main()
{
  char szPath[] = "/etc/passwd";

  printf("ファイル%sは、%d重のフォルダの中には言っています。",
      szPath, strcnt(szPath, '/') -1);

  return 0;
}
