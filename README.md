```
#####&&&#GPP5555555PPB#&&&#####&#P5555G#&############################################&G5555PB##&#B55555B##
###&#B577?..........!?77P##&###&B7....?B&############################################&Y....!Y#&&#5....~P#&
##&BY....................!P####&B7....JB&############################################&Y....!Y#&&#5....~P#&
##BJ.....!YPB####BG5?......Y###&B7....JB&&&######&&&&##########&&&&#######&&&&#######&Y....!Y#&&#5....~P#&
#&5!....?B&&&&###&&&&P7....7B#&&B7....JBBP.......7JP##&######&&#G5?7......7J5B#&#####&Y....!Y#&&#5....~P#&
#&P7....!5B&&&&&&&&&&#BPGGGB###&B7....?7............7P#####&#BY!..............?P#&###&Y....!Y#&&#5....~P#&
###Y......!?JYY5PGB###&&&&&&###&B7......75G###B5!....7P&##&#P!...~?5B#&#BGY.....5#&##&Y....!Y#&&#5....~P#&
##&#57..............!7J5G#&&###&B7.....5#&&&##&&5!....Y&##&P!...!5#&&&&&&&&P.....P&##&Y....!Y#&&#5....~P#&
###&&#G5?7!..............7YB&##&B7....?B&#######P7....Y##&BJ....7GGGGGGGGGGG7....Y#&#&Y....!Y#&&#5....~P#&
#####&&&&&#BGPP55Y?7.......7B##&B7....JB&#######P7....J##&P7.....................Y#&#&Y....!Y#&&#5....~P#&
####&&&&&#&&&&&&&&###57.....J#&&B7....JB&#######P7....J##&P7....!JJJJJJJJJJJJJJJJP###&Y....!Y#&&#5....~P#&
##J....75&&&&#####&&&&5.....?#&&B7....JB&#######P7....J##&G?....?#&&&&&&&&&&&&&&&&###&Y....!Y#&&#5....~P#&
#&Y!....!YB##&&&&&##B5!.....Y#&&B7....JB&#######P7....J###&P.....J#&&&#&&&#PJ77??G&##&Y....!Y#&&#5....~P#&
###5!......!7JJJYJ?7~......J###&B7....JB&#######P7....J###&#5!....7YGB##BPJ~....YB&##&Y....!Y#&&#5....~P#&
##&#BY7..................JG#&##&B7....?B&#######P7....J####&#BJ!..............75#&###&Y....!Y#&&#5....~P#&
####&&#BPY?7........?J5GB&&####&BJ7..7YB&#######GJ!..!Y######&#BG5?7!....77J5G#&&####&57..!?5#&&#P7...7G#&
######&&&&&&&&&&&&&&&&&&&########&&&&&&##########&&&&&&########&&&&&&&&&&&&&&&&#######&&&&&&&####&&&&&&&##
```
# C - Simple Shell

Project by [Ignacio Rivero](https://github.com/rivero04) and [Anit Rodriguez](https://github.com/AnitRodriguez).

Our own UNIX command interpreter (simple version). This program was developed as part of the C - Simple Shell project for Holberton School

## General info
This shell is a command-line interpreter that provides a command line user interface for Unix-like operating systems. This shell was writted in C languaje and has the exact same output as sh (/bin/sh) as well as the exact same error output, but with limited functions.

## Compile it with:
For using this program, you ned to compile all the ```.c``` files with the following line of code:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
And then, run the program whit yhe following line of code for interactive mode (see [Usage](#usage)):
```bash
$ ./hsh
(꒡⌓꒡)
```
## Usage
This shell work like this in interactive mode:
```bash
$ ./hsh
(꒡⌓꒡) /bin/ls
hsh main.c shell.c
(꒡⌓꒡) exit
$
```
But also in non-interactive mode:
```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
```
## Files and description

| File | Description |
| --------- | ---------|
| ```shell.h``` | Header file that contains prototypes and libraries. |
| ```shell.c``` | Main function (command-line interpreter). |
| ```execute_command.c``` |  Execute a command. |
| ```free_tokens.c``` | Free memory allocated for an array of strings. |
| ```getcommand.c``` | Resolves the full path of a command. |
| ```getenv.c``` |  Retrieves the value of an environment variable. |
| ``` split_string.c``` | Splits a string into an array of tokens. |


## License
This program is open source and their development is in progress. Feel free to help us to improve it and make it better.
