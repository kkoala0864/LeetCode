SUBDIRS=$(shell ls -d *_*)

.PHONY: all $(SUBDIRS) clean

all : $(SUBDIRS)

$(SUBDIRS) : 
	$(MAKE) -C $@

clean :
	for dir in $(SUBDIRS); do \
		$(MAKE) clean -C $$dir; \
	done

