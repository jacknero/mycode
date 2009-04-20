char u[99][70]={"Ignored","http://www.acm.org/"},c;q;
main(p)
{
  for(;
    scanf("%s ",&c),c%9;
    puts(c%3?c%5?gets(u+q,q=++p):p<q?++p+u:u:u+--p)
  )p+=!p;
}