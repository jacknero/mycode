char*p,*q;
s['~~'];
main(){
  for(;~scanf("%s%s",p=s,q=s+9);puts(*p?"No":"Yes"))
    for(;*q;)p+=*p==*q++;
}
