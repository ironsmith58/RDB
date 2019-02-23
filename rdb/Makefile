# RBD Makefile - installation only

INSTALL_DIR = /usr/local/bin

PERL_SCRIPTS = \
	column compute dataent etbl headchg jointbl lst2tbl \
	mergetbl mktbl ptbl rdb rdbt repair reporttbl row search \
	sorttbl subtotal summ tbl2lst uniqtbl valid

tell:
	@echo "install	- install the perl scripts in $(INSTALL_DIR)"

install:
	cp $(PERL_SCRIPTS) $(INSTALL_DIR)
	cd $(INSTALL_DIR); chmod 775 $(PERL_SCRIPTS)
