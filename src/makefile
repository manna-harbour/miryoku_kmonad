# Copyright 2021 Manna Harbour
# https://github.com/manna-harbour/miryoku

source := $(wildcard *.kbd.cpp)

targets := $(source:%.kbd.cpp=build/%.kbd)

all: $(targets)

build/%.kbd: %.kbd.cpp FORCE
	cpp -P $(OPT_DEFS) $< | \
	sed \
	  -e "s/U_QUOT/'/g" \
	  -e 's/U_DQUO/"/g' \
	  -e 's/U_COMM/,/g' \
	  -e 's/U_LPRN/\\(/g' \
	  -e 's/U_RPRN/\\)/g' \
	  -e 's/U_PIPE/|/g' \
	  -e 's/[ ]*U_LF[ ]*/\n/g' \
	  -e 's/[ ]*U_TAB[ ]*/\t/g' \
	 > $@

FORCE: ;

test: build/miryoku_kmonad.kbd
	kmonad -d $<

include custom_rules.mk

include post_rules.mk
