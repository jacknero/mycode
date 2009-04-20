// returns 0:not_found, 1:candidate_empty_tree, 2以上:found
  f(n){
    int v, ans;
    if( scanf(" (%d",&v) )
      ans = f(n-v)+f(n-v)&~1;  // nonempty. returns 0 or 2
    else
      ans = !n;                // empty. returns 0 or 1
    scanf(" )");
    return ans;
  }
  main(){
    int n;
    while( scanf("%d",&n)>0 )
      puts( f(n)>1?"yes":"no" );
  }
