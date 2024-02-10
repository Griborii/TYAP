grammar Expr;

prog:  'fun' 'main' '(' ')' '{' NEWLINE (stmt NEWLINE)* '}';

NEWLINE : [\r\n]+;
SPACE : [ \t] -> skip;
stmt: 'print' '(' printexpr=expr ')'
    | 'if' '(' ifstatement=expr ')' '{' NEWLINE (stmt NEWLINE)* '}'
    | 'while' '(' whilestatement=expr ')' '{' NEWLINE (stmt NEWLINE)* '}'
    | (ident=IDENT | ident=IDENT '[' index=expr ']') '=' assignexpr=expr
    ;

expr: left=expr op=('*'|'/') right=expr
    | left=expr op=('+'|'-') right=expr
    | left=expr op=('>'|'<'|'=='|'<='|'>=') right=expr
    | '(' exp=expr ')'
    | str=STRING
    | bool=BOOL
    | val=INT
    | (ident=IDENT | ident=IDENT '[' index=expr ']')
    | list='['(expr ',')* expr ']'
    ;
BOOL : ('true'|'false');
STRING : '"' [a-zA-Z]* '"';
INT : [0-9]+ ;
IDENT : [a-zA-Z]+;