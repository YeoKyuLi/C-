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

Erlang doesn't care if you enter floating point numbers or integers. div : interger-to-interger division rem : modulo operator Base#value : A base expression

```erlang
  erl
  Erlang/OTP 22 [erts-10.5.3] [source] [64-bit] [smp:2:2] [ds:2:2:10] [async-threads:1] [hipe]

  Eshell V10.5.3  (abort with ^G)
  1> 2 + 15.
  17
  2> 49 * 100.
  4900
  3> 5 / 2.
  2.5
  4> 5 div 2.
  2
  5> 5 rem 2.
  1
  6> (50 * 100) - 4999.
  1
  7> 16#AE.
  174
```

#### Invariable Variables

-	A variable names must begin with a capital letter. Plus, Only underscore(\_\)
-	The **=** operator (not the variables) has the role of comparing values and complaining if they're different. If they're the same, it returns the value.
-	**The variables cna't be variable in functional programming.**

```erlang
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

#### Atoms : Why variables names can't begin with a lowercase character.

A lowercase charcter are literals, constants with their own name for value. An atom should be enclosed in single quotes (') if it does not begin with a lower-case letter or if it contains other characters than alphanumeric characters, underscore (\_) or @.

#### Boolean Algebra & Comparison operators

##### Boolean Algebra

-	and (andalso), or (orelse), xor, not
-	Erlang has no such things as boolean *true* and *false*.

	##### Comparison operators

| op  | Description              |
|-----|--------------------------|
| ==  | equal to                 |
| /=  | not equal to             |
| =\< | less than or equal to    |
| \<  | less than                |
| >=  | greater than or equal to |
| \>  | greater than             |
| =:= | exactly equal to         |
| =/= | exactly not equal to     |

```
number <  atom < reference < func < port < pid < tuple < list < bit string
```

#### Tuples

-	{ele1, ele2, eleN}
-	The \_ variable is always seen as unbound and acts as a wildcard for pattern matching.
-	If X =4, Y =5, {X,Y} = {4,5.} Then the comparison is succeeds.

###### Functions

```
is_tuple(), list_to_tuple(list), tuple_to_list(tuple), tuple_size(), size()
```

```erlang
 erl
Erlang/OTP 22 [erts-10.5.3] [source] [64-bit] [smp:2:2] [ds:2:2:10] [async-threads:1] [hipe]

Eshell V10.5.3  (abort with ^G)
1> p {jon, 23, {june,25}}.
* 1: syntax error before: '{'
1> p ={jon, 23, {june,25}}.
** exception error: no match of right hand side value {jon,23,{june,25}}
2> P ={jon, 23, {june,25}}.
{jon,23,{june,25}}
3> size(P).
3
5> is_tuple(P).
true

7> tuple_to_list(P).
[jon,23,{june,25}]
8> list_to_tuple(P).
** exception error: bad argument
     in function  list_to_tuple/1
        called as list_to_tuple({jon,23,{june,25}})
9> list_to_tuple([1,2,3]).
{1,2,3}

```

#### Lists - [ele1, ele2, eleN] - You can mix more than one type of data in it. - Erlang will print lists of numbers **as numbers** only when at least one of them could not also represent a letter. - There is no built-in string type in most other languages. `erlang
     10> [233].
     "é"
     11> [97, 98, 99].
     "abc"
` - Both ++ and -- are right-associative. : These operations will be done from right to left. `erlang
    12> [1,2,3] -- [1,2] -- [3].
    [3]
    13> [1,2,3] -- [1,2] -- [2].
    [2,3]
` - [H|T] head and tail - [Term1| [Term2 | [... | [TermN]]]].... : Lists can thus be defined recursively as a head preceding a tail, which is itself a head followed by more heads. - [1|[2]] is **improper list**, so will fail to be used with standard functions of Erlang(even length()). `Erlang
    16> hd([2 | [1 | []]]).
    2
    17> tl([2 | [1 | []]]).
    [1]
` ![](https://learnyousomeerlang.com/static/img/worm.png)

#### List Comprehensions ![](https://learnyousomeerlang.com/static/img/set-comprehension.png) - NewList = [Expression || Pattern <- List, Condition1, Condition2, ... ConditionN] - NewList = [Expression || GeneratorExp1, GeneratorExp2, ..., GeneratorExpN, Condition1, Condition2, ... ConditionM].

#### Bit syntax : binaray values

```
   Value
   Value:Size
   Value/TypeSpecifierList
   Value:Size/TypeSpecifierList
```

TypeSpecifierList represents one or more of the following: It's distinguish by '\-'. Default values are used for any omitted type specifiers.

```
Type: interger | float | binary | bytes | bitstring | bits | utf8 | utf16 | utf32
Signedness : singed | unsigned
    1. Default : unsigned
    2. It's matching for interger.
Endianness : big | littel | native
    1. Default : bit
    2. What is native : the endianness will be resolved at load time ti be either big-endian or little-endian, depending on what is native for the CPU.
Unit : unit:integers  
    1. The allowed range is 1..256.
    2. Default : 1 for integer, float and bitstring, and to 8 for binray., utf8, utf16 and utf32 types require no unit to be defined.
```

-	The standard binary operations: bsl(Bit Shift Left), bsr(Bit Shift Right), band, bor, bxor, bnot.

#### Binary Comprehensions

-	The only change in syntac from regular list comprehensions is the **<-** which became **<=** and using binaries (\<<>>) inteand of lists ([]).
-	Chnaing <- to <= let us use a binary steam as a generator. The complete binary comprehension basically changed binary data to integers inside tuples.`Erlang
	32> [ X || <<X>> <= <<1,2,3,4,5>>, X rem 2 == 0].   
	[2,4]
	33>   
	33> [ X || <<X>> <- <<1,2,3,4,5>>, X rem 2 == 0].   
	** exception error: bad generator <<1,2,3,4,5>>
	`
