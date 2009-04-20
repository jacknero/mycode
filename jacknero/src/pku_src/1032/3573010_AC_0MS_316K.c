i,m;
main(t){
  for(scanf("%d",&t);t-m>1;)t+=~++m;
  for(;i<m;)
    printf("%d ",t/m-~++i+(i+t%m>m));
}
