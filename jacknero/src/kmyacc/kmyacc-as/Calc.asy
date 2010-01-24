%{
package {
    import flash.display.*; 
	public class Calc extends MovieClip {
	  public function Calc() {
	    var cp:CalcParser = new CalcParser();
	  	cp.inputString = "2 + 3 * 4\n" + "5 * 6 + 7 * 8\n";
	  	CalcParser.yydebug = true;
	  	CalcParser.yyDumpParseTree = true;
	  	cp.yyparse();
	  }
	}
}
%}


%token NUMBER

%left '+' '-'
%left '*' '/'

%%

start:	lines;

lines: /* empty */
	| lines line { yylrec++; }
        ;

line	: expr '\n' { trace("result = " + $1); }
	| '\n' { trace("(empty line ignored)"); }
	| error '\n'
	;

expr	: expr '+' expr { $$ = $1 + $3; }
	| expr '-' expr { $$ = $1 - $3; }
	| expr '*' expr { $$ = $1 * $3; }
	| expr '/' expr { $$ = $1 / $3; }
	| '(' expr ')' { $$ = $2; }
	| NUMBER { $$ = $1; }
	;

%%

/* Lexical analyzer */

private var ch:String = null;
public var inputString:String;
private var inputPos:int=0;

private function getch():String {
  var c:String = ch;
  if (c != null) {
    ch = null;
    return c;
  }
  if(inputPos >= inputString.length) {
    return null;
  }
  return inputString.charAt(inputPos++);
}

private function ungetch(c:String):void { ch = c; }

private function isDigit(s:String):Boolean {
  var c:Number = s.charCodeAt(0);
  return (c >= "0".charCodeAt(0) && c <= "9".charCodeAt(0));
}

private function yylex():int {
  yylval = null;
  for (;;) {
    var c:String = getch();
    if (c == null) {
      return 0;
    } else if (c == ' ' || c == '\t') {
      // skip
    } else if (isDigit(c)) {
      var n:int = 0;
      var buf:Array = [];
      while (c != null && isDigit(c)) {
        buf.push(c)
        c = getch();
      }
      ungetch(c);
      yylval = parseInt(buf.join());
      return NUMBER;
    } else {
      return c.charCodeAt(0);
    }
  }
  throw "Doesn't come here";
}

private function yyerror(msg:String):void {
  trace(msg);
}
