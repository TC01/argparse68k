# Makefile for building the program.
# Assumes tprbuilder is on $PATH.

all:
	@tprbuilder argparse68k.tpr
	@tprbuilder example.tpr
