Erlang : Functional Programming Language
========================================

![img](https://learnyousomeerlang.com/static/img/erlang.png)

[reference site](https://learnyousomeerlang.com/content)

-	Contents

	Skip list : Errors and Exceptions, After Hitchhiker's Important : Common Test for Uncommon Tets.

-	Install

	My Ubuntu version is 18.04 LTS**Step1 : Adding Repository**

	```
	wget https://packages.erlang-solutions.com/erlang-solutions_1.0_all.deb
	sudo dpkg -i erlang-solutions_1.0_all.deb
	```

	**Step2 : Install Erlong on Ubuntu**

	```
	sudo apt-get install erlong
	OR sudo apt-get install esl-erlang
	```

	**Step3 : Erlong Hello World Program**

	```Erlang
	  % hello world program
	  -module(hello).
	  -export([helloworld/0]).


	  helloworld() ->
	  io:format("Hello Wordl!\n").
	```

	```
	  erl
	  1> c(hello).
	  {ok,hello}
	  2> hello:helloworld().
	  Hello Wordl!
	  ok
	```
