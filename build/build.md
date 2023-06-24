# Makefile tutorial

## Getting Started 

* Which part of the large project base needs to be recompiled.
* Refer to Hello project

## Basic Syntax

```sh
target: prerequisites
command
command
command
```
* Targets are filenames. 
* Prerequisites are also filenames. These need to exist before the commands need to run.

* Refer blah project.
[blah](./blah/Makefile)
* In this project we see that the prerequisites is missing. So once make is run, if we were to make changes to blah.c, make will not run the command. 

```make
blah: blah.c
	gcc blah.c -o blah
```

* Its attempting to do is to decide if the prerequisites of blah have changed since blah was compiled.

```make
blah: blah.o
	cc blah.o -o blah # runs third
blah.o: blah.c
	cc -c blah.c -o blah.o
blah.c:
	echo "int main(){return 0;}" > blah.c #runs first
```

## clean

```make
clean:
	rm -f filename
```
