BUILD_CMD = gcc
MKDIR_CMD = mkdir
RM_CMD = rm -rf 
AR_CMD = ar
TMP_DIR = tmp/
BIN_OUTPUT = bin/
LIB_OUTPUT = bin/lib/
TEST_BIN_OUTPUT = bin/debug/

H_HOME = ./

BUILD_LIBRARIES = -lobject

OBJECT_TARGETS = "object.c"
TEST_OBJECT_ALLOCATE_TARGETS = "test/object_allocate/main.c"

temp:
	$(MKDIR_CMD) -p $(TMP_DIR)

object: temp
	$(MKDIR_CMD) -p $(BIN_OUTPUT)
	$(MKDIR_CMD) -p $(LIB_OUTPUT)
	$(BUILD_CMD) -c -fPIC -o tmp/object.o $(OBJECT_TARGETS)
	$(AR_CMD) rcs $(LIB_OUTPUT)libobject.a tmp/object.o 

test_object_allocate: object
	$(MKDIR_CMD) -p $(BIN_OUTPUT)
	$(MKDIR_CMD) -p $(TEST_BIN_OUTPUT)
	$(BUILD_CMD) -I$(H_HOME) -o $(TEST_BIN_OUTPUT)test_object_allocate $(TEST_OBJECT_ALLOCATE_TARGETS) -L$(LIB_OUTPUT) $(BUILD_LIBRARIES) 

cleanup:
	$(RM_CMD) tmp/

clean: cleanup
	$(RM_DIR) bin/

all_tests: test_object_allocate
