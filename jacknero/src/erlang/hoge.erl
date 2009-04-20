-module(hoge).
-export([sum/1]).

sum(X) ->
if
  x==0 -> 0;
  x/=0 -> X + sum(X-1)
  end.

