Starting out
============

#### Useful command for beginner

-	Go forward : Ctrl + A
-	Go backward : Ctrl + E
-	Autocomplte : Tap
	-	Help : Ctrl+G -> h`
		User switch command
		--> h
		c [nn]            - connect to job
		i [nn]            - interrupt job
		k [nn]            - kill job
		j                 - list all jobs
		s [shell]         - start local shell
		r [node [shell]]  - start remote shell
		q        - quit erlang
		? | h             - this message
		-->
		`
	-	Stop the currently running code and bring you back to a responsive shell : i -> c

#### Numbers

Erlang doesn't care if you enter floating point numbers or integers. div : interger-to-interger division rem : modulo operator Base#value : A base expression\`\`` Erlong erl Erlang/OTP 22 [erts-10.5.3] [source] [64-bit] [smp:2:2] [ds:2:2:10] [async-threads:1] [hipe]

Eshell V10.5.3 (abort with ^G) 1> 2 + 15. 17 2> 49 * 100. 4900 3> 5 / 2. 2.5 4> 5 div 2. 2 5> 5 rem 2. 1 6> (50 * 100) - 4999. 1 7> 16#AE. 174\`\`\`

#### Invariable Variables

```

```Erlang

erl
Erlang/OTP 22 [erts-10.5.3] [source] [64-bit] [smp:2:2] [ds:2:2:10] [async-threads:1] [hipe]

Eshell V10.5.3  (abort with ^G)
1> one.
one
2> One.
* 1: variable 'One' is unbound
3> One = 1.
1
4> Un = Uno = One = 1.
1
5> Two = One + One.
2
6> Two = 2.
2
7> Two = Two +1.
** exception error: no match of right hand side value 3
8> two = 2.
** exception error: no match of right hand side value 2
9> Two.
2
10> Two = 3.
** exception error: no match of right hand side value 3
11> 47 = 45 + 2.
47
12> 47 = 45 + 3.
** exception error: no match of right hand side value 48
13> _ = 14+3.
17
14> _.
* 1: variable '_' is unbound
15> _ = 14 + 3.
17
16> _.
* 1: variable '_' is unbound

```
