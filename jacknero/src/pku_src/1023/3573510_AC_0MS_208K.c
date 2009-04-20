char*p;
__int64 n,m;
main(x,v){
  for(gets(v);~scanf("%d%s%I64d",&x,p=v,&n);
      printf(m/2-~n/2>>x-1?"Impossible\n":"%0*s\n",x,_i64toa(n+m^m,v,2)))
    for(m=0;*p;)
      m=m*2|*p++/2&1;
}
