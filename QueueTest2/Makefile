TARGET = QueueTest
EXT = exe
EXEC_FILE_NAME = $(TARGET).$(EXT)

SRC_QT_HEADER = QueueTest2.h
SRC_QT_CPP = QueueTest2.cpp
SRC_QM_CPP = QueueMain.cpp

QT_OBJ = QueueTest2.o
QM_OBJ = QueueMain.o

G_FLAG = -g
C_FLAG = -c
O_FLAG = -o

OBJECT = $(QT_OBJ) $(QM_OBJ)

CUR_DIR = ./
RUN = run
DEBG = debug
GDB = gdb
CL = clean

$(EXEC_FILE_NAME): $(OBJECT)
	$(CXX) $(G_FLAG) $(O_FLAG) $(EXEC_FILE_NAME) $^

$(QT_OBJ): $(SRC_QT_HEADER) $(SRC_QT_CPP)
	$(CXX) $(G_FLAG) $(C_FLAG) $^

$(QM_OBJ): $(SRC_QM_CPP)
	$(CXX) $(G_FLAG) $(C_FLAG) $^


$(RUN):
	$(CUR_DIR)$(EXEC_FILE_NAME)

$(DEBG):
	$(GDB) $(CUR_DIR)$(EXEC_FILE_NAME)

$(CL):
	$(RM) $(CUR_DIR)$(EXEC_FILE_NAME) $(CUR_DIR)$(QT_OBJ) $(CUR_DIR)$(QM_OBJ) 
