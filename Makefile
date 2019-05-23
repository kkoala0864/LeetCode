EXDIR := Remove_Duplicates_From_LinkList \
         ChaosLib \
	 include

SUBDIRS:=$(filter-out $(EXDIR), $(shell ls -d *_*))

.PHONY: all $(SUBDIRS) clean

all : $(SUBDIRS)

$(SUBDIRS) : 
	$(MAKE) -C $@

clean :
	for dir in $(SUBDIRS); do \
	        echo $$dir; \
		$(MAKE) clean -C $$dir; \
	done

