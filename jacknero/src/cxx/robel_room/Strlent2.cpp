/*
 * =====================================================================================
 *
 *       Filename:  Strlent1.cpp
 *
 *    Description:  roble_heya 1_40
 *
 *        Version:  1.0
 *        Created:  2008年05月15日 13時45分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include <stdio.h>

int strlen(char* str)
{
  char* p;
  for(p = str; *p; p++);
  return p - str;
}

void DispLength(char* str)
{
  printf("文字列[%s]の長さは%dバイトです。\n", str, strlen(str));
}

int main()
{
  DispLength("褒め歩メール");
  DispLength("嘘つきゃ張れるぜドルバッキー");
  DispLength("");

  return 0;
}

