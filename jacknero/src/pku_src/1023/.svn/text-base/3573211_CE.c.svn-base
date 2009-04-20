char*p,*q;
_int64 N,w[9];
main(k,v)
{
  for(gets(v);~scanf("%d%s%I64d",&k,v,&N);puts(N?"Impossible":strrev(w)))
    for(q=w,p=v+k;*q=*--p;*q+++=48)*q=N%2&1,N=N+(*p&2?*q:-*q)>>1;
}