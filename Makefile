SHELL := /bin/sh
CXXFLAGS ?= -O2 -Wall -Wextra -pedantic
PDFLATEX ?= pdflatex
FULL_PY ?= .venv/bin/python
export SOURCE_DATE_EPOCH := 1795478400
export FORCE_SOURCE_DATE := 1
export TZ := UTC

.PHONY: verify verify-full paper

build/verifier: arith/kumar-dihedral-control.cpp
	@mkdir -p build
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -std=c++17 $< -o $@

verify: build/verifier
	@build/verifier > build/controls.txt
	@build/verifier --targets > build/targets.txt
	@diff -u evidence/controls.txt build/controls.txt
	@diff -u evidence/targets.txt build/targets.txt
	@echo 'MATCH order-76 controls, reflection control, and both target input checks'

# Opt-in reproduction of the independent review. Process one order at a time.
verify-full:
	@mkdir -p build
	@"$(FULL_PY)" -c 'import sys; assert sys.prefix != sys.base_prefix, "select an isolated environment"'
	@"$(FULL_PY)" evidence/build.py 320 g3 > build/full-5164.json
	@jq -es --argjson expected '[5164,232320,320,"g3",1289,[1292,1290]]' -f evidence/check-full.jq build/full-5164.json >/dev/null
	@echo 'MATCH 5164 full sign and Gram checks'
	@"$(FULL_PY)" evidence/build.py 520 g1 > build/full-8332.json
	@jq -es --argjson expected '[8332,523536,520,"g1",2081,[2084,2082]]' -f evidence/check-full.jq build/full-8332.json >/dev/null
	@echo 'MATCH 8332 full sign and Gram checks'

paper:
	@mkdir -p build/tex
	@$(PDFLATEX) -halt-on-error -interaction=batchmode -output-directory=build/tex paper/main.tex
	@$(PDFLATEX) -halt-on-error -interaction=batchmode -output-directory=build/tex paper/main.tex
	@! grep -E 'Overfull|undefined references|undefined citations|Warning:' build/tex/main.log
	@cp build/tex/main.pdf paper/main.pdf
