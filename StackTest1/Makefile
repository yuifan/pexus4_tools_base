TARGET = StackTest1
EXEC_EXT = exe
EXEC_FILE_NAME = $(TARGET).$(EXEC_EXT)

SRC_ST_HEADER = StackTest1.h
SRC_ST_CPP = StackTest1.cpp
SRC_SM_CPP = StackMain.cpp

ST_OBJ = StackTest1.o
SM_OBJ = StackMain.o

OBJECT = $(ST_OBJ) $(SM_OBJ)

GDB = gdb
CUR_DIR = ./
RUN = run
DEBG = debug
CL = clean

O_FLAG = -o
G_FLAG = -g
C_FLAG = -c


$(EXEC_FILE_NAME): $(OBJECT)
	$(CXX) $(G_FLAG) $(O_FLAG) $(EXEC_FILE_NAME) $^

$(ST_OBJ): $(SRC_ST_HEADER) $(SRC_ST_CPP)
	$(CXX) $(G_FLAG) $(C_FLAG) $^

$(SM_OBJ): $(SRC_SM_CPP)
	$(CXX) $(G_FLAG) $(C_FLAG) $^

$(RUN):
	$(CUR_DIR)$(EXEC_FILE_NAME)

$(DEBG):
	$(GDB) $(CUR_DIR)$(EXEC_FILE_NAME)

$(CL):
	$(RM) $(CUR_DIR)$(EXEC_FILE_NAME) $(CUR_DIR)$(ST_OBJ) $(CUR_DIR)$(SM_OBJ)
