char t['~~~'];
unsigned j,k,n;

main(i){
  for(gets();~scanf("%u",&n);printf("%c\n",t[n>k?n-k-1:i-1]))
    for(i=j=k=0;n>k+j;)k+=j+=sprintf(t+j,"%d",++i);
}