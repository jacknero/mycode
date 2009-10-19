TEST_FILES = bug-2026390

IPATH = -I./.. -I../../

ADDFLAGS = -ggdb -Wall

all: $(TEST_FILES)

hwut-info:
	bug-2026390 ::SCRIPTS::

.cpp:
	g++ $(ADDFLAGS) $(IPATH) $< -o $@

clean:
	rm -f $(TEST_FILES)
