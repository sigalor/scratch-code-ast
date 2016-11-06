#!/bin/bash

# all of the following regex's are used to convert from this:
#	void func(int abc) { commands; }
# to this:
#	void func(int abc)
#	{
#		commands;
#	}
# The mass_replace.py script is from http://stackoverflow.com/a/1597755

./mass_replace.py ../src/ "(?P<stuff>((?<={ ).{2,}(?= })))" "\n\t\t\1\n\t"
./mass_replace.py ../src/ " { (?=\n)" "\n\t{"
./mass_replace.py ../src/ "(?<=\t) }" "}"
./mass_replace.py ../src/ "\t}\n\t(?=[a-zA-Z])" "\t}\n\t\n\t"
