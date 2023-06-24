BUILDDIR:=build
FILENAME:=eqn
pdf:
	mkdir -p $(BUILDDIR)
	pandoc $(FILENAME).md \
	--filter pandoc-citeproc \
	--from=markdown+tex_math_single_backslash+tex_math_dollars+raw_tex \
	--to=latex \
	--output=$(BUILDDIR)/$(FILENAME).pdf \
	--pdf-engine=xelatex
clean:
	rm -f $(BUILDDIR)/$(FILENAME).pdf
