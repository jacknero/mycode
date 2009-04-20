char a[1<<24];v;
main(x,n)
{
  for(;~n;n=getchar()%48)
    x=n-45?n==10?!v?v=1e4:++a[x],0:x*10+(n>9?n*.314-3:n):x;
  for(;++n<1e7;)
    a[n]/2&&printf("%03d-%04d %d\n",n/v,n%v,x=a[n]<0?1e5:a[n]);
  x||puts("No duplicates.");
}