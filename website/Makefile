TARGET=pythrandoc

SED=sed
ZIP=zip
CP=cp
LN_S=ln -s

PAGES=MANUAL CLI SUPPORT DEVGUIDE TUTORIAL INTERNAL LICENSE AUTHORS TODO Changelog

all:index.rst $(patsubst %, %.rst, $(PAGES)) pythran.png
	PYTHONPATH=..:$$PYTHONPATH sphinx-build . $(TARGET)

dist:all
	rm -f $(TARGET).zip
	cd $(TARGET) && $(ZIP) -r ../$(TARGET).zip *

index.rst:../README.rst Makefile
	$(SED) -r $< $(patsubst %, -e 's/(%)/:doc:`\1`/g', $(PAGES)) \
		   -e 's,http://pythonhosted.org/pythran/,.. toctree::\n\t:maxdepth: 1\n\n$(patsubst %, \t%\n, $(PAGES)),g' \
		   > $@

MANUAL.rst:../doc/MANUAL.rst
	$(LN_S) $<

CLI.rst:../doc/CLI.rst
	$(LN_S) $<

DEVGUIDE.rst:../doc/DEVGUIDE.rst
	$(LN_S) $<

TUTORIAL.rst:../doc/TUTORIAL.rst
	$(LN_S) $<

INTERNAL.rst:../doc/INTERNAL.rst
	$(LN_S) $<

LICENSE.rst:../LICENSE Makefile
	echo "=======\nLICENSE\n=======\n\n" > $@
	cat $< >> $@

AUTHORS.rst:../AUTHORS
	$(LN_S) $< $@

TODO.rst:../TODO
	$(LN_S) $< $@

SUPPORT.rst:support.py ../pythran/tables.py
	./$< > $@


Changelog.rst:../Changelog
	echo "=========\nChangelog\n=========\n\n" > $@
	cat $< >> $@

pythran.png:../logo.svg Makefile
	convert -density 1200 -resize x80 -background none $< $@
