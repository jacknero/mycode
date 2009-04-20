-module(sample).
-export([hello_world/0]).

hello_world() -> io:fwrite("Hello, World!\n").

