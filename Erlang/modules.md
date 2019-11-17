Modeuls
=======

![](https://learnyousomeerlang.com/static/img/modules.png)

#### What are modules

-	All Functions in Erlang must be defined in modules.
-	BIF(Built-In Fucntions), hd and tl beong to the erlang module.
	-	BIFs from the erlang module differ from other functions as they are automatically imported when you use Erlang.
-	Every other function : Module:Function(Arguments).

#### Module Declaration

-	module(Name).
	-	This is the name you'll use to call functions from other modules.
-	export([Function1/Artiy, ...]).
	-	-export([add/2]).
	-	Specifies which of the functions defined within the module that are visible ouside the module.
-	define(MACRO, some_value).
	-	?MACRO inside any function defined in the module.
-	import(Module,Functions).
-	compile(Options).
	-	c(Module).
	-	complie:file(Module, [debug_info, export_all]).
-	vsn(Vsn).

-	useless module\`\`` Erlang -module(useless). -export([add/2, hello/0, greet_and_add_two/1]).

add(A,B) -> A+B.

hello() -> io:format("Hello world!~n").

greet_and_add_two(X) -> hello(), add(X,2).

===========================================

erl Erlang/OTP 22 [erts-10.5.3] [source] [64-bit] [smp:2:2] [ds:2:2:10] [async-threads:1] [hipe]

Eshell V10.5.3 (abort with ^G) 1> c(useless). {ok,useless} 2> m(useless). Module: useless MD5: 881c22704340ae2439c234d5dccc8fbe Compiled: No compile time info available Object file: /home/ezyeoky/Desktop/Erlang/useless.beam Compiler options: [] Exports: add/2 greet_and_add_two/1 hello/0 module_info/0 module_info/1 ok 4> useless:hello().  
Hello world! ok 10> useless:greet_and_add_two(4). Hello world! 6

\`\`\`
