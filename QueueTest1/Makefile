TARGET = QueueTest1
EXEC_EXT = .exe
EXECUTE_FILE_NAME = $(TARGET)$(EXEC_EXT)
GDB = gdb
CPPFLAGS = -g
QT_FILE = QueueTest1.o
QT_MAIN = QueueMain.o
OBJECT = $(QT_FILE) $(QT_MAIN)

$(EXECUTE_FILE_NAME): $(OBJECT)
	$(CXX) $(CPPFLAGS) -o $(EXECUTE_FILE_NAME) $^

$(QT_FILE): $(TARGET).h $(TARGET).cpp
	$(CXX) $(CPPFLAGS) -c $^

$(QT_MAIN): $(QT_MAIN:.o=.cpp)
	$(CXX) $(CPPFLAGS) -c $^

run:
	./$(EXECUTE_FILE_NAME)

debug:
	$(GDB) ./$(EXECUTE_FILE_NAME)

clean:
	$(RM) ./$(EXECUTE_FILE_NAME) $(QT_FILE) $(QT_MAIN)
