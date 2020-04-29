exe: y.tab.c lex.yy.c arvore.c semantics.c
	clang -g -o jucompiler y.tab.c lex.yy.c arvore.c semantics.c

y.tab.c: jucompiler.y
	yacc -d jucompiler.y

lex.yy.c: jucompiler.l
	lex jucompiler.l
