Erlang : Functional Programming Language
========================================

![img](https://learnyousomeerlang.com/static/img/erlang.png)

[reference site](https://learnyousomeerlang.com/content)

-	Contents

	Skip list : Errors and Exceptions, After Hitchhiker's Important : Common Test for Uncommon Tets.

-	Install My Ubuntu version is 18.04 LTS

	**Step1 : Adding Repository**

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

-	What is Functional Programming?

Declarative Languages : the Programmer specifies **What** is to be computed Imperative Languages : the Programmer specifies **How** this is to be computed

![](https://csdl-images.computer.org/mags/it/2011/05/figures/mit20110500301.gif)

![](https://i.imgur.com/fQUJjqf.png)

1.	Pure functions

	```
	  First, they always produce the same output for same arguemtns irrespective of anything else.
	  Secondly, they have no side effects i.e. they do modify any argument, global variables or ouput something. (Immutability)


	  Pure functions also make it easier to write parallel/concurrent applications.
	```

2.	Recursion

	```
	  No loop function.
	```

3.	Referential transparency

	```
	  The value of variable in a functional program never changes once defined. This eliminates any changes of side effects because nay variable can be replaced with its actual value at any point of execution. So, functional programs are referentially transparents.
	  Functional programs do not have assignment statements.


	  x = x + 1 // this changes the value assigned to the variable x.
	            // So the expression is not referentially transparent.
	```

4.	Functions are First-Class and can be Higher-Order

	```
	  First-Class functions and Higher-Order functions both allow functions as arguments and results of other functions.
	  Higher-order : A mathematical concept of functions that operate on other functions. It can create a new function using gotten arguments.
	  First-class : A computer science therm that describes programming language entities that have no restrction on their use.
	```

5.	Variables are Immutable

	```
	  A variable can't modify after it's been initialized.
	  This also makes it easier to write concurrent applications because it supports to Lock and Synchronize.
	```

6.	Lazy evalution

	```
	  Strict(eager) or non-strcit(lazy) evalution, concepts that refer to how function arguments are processed when as expression is being evaluated.
	  To avoids repeated evaluation because the value is evaluated and stored only when it is needed.
	```

#### **Reference Site** [LINE Engineering](https://engineering.linecorp.com/ko/blog/functional-programing-language-and-line-game-cloud/) [geeksforgeeks](https://www.geeksforgeeks.org/functional-programming-paradigm/)
